#include "shape.h"

// ABSTRACT SHAPE CONSTRUCTOR AND FUNCTIONS
Shape::Shape(){}

Shape::~Shape(){
    this->mesh->VAO.Delete();
}

void Shape::Draw(Shader& shader){
    mesh->Draw(shader, drawType);
}

void Shape::setColor(float r, float g, float b){
    this->color = glm::vec3(r, g, b);
    calcVertices();
    this->mesh = new Mesh(this->vertices, this->indices);
}

//2D POINT PRIMITIVE CONSTRUCTOR AND FUNCTIONS
Point::Point(float x, float y){
    this->c_x = x;
    this->c_y = y;

    calcVertices();
    this->mesh = new Mesh(this->vertices, this->indices);
    this->drawType = GL_POINTS;
}

void Point::calcVertices(){
    Vertex v[] = {
        Vertex{glm::vec3(c_x, c_y, 0.0f), this->color}
    };
    vertices = std::vector<Vertex>(v, v + sizeof(v) / sizeof(Vertex));
}

//2D LINE PRIMITIVE CONSTRUCTOR AND FUNCTIONS
Line::Line(float x1, float y1, float x2, float y2, float width){
    this->c_x = x1 + x2 / 2;
    this->c_y = y1 + y2 / 2;
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->width = width;

    calcVertices();
    this->mesh = new Mesh(this->vertices, this->indices);
    this->drawType = GL_TRIANGLE_FAN;
}

void Line::calcVertices(){
    float angle = (y2 - y1)/(x2 - x1) * M_PI / 180;
    Vertex v[] = {
        Vertex{glm::vec3(x1 + width*sin(angle), y1 + width*cos(angle), 0.0f), this->color},
        Vertex{glm::vec3(x1 - width*sin(angle), y1 - width*cos(angle), 0.0f), this->color},
        Vertex{glm::vec3(x2 - width*sin(angle), y2 - width*cos(angle), 0.0f), this->color},
        Vertex{glm::vec3(x2 + width*sin(angle), y2 + width*cos(angle), 0.0f), this->color}
    };
    vertices = std::vector<Vertex>(v, v + sizeof(v) / sizeof(Vertex));
}

// 2D CIRCLE PRIMITIVE CONSTRUCTOR AND FUNCTIONS
Circle::Circle(float x, float y, float radius, int detail){
    this->c_x = x;
    this->c_y = y;
    this->radius = radius;
    this->detail = detail;

    calcVertices();
    this->mesh = new Mesh(this->vertices, this->indices);
    this->drawType = GL_TRIANGLE_FAN;
}

void Circle::calcVertices(){
    Vertex v[this->detail];
    for(int i = 0; i < detail; i++){
        float angle = (2 * M_PI * i) / detail;
        float x = cosf(angle) * radius;
        float y = sinf(angle) * radius;
        v[i] = Vertex{glm::vec3(c_x + x, c_y + y, 0.0f), color};
    }
    vertices = std::vector<Vertex>(v, v + sizeof(v) / sizeof(Vertex));
}

Triangle::Triangle(float x, float y, float width, float height){
    this->c_x = x;
    this->c_y = y;
    this->width = width;
    this->height = height;

    calcVertices();
    this->mesh = new Mesh(this->vertices, this->indices);
}

void Triangle::calcVertices(){
    Vertex v[] = {
        Vertex{glm::vec3(c_x - width / 2, c_y - height / 2, 0.0f), this->color},
        Vertex{glm::vec3(c_x + width / 2, c_y - height / 2, 0.0f), this->color},
        Vertex{glm::vec3(c_x, c_y + height / 2, 0.0f), this->color}
    };
    vertices = std::vector<Vertex>(v, v + sizeof(v) / sizeof(Vertex));
}

Rect::Rect(float x, float y, float width, float height){
    this->c_x = x;
    this->c_y = y;
    this->width = width;
    this->height = height;

    calcVertices();
    this->mesh = new Mesh(this->vertices, this->indices);
    this->drawType = GL_TRIANGLE_FAN;
}

void Rect::calcVertices(){
    Vertex v[] = {
        Vertex{glm::vec3(c_x - width / 2, c_y - height / 2, 0.0f), this->color},
        Vertex{glm::vec3(c_x + width / 2, c_y - height / 2, 0.0f), this->color},
        Vertex{glm::vec3(c_x + width / 2, c_y + height / 2, 0.0f), this->color},
        Vertex{glm::vec3(c_x - width / 2, c_y + height / 2, 0.0f), this->color}
    };
    vertices = std::vector<Vertex>(v, v + sizeof(v) / sizeof(Vertex));
}