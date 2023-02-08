#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "window.h"
#include "shape.h"

struct Particle{
    float x;
    float y;
    float radius;
    glm::vec2 velocity;

    Particle(float x, float y, float radius){
        this->x = x;
        this->y = y;
        this->radius = radius;
    }

    void update(){

    }

    void Draw(Shader& shader){
        Circle circle(x, y, radius);
        circle.Draw(shader);
    }
};

int main(){
	Window win("HELLO WORLD!", 1080, 720);

    win.Init();
    Line line(0.0f, 0.0f, 25.0f, 25.0f);
    //Triangle triangle(0.0f, 0.0f, 10.0f, 10.0f);
    //line.setColor(1.0f, 0.0f, 0.0f);

    while(!win.Closed()){
        win.Clear(0.07f, 0.13f, 0.17f);
        line.Draw(win.getShader());
        //triangle.Draw(win.getShader());
        win.Update();
    }
}