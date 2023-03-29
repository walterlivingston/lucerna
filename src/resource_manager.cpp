#include "lucerna/lucerna.h"

std::map<std::string, Tex2D> ResourceManager::textures;
std::map<std::string, Shader> ResourceManager::shaders;

Shader ResourceManager::loadShader(std::string filepath, std::string name){
    shaders[name] = loadShaderFromFile(filepath);
    return shaders[name];
}

Shader ResourceManager::getShader(std::string name){
    return shaders[name];
}

Tex2D ResourceManager::loadTexture(const char* file, bool alpha, std::string name){
    textures[name] = loadTextureFromFile(file, alpha);
    return textures[name];
}

Tex2D ResourceManager::getTexture(std::string name){
    return textures[name];
}

void ResourceManager::clear(){
    for (auto iter : shaders)
        glDeleteProgram(iter.second.ID);

    for (auto iter : textures)
        glDeleteTextures(1, &iter.second.ID);
}

Tex2D ResourceManager::loadTextureFromFile(const char *file, bool alpha){
    Tex2D texture;
    if (alpha){
        texture.setFormat(GL_RGBA);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
    int width, height, nrChannels;
    unsigned char* data = stbi_load(file, &width, &height, &nrChannels, 0);

    texture.Generate(width, height, data);

    stbi_image_free(data);
    return texture;
}

Shader ResourceManager::loadShaderFromFile(const std::string& filepath){
    std::ifstream stream(filepath);

    ShaderType type = ShaderType::NONE;
    std::stringstream ss[3];
    std::string line;
    while(getline(stream, line)){
        if(line.find("#shader") != std::string::npos){
            if(line.find("vertex") != std::string::npos){
                type = ShaderType::VERTEX;
            }else if(line.find("fragment") != std::string::npos){
                type = ShaderType::FRAGMENT;
            }else if(line.find("geometry") != std::string::npos){
                type = ShaderType::GEOMETRY;
            }
        }else{
            ss[(int)type] << line << '\n';
        }
    }

    // (TODO) Clean up shader.compile() code

    // const char* vSource = ss[(int)ShaderType::VERTEX].str().c_str();
    // const char* fSource = ss[(int)ShaderType::FRAGMENT].str().c_str();
    // const char* gSource = ss[(int)ShaderType::GEOMETRY].str().c_str();

    Shader shader;
    shader.compile(ss[(int)ShaderType::VERTEX].str().c_str(), ss[(int)ShaderType::FRAGMENT].str().c_str(), ss[(int)ShaderType::GEOMETRY].rdbuf()->in_avail() != 0 ? ss[(int)ShaderType::GEOMETRY].str().c_str() : nullptr);
    return shader;
}