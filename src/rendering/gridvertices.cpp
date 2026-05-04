#include "gridvertices.h"
#include <QtOpenGL/QOpenGLFunctions_3_3_Core>

Gridvertices::Gridvertices(float spacing, int s) {
    generateVertices(spacing, s);
}

Gridvertices::~Gridvertices(){
    free(vertices);
}

void Gridvertices::generateVertices(float spacing, int s){

    int lines = 4+(8*s);
    vertexCount = lines;

    vertices = (GLfloat*)malloc(lines*3*sizeof(GLfloat));

    vertices[0] = s;
    vertices[1] = 0;
    vertices[2] = 0;

    vertices[3] = -s;
    vertices[4] = 0;
    vertices[5] = 0;

    vertices[6] = 0;
    vertices[7] = 0;
    vertices[8] = s;

    vertices[9] = 0;
    vertices[10] = 0;
    vertices[11] = -s;

    int index = 12;

    for(int i = 1; i <= s; i++){
        vertices[index++] = s;
        vertices[index++] = 0;
        vertices[index++] = i*spacing;

        vertices[index++] = -s;
        vertices[index++] = 0;
        vertices[index++] = i*spacing;

        vertices[index++] = s;
        vertices[index++] = 0;
        vertices[index++] = -i*spacing;

        vertices[index++] = -s;
        vertices[index++] = 0;
        vertices[index++] = -i*spacing;

        vertices[index++] = i*spacing;
        vertices[index++] = 0;
        vertices[index++] = s;

        vertices[index++] = i*spacing;
        vertices[index++] = 0;
        vertices[index++] = -s;

        vertices[index++] = -i*spacing;
        vertices[index++] = 0;
        vertices[index++] = -s;

        vertices[index++] = -i*spacing;
        vertices[index++] = 0;
        vertices[index++] = s;

    }
}

GLfloat* Gridvertices::getVertices(){
    return vertices;
}

int Gridvertices::getVertexCount(){
    return vertexCount * 3;
}
