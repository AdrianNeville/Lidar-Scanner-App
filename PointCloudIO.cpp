#include "helpers/PointCloudIO.h"
#include <QFileInfo>
#include <QDebug>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/conversions.h>

PointCloudPtr PointCloudIO::loadFromFile(const QString& path, bool& hasColor) {
    QFileInfo fileInfo(path);
    QString ext = fileInfo.suffix().toLower();

    if (ext == "pcd") {
        return PointCloudIO::loadFromPCD(path, hasColor);
    } else if (ext == "ply") {
        return PointCloudIO::loadFromPLY(path, hasColor);
    }

    qWarning() << "[ERROR] Unsupported file format:" << ext;
    return nullptr;
}

PointCloudPtr PointCloudIO::loadFromPCD(const QString& path, bool& hasColor) {
    pcl::PCLPointCloud2 cloud_blob;
    if (pcl::io::loadPCDFile(path.toStdString(), cloud_blob) == -1) {
        qWarning() << "[ERROR] Failed to load PCD:" << path;
        return nullptr;
    }

    hasColor = (pcl::getFieldIndex(cloud_blob, "rgb") != -1 ||
                pcl::getFieldIndex(cloud_blob, "rgba") != -1);

    PointCloudPtr cloud(new pcl::PointCloud<PointT>);
    if (hasColor) {
        pcl::fromPCLPointCloud2(cloud_blob, *cloud);
    } else {
        pcl::PointCloud<pcl::PointXYZ> plain;
        pcl::fromPCLPointCloud2(cloud_blob, plain);
        for (const auto& pt : plain.points) {
            PointT rgbPt;
            rgbPt.x = pt.x;
            rgbPt.y = pt.y;
            rgbPt.z = pt.z;
            rgbPt.r = 255; // Default color
            rgbPt.g = 255;
            rgbPt.b = 255;
            cloud->points.push_back(rgbPt);
        }
    }

    cloud->width = static_cast<uint32_t>(cloud->points.size());
    cloud->height = 1;
    cloud->is_dense = false;

    return cloud;
}

PointCloudPtr PointCloudIO::loadFromPLY(const QString& path, bool& hasColor) {
    hasColor = true; // Assume PLY can store RGB
    PointCloudPtr cloud(new pcl::PointCloud<PointT>);
    if (pcl::io::loadPLYFile<PointT>(path.toStdString(), *cloud) == -1) {
        qWarning() << "[ERROR] Failed to load PLY:" << path;
        return nullptr;
    }
    return cloud;
}

void PointCloudIO::saveKeyframe(PointCloudHandler& h, const QString& filename, int i){

    if (pcl::io::savePCDFileBinary(filename.toStdString(), *h.keyframes[i].cloud) == -1) {
        qWarning() << "Failed to save keyframe";
    } else {
        qDebug() << "Saved keyframe to" << filename;
    }
}


void PointCloudIO::saveAsOnePCD(PointCloudHandler& h, const QString& directoryPath){
    if (h.keyframes.empty()) {
        qWarning() << "No keyframes to save";
        return;
    }

    PointCloudPtr combined(new pcl::PointCloud<PointT>);

    for (const auto& kf : h.keyframes) {
        qDebug() << "Saving";
        if (!kf.cloud->empty()) {
            *combined += *kf.cloud;
        }
    }

    if (combined->empty()) {
        qWarning() << "Combined cloud is empty. Nothing to save.";
        return;
    }

    if (pcl::io::savePCDFileBinary(directoryPath.toStdString(), *combined) == -1) {
        qWarning() << "Failed to save combined keyframes.";
    } else {
        qDebug() << "Saved combined keyframes to" << directoryPath;
    }
}

void PointCloudIO::saveAllKeyframes(PointCloudHandler& h, const QString& baseName, const QString& directoryPath){

    QDir outDir(directoryPath);
    if (!outDir.exists()) outDir.mkpath(".");

    for (size_t i = 0; i < h.keyframes.size(); ++i) {
        QString filename = outDir.filePath(QString("%1_%2.pcd").arg(baseName).arg(i));
        if (pcl::io::savePCDFileBinary(filename.toStdString(), *h.keyframes[i].cloud) == -1) {
            qWarning() << "Failed to save keyframe" << i;
        } else {
            qDebug() << "Saved keyframe to" << filename;
        }
    }
}

