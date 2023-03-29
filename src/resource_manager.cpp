#include "lucerna/lucerna.h"

std::map<std::string, Tex2D> ResourceManager::textures;
// std::map<std::string, Shader>       ResourceManager::Shaders;


// Shader ResourceManager::LoadShader(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile, std::string name)
// {
//     Shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
//     return Shaders[name];
// }

// Shader ResourceManager::GetShader(std::string name)
// {
//     return Shaders[name];
// }

Tex2D ResourceManager::loadTexture(const char* file, bool alpha, std::string name)
{
    textures[name] = loadTextureFromFile(file, alpha);
    return textures[name];
}

Tex2D ResourceManager::getTexture(std::string name)
{
    return textures[name];
}

void ResourceManager::clear()
{
    // for (auto iter : Shaders)
    //     glDeleteProgram(iter.second.ID);
    // (properly) delete all textures
    for (auto iter : textures)
        glDeleteTextures(1, &iter.second.ID);
}

Tex2D ResourceManager::loadTextureFromFile(const char *file, bool alpha)
{
    // create texture object
    Tex2D texture;
    if (alpha)
        texture.setFormat(GL_RGBA);
    // load image
    int width, height, nrChannels;
    unsigned char* data = stbi_load(file, &width, &height, &nrChannels, 0);
    // now generate texture
    texture.Generate(width, height, data);
    // and finally free image data
    stbi_image_free(data);
    return texture;
}

// Shader ResourceManager::loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile)
// {
//     // 1. retrieve the vertex/fragment source code from filePath
//     std::string vertexCode;
//     std::string fragmentCode;
//     std::string geometryCode;
//     try
//     {
//         // open files
//         std::ifstream vertexShaderFile(vShaderFile);
//         std::ifstream fragmentShaderFile(fShaderFile);
//         std::stringstream vShaderStream, fShaderStream;
//         // read file's buffer contents into streams
//         vShaderStream << vertexShaderFile.rdbuf();
//         fShaderStream << fragmentShaderFile.rdbuf();
//         // close file handlers
//         vertexShaderFile.close();
//         fragmentShaderFile.close();
//         // convert stream into string
//         vertexCode = vShaderStream.str();
//         fragmentCode = fShaderStream.str();
//         // if geometry shader path is present, also load a geometry shader
//         if (gShaderFile != nullptr)
//         {
//             std::ifstream geometryShaderFile(gShaderFile);
//             std::stringstream gShaderStream;
//             gShaderStream << geometryShaderFile.rdbuf();
//             geometryShaderFile.close();
//             geometryCode = gShaderStream.str();
//         }
//     }
//     catch (std::exception e)
//     {
//         std::cout << "ERROR::SHADER: Failed to read shader files" << std::endl;
//     }
//     const char *vShaderCode = vertexCode.c_str();
//     const char *fShaderCode = fragmentCode.c_str();
//     const char *gShaderCode = geometryCode.c_str();
//     // 2. now create shader object from source code
//     Shader shader;
//     shader.Compile(vShaderCode, fShaderCode, gShaderFile != nullptr ? gShaderCode : nullptr);
//     return shader;
// }