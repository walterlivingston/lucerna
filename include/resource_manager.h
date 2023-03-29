#pragma once

#include <map>
#include <string>

#include <glad/glad.h>

#include "texture.h"

class ResourceManager{
    public:
        // static Shader    LoadShader(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile, std::string name);
        // static Shader    GetShader(std::string name);

        static Tex2D loadTexture(const char *file, bool alpha, std::string name);
        static Tex2D getTexture(std::string name);

        static void clear();
    private:
        // static std::map<std::string, Shader>    Shaders;
        static std::map<std::string, Tex2D> textures;

        ResourceManager() { }
        // static Shader    loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile = nullptr);
        static Tex2D loadTextureFromFile(const char *file, bool alpha);
};
