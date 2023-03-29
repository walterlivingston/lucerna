#include "lucerna/lucerna.h"

int main(){
    Application app;
    
    ResourceManager::loadTexture("assets/textures/lamp.jpg", false, "lamp");
    ResourceManager::loadShader("shaders/default.glsl", "default");

    app.run();
    return 0;
}