// PCDVertices.h
#ifndef PCDVERTICES_H
#define PCDVERTICES_H

#include <QFile>
#include <QTextStream>
#include <QVector3D>
#include <QString>
#include <QOpenGLFunctions>
#include <QOpenGLFunctions_3_3_Core>
#include <vector>

class PCDVertices {
public:
    PCDVertices();
    ~PCDVertices();

    bool loadFromFile(const QString& filename);
    GLfloat* getVertices();
    int getVertexCount() const;

private:
    void parsePCD(const QString& filename);
    GLfloat* vertices = nullptr;
    int vertexCount = 0;
};

#endif // PCDVERTICES_H
