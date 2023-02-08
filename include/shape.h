#ifndef SHAPE_H
#define SHAPE_H

#include "mesh.h"

class Shape{
    protected:
        float c_x;
        float c_y;
        std::vector<Vertex> vertices;
        std::vector<GLuint> indices;
        glm::vec3 color = glm::vec3(1.0f, 0.5f, 0.2f);
        Mesh* mesh;
        GLenum drawType = GL_TRIANGLES;
        virtual void calcVertices() = 0;
    public:
        Shape();
        ~Shape();
        void setColor(float r, float g, float b);
        virtual void Draw(Shader& shader);
};

class Point : public Shape{
    private:
        void calcVertices();
    public:
        Point(float x, float y);
};

class Line : public Shape{
    private:
        float x1;
        float y1;
        float x2;
        float y2;
        float width;
        void calcVertices();
    public:
        Line(float x1, float y1, float x2, float y2, float width = 1.0f);
};

class Circle : public Shape{
    private:
        float radius;
        int detail;
        void calcVertices();
    public:
        Circle(float x, float y, float radius, int detail = 360);
};

class Triangle : public Shape{
    private:
        float width;
        float height;
        void calcVertices();
    public:
        Triangle(float x, float y, float width, float height);
};

class Rect : public Shape{
    private:
        float width;
        float height;
        void calcVertices();
    public:
        Rect(float x, float y, float width, float height);
};

#endif