#pragma once

#include <string>
#include <iostream>
#include "SDL.h"

class TexturedRect{
    private:
        SDL_Rect m_rect;
        SDL_Renderer* m_renderer;
        SDL_Texture* m_texture;
    public:
        TexturedRect(std::string filepath, SDL_Renderer* renderer);
        ~TexturedRect();

        void draw();
        void setProperties(int x, int y, int width, int height);
};