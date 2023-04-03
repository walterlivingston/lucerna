#include "lucerna/lucerna.h"

int width = 1080;
int height = 720;

SpriteRenderer* renderer;
Mesh* mesh;
Quad* rect;
Triangle* tri;

void render(){
    // mesh->draw(ResourceManager::getTexture("mario"), 
    //     glm::vec2(width/2, height/2), 
    //     glm::vec2(ResourceManager::getTexture("mario").width, ResourceManager::getTexture("mario").height));
    rect->draw();
}

void loadResources(){
    // Textures
    ResourceManager::loadTexture("assets/textures/Mario.png", true, "mario");
    // Shaders
    ResourceManager::loadShader("shaders/default.glsl", "default");
    ResourceManager::loadShader("shaders/sprite.glsl", "sprite");
}

int main(){
    Application app("Lucerna", width, height);
    
    ResourceManager::loadTexture("assets/textures/Mario.png", true, "mario");
    ResourceManager::loadShader("shaders/default.glsl", "default");
    ResourceManager::loadShader("shaders/sprite.glsl", "sprite");

    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(width), 
        static_cast<float>(height), 0.0f, -1.0f, 1.0f);
    ResourceManager::getShader("default").use().setInteger("image", 0);
    ResourceManager::getShader("default").setMat4f("projection", projection);

    rect = new Quad();
    rect->setPos(glm::vec3(width/2, height/2, 0.0f));
    rect->setScale(glm::vec3(100,100,1.0f));
    // rect->update();
    // renderer = new SpriteRenderer(ResourceManager::getShader("sprite"));
    // mesh = new Mesh(rect);

    app.setRenderCallback(render);
    app.run();
    return 0;
}