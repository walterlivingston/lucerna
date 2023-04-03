#shader vertex
#version 330 core
layout (location = 0) in vec3 vertex; // <vec2 position, vec2 texCoords>
layout (location = 1) in vec2 coords;

out vec2 texCoords;

uniform mat4 model;
uniform mat4 projection;

void main(){
    texCoords = coords;
    gl_Position = projection * model * vec4(vertex.xyz, 1.0);
}

#shader fragment
#version 330 core
in vec2 texCoords;
out vec4 fragColor;

uniform sampler2D image;
uniform vec3 spriteColor;

void main(){    
    fragColor = vec4(spriteColor, 1.0) * texture(image, texCoords);
    //fragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);
} 
