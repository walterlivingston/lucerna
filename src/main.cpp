#include "lucerna/lucerna.h"

int main(){
    Application app;
    
    ResourceManager::loadTexture("assets/textures/lamp.jpg", false, "lamp");

    app.run();
    return 0;
}