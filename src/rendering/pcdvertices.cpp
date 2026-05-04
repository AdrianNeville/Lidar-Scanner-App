// PCDVertices.cpp
#include "pcdvertices.h"
#include <QDebug>

PCDVertices::PCDVertices() {}

PCDVertices::~PCDVertices() {
    if (vertices) delete[] vertices;
}

bool PCDVertices::loadFromFile(const QString& filename) {
    parsePCD(filename);
    return vertexCount > 0;
}

GLfloat* PCDVertices::getVertices() {
    return vertices;
}

int PCDVertices::getVertexCount() const {
    return vertexCount;
}

void PCDVertices::parsePCD(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open file:" << filename;
        return;
    }

    QTextStream in(&file);
    bool headerDone = false;
    std::vector<QVector3D> points;

    while (!in.atEnd()) {
        QString line = in.readLine();
        if (!headerDone) {
            if (line.trimmed().toUpper() == "DATA ASCII") {
                headerDone = true;
            }
            continue;
        }

        QStringList parts = line.split(" ", Qt::SkipEmptyParts);
        if (parts.size() >= 3) {
            float x = parts[0].toFloat();
            float y = parts[1].toFloat();
            float z = parts[2].toFloat();
            points.emplace_back(x, y, z);
        }
    }

    if (vertices) delete[] vertices;
    vertexCount = points.size();
    vertices = new GLfloat[vertexCount * 3];

    for (int i = 0; i < vertexCount; ++i) {
        vertices[i * 3 + 0] = points[i].x();
        vertices[i * 3 + 1] = points[i].y();
        vertices[i * 3 + 2] = points[i].z();
    }
}
