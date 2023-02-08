#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor; // the color variable has attribute position 1

uniform mat4 projection;
uniform mat4 view;

out vec3 ourColor; // output a color to the fragment shader
void main(){
   gl_Position = projection * view * vec4(aPos, 1.0);
   ourColor = aColor;
}