#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include <map>
#include <string>

#include "shader.h"

class DisplayManager{
    private:
        static std::map<std::string, Shader> shaders;
        DisplayManager() { }
        static Shader loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile = nullptr);
    public:
        static Shader LoadShader(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile, std::string name);
        static Shader getShader(std::string name);
};

#endif