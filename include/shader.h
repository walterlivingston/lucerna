#ifndef SHADER_H
#define SHADER_H

class Shader{
    private:
        unsigned int ID; 
        void checkCompileErrors(unsigned int object, std::string type);
    public:
        Shader() { }
        Shader  &Use();
        void Compile(const char* vertexSource, const char* fragmentSource, const char* geometrySource);
};

#endif