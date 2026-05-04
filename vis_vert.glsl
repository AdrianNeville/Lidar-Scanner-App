#version 330 core
// Input vertex data, different for all executions of this shader.
layout (location = 0) in vec3 vertexPosition_modelspace;
layout (location = 1) in vec3 v_color;

uniform mat4 MVP;

out vec3 color;

void main(){

    color = v_color;
    gl_Position = MVP * vec4(vertexPosition_modelspace, 1);

}