void PointCloudIO::saveSessionData(PointCloudHandler& h, const QString& baseName, const QString& directoryPath){
    QDir outDir(directoryPath);
    if (!outDir.exists()) outDir.mkpath(".");

    QJsonArray keyframesArray;

    for (size_t i = 0; i < h.keyframes.size(); ++i) {
        QString filename = outDir.filePath(QString("%1_%2.pcd").arg(baseName).arg(i));
        if (pcl::io::savePCDFileBinary(filename.toStdString(), *h.keyframes[i].originalCloud) == -1) {
            qWarning() << "Failed to save keyframe" << i;
        } else {
            qDebug() << "Saved keyframe to" << filename;
        }

        // --- Collect metadata for this keyframe ---
        QJsonObject kfObj;
        kfObj["file"] = QString("%1_%2.pcd").arg(baseName).arg(i);

        QJsonObject pos;
        pos["x"] = h.keyframes[i].pos.x;
        pos["y"] = h.keyframes[i].pos.y;
        pos["z"] = h.keyframes[i].pos.z;
        pos["roll"]  = h.keyframes[i].pos.roll;
        pos["pitch"] = h.keyframes[i].pos.pitch;
        pos["yaw"]   = h.keyframes[i].pos.yaw;
        kfObj["pos"] = pos;

        keyframesArray.append(kfObj);
    }

    // --- Write metadata file ---
    QJsonObject root;
    root["baseName"] = baseName;
    root["keyframes"] = keyframesArray;

    QJsonDocument doc(root);
    QString metaFile = outDir.filePath(QString("%1.session.json").arg(baseName));

    QFile file(metaFile);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();
        qDebug() << "Saved session metadata to" << metaFile;
    } else {
        qWarning() << "Failed to write session metadata file" << metaFile;
    }
}

void PointCloudIO::loadSessionData(PointCloudHandler& h, const QString& sessionFile, const QString& dir){
    QFile file(sessionFile);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Failed to open session file:" << sessionFile;
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isObject()) {
        qWarning() << "Invalid session JSON:" << sessionFile;
        return;
    }

    QJsonObject root = doc.object();
    QJsonArray kfArray = root["keyframes"].toArray();

    QFileInfo info(sessionFile);
    QString directory = info.absolutePath();

    for (int i = 0; i < kfArray.size(); ++i) {
        QJsonObject kfObj = kfArray[i].toObject();

        // Pose
        Position pos;
        QJsonObject poseObj = kfObj["pos"].toObject();
        pos.x     = poseObj["x"].toDouble();
        pos.y     = poseObj["y"].toDouble();
        pos.z     = poseObj["z"].toDouble();
        pos.roll  = poseObj["roll"].toDouble();
        pos.pitch = poseObj["pitch"].toDouble();
        pos.yaw   = poseObj["yaw"].toDouble();

        // Cloud file
        QString cloudFile = QDir(directory).filePath(kfObj["file"].toString());

        bool hasColor = false;
        PointCloudPtr cloud = PointCloudIO::loadFromPCD(cloudFile, hasColor);

        if (!cloud || cloud->empty()) {
            qWarning() << "Failed to load or empty cloud:" << cloudFile;
            continue;
        }

        h.startNewKeyframe(i);

        // Store keyframe
        Keyframe kf;
        kf.originalCloud = std::make_shared<pcl::PointCloud<PointT>>(*cloud);
        kf.cloud = std::make_shared<pcl::PointCloud<PointT>>(*cloud);
        kf.pos = pos;

        h.keyframes[i] = kf;
        h.setPosData(i);
    }

    // After all keyframes are in, rebuild VBOs / visualization
    h.loadPointsfromSession(kfArray.size());
}
