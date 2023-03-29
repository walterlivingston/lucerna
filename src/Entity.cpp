#include "Entity.h"

Entity::Entity(){
    m_rect = nullptr;
}

Entity::Entity(std::string filepath, SDL_Renderer* renderer){
    m_rect = new TexturedRect(filepath, renderer);
    m_renderer = renderer;
}

Entity::~Entity(){

}

void Entity::update(){

}

void Entity::render(){
    if(nullptr != m_rect)
        m_rect->draw();
}