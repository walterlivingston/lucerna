#shader vertex
#version 330 core
layout (location = 0) in vec4 vertex; // <vec2 position, vec2 texCoords>

out vec2 texCoords;

uniform mat4 model;
uniform mat4 projection;

void main(){
    texCoords = vertex.zw;
    gl_Position = projection * model * vec4(vertex.xy, 0.0, 1.0);
}

#shader fragment
#version 330 core
in vec2 texCoords;
out vec4 fragColor;

uniform sampler2D image;
uniform vec3 spriteColor;

void main(){    
    fragColor = vec4(spriteColor, 1.0) * texture(image, texCoords);
} 
