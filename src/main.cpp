#include "lucerna/lucerna.h"

int width = 1080;
int height = 720;
SpriteRenderer* renderer;

void render(){
    renderer->draw(ResourceManager::getTexture("lamp"), 
        glm::vec2(200.0f, 200.0f), glm::vec2(300.0f, 400.0f), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
}

int main(){
    Application app("Lucerna", width, height);
    
    ResourceManager::loadTexture("assets/textures/lamp.jpg", false, "lamp");
    ResourceManager::loadShader("shaders/default.glsl", "default");

    ResourceManager::loadShader("shaders/sprite.glsl", "sprite");
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(width), 
        static_cast<float>(height), 0.0f, -1.0f, 1.0f);
    ResourceManager::getShader("sprite").use().setInteger("image", 0);
    ResourceManager::getShader("sprite").setMat4f("projection", projection);
    renderer = new SpriteRenderer(ResourceManager::getShader("sprite"));
    //ResourceManager::loadTexture("assets/textures/awesomeface.png", true, "face");

    app.setRenderCallback(render);

    app.run();
    return 0;
}