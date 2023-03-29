#pragma once

#include <SDL.h>
#include <string>
#include "TexturedRect.h"

class Entity{
    private:
        SDL_Renderer* m_renderer;
        TexturedRect* m_rect;
    public:
        Entity();
        Entity(std::string filepath, SDL_Renderer* renderer);
        ~Entity();

        void update();
        void render();

        inline TexturedRect* getRect() { return m_rect; };
};