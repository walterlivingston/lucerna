#include "lucerna/lucerna.h"

int width = 1080;
int height = 720;
SpriteRenderer* renderer;

int filterType = 0;

void render(){
    ImGui::InputInt("Filter Type", &filterType, 0);
    ResourceManager::getShader("filtering").use().setInteger("filterType", filterType);

    renderer->draw(ResourceManager::getTexture("flowers"), 
        glm::vec2(width/2, height/2), 
        glm::vec2(ResourceManager::getTexture("flowers").width, ResourceManager::getTexture("flowers").height));
}

int main(){
    Application app("Lucerna", width, height);
    
    ResourceManager::loadTexture("assets/textures/Mario.png", true, "mario");
    ResourceManager::loadTexture("assets/textures/lamp.jpg", false, "lamp");
    ResourceManager::loadTexture("assets/textures/flowers.jpeg", false, "flowers");

    ResourceManager::loadShader("shaders/sprite.glsl", "sprite");
    ResourceManager::loadShader("shaders/image_filtering.glsl", "filtering");

    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(width), 
        static_cast<float>(height), 0.0f, -1.0f, 1.0f);
    ResourceManager::getShader("filtering").use().setInteger("image", 0);
    ResourceManager::getShader("filtering").setMat4f("projection", projection);
    ResourceManager::getShader("filtering").setVec2f("resolution", {ResourceManager::getTexture("flowers").width, ResourceManager::getTexture("flowers").height});

    renderer = new SpriteRenderer(ResourceManager::getShader("filtering"));

    app.setRenderCallback(render);

    app.run();
    return 0;
}