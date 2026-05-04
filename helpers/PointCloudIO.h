#pragma once
#include "types/pointtypes.h"
#include "pointcloudhandler.h"
#include <QString>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

class PointCloudIO {
public:
    static PointCloudPtr loadFromFile(const QString& path, bool& hasColor);
    static PointCloudPtr loadFromPCD(const QString& path, bool& hasColor);
    static PointCloudPtr loadFromPLY(const QString& path, bool& hasColor);

    static void saveKeyframe(PointCloudHandler& h, const QString& directoryPath, int index);
    static void saveAsOnePCD(PointCloudHandler& h, const QString& directoryPath);
    static void saveAllKeyframes(PointCloudHandler& h, const QString& directoryPath, const QString& baseName);

    static void saveSessionData(PointCloudHandler& h, const QString& directoryPath, const QString& baseName);
    static void loadSessionData(PointCloudHandler& h, const QString& sessionFile, const QString& dir);
};
