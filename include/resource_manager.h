#pragma once

#include <map>
#include <string>

#include <glad/glad.h>

#include "texture.h"
#include "shader.h"

class ResourceManager{
    public:
        static Shader loadShader(std::string filepath, std::string name);
        static Shader getShader(std::string name);

        static Tex2D loadTexture(const char *file, bool alpha, std::string name);
        static Tex2D getTexture(std::string name);

        static void clear();
    private:
        static std::map<std::string, Shader> shaders;
        static std::map<std::string, Tex2D> textures;

        ResourceManager() { }
        static Shader loadShaderFromFile(const std::string& filepath);
        static Tex2D loadTextureFromFile(const char *file, bool alpha);
};
