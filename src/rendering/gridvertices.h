#ifndef GRIDVERTICES_H
#define GRIDVERTICES_H


#include <QtOpenGL/QOpenGLFunctions_3_3_Core>

class Gridvertices
{
public:
    Gridvertices(float spacing = 1, int s = 50);
    ~Gridvertices();
    int getVertexCount();
    GLfloat* getVertices();
private:
    GLfloat* vertices;
    int vertexCount;
    void generateVertices(float spacing, int s);
};

#endif // GRIDVERTICES_H
