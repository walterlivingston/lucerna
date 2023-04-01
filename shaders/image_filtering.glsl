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

// Based on
//
// author : csblo
// Work made just by consulting :
// https://en.wikipedia.org/wiki/Kernel_(image_processing)
// Define kernels

#version 330 core

in vec2 texCoords;
out vec4 fragColor;

uniform sampler2D image;
uniform vec2 resolution;
uniform int filterType = 0;

#define identity mat3(0, 0, 0, 0, 1, 0, 0, 0, 0)                    //  0
#define edge0 mat3(1, 0, -1, 0, 0, 0, -1, 0, 1)                     //  1
#define edge1 mat3(0, 1, 0, 1, -4, 1, 0, 1, 0)                      //  2
#define edge2 mat3(-1, -1, -1, -1, 8, -1, -1, -1, -1)               //  3
#define sharpen mat3(0, -1, 0, -1, 5, -1, 0, -1, 0)                 //  4
#define box_blur mat3(1, 1, 1, 1, 1, 1, 1, 1, 1) * 0.1111           //  5
#define gaussian_blur mat3(1, 2, 1, 2, 4, 2, 1, 2, 1) * 0.0625      //  6
#define emboss mat3(-2, -1, 0, -1, 1, 1, 0, 1, 2)                   //  7

// Extract region of dimension 3x3 from sampler centered in uv
// sampler : texture sampler
// uv : current coordinates on sampler
// return : an array of mat3, each index corresponding with a color channel
mat3[3] region3x3(sampler2D sampler, vec2 uv){
    // Create each pixels for region
    vec4[9] region;
    
    int index = 0;
    for (int i = -1; i <= 1; i++){
        for (int j = -1; j <= 1; j++){
            region[index] = texture(sampler, uv + (vec2(i,j) / resolution.xy));
            index++;
        }
    }

    // Create 3x3 region with 3 color channels (red, green, blue)
    mat3[3] mRegion;
    
    for (int i = 0; i < 3; i++)
        mRegion[i] = mat3(
        	region[0][i], region[1][i], region[2][i],
        	region[3][i], region[4][i], region[5][i],
        	region[6][i], region[7][i], region[8][i]
    	);
    
    return mRegion;
}

// Convolve a texture with kernel
// kernel : kernel used for convolution
// sampler : texture sampler
// uv : current coordinates on sampler
vec3 convolution(mat3 kernel, sampler2D sampler, vec2 uv){
    vec3 fragment;
    
    // Extract a 3x3 region centered in uv
    mat3[3] region = region3x3(sampler, uv);
    
    // for each color channel of region
    for (int i = 0; i < 3; i++){
        // get region channel
        mat3 rc = region[i];
        // component wise multiplication of kernel by region channel
        mat3 c = matrixCompMult(kernel, rc);
        // add each component of matrix
        float r = c[0][0] + c[1][0] + c[2][0]
                + c[0][1] + c[1][1] + c[2][1]
                + c[0][2] + c[1][2] + c[2][2];
        
        // for fragment at channel i, set result
        fragment[i] = r;
    }
    
    return fragment;    
}

void main(){
    // Normalized pixel coordinates (from 0 to 1)
    vec2 uv = texCoords;
    vec3 col = convolution(identity, image, uv);

    switch(filterType){
        case 0:
            col = convolution(identity, image, uv);
            break;
        case 1:
            col = convolution(edge0, image, uv);
            break;
        case 2:
            col = convolution(edge1, image, uv);
            break;
        case 3:
            col = convolution(edge2, image, uv);
            break;
        case 4:
            col = convolution(sharpen, image, uv);
            break;
        case 5:
            col = convolution(box_blur, image, uv);
            break;
        case 6:
            col = convolution(gaussian_blur, image, uv);
            break;
        case 7:
            col = convolution(emboss, image, uv);
            break;
    }
    // Output to screen
    fragColor = vec4(col, 1.0);
}