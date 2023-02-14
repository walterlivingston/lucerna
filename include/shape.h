#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape{
    protected:
        float m_x;
        float m_y;
        float* m_vertices;
        std::string m_shader;
        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;

        virtual void calcVertices() = 0;
    public:
        Shape(float c_x, float c_y, std::string shader = "default");
        ~Shape();
        void Draw(GLenum drawType = GL_TRIANGLES) const;
};

class Circle : Shape{
    private:
        float m_radius;

        void calcVertices();
    public:
        Circle(float c_x, float c_y, float radius, std::string shader = "default");
        ~Circle();
        // void Draw(GLenum drawType = GL_TRIANGLES);
};

class Triangle : public Shape{
    private:
        float m_width;
        float m_height;

        void calcVertices();
    public:
        Triangle(float c_x, float c_y, float width, float height, std::string shader = "default");
        ~Triangle();
        // void Draw(GLenum drawType = GL_TRIANGLES);
};

class Quad : Shape{
    private:
        float m_width;
        float m_height;

        void calcVertices();
    public:
        Quad(float c_x, float c_y, float width, float height, std::string shader = "default");
        ~Quad();
        // void Draw(GLenum drawType = GL_TRIANGLES);
};

#endif