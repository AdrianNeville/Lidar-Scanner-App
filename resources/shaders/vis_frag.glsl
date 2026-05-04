#version 330 core

in vec3 color;

void main()
{

  // Output color = red
  gl_FragColor = vec4(color,1);

}
