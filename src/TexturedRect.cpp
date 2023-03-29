#include "TexturedRect.h"

TexturedRect::TexturedRect(std::string filepath, SDL_Renderer* renderer) : m_renderer(renderer){
    SDL_Surface* surface = SDL_LoadBMP(filepath.c_str());
    if(!surface)
        std::cout << "FAILED" << std::endl;
    m_texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

TexturedRect::~TexturedRect(){
    SDL_DestroyTexture(m_texture);
}

void TexturedRect::draw(){
    SDL_RenderCopy(m_renderer, m_texture, NULL, &m_rect);
}

void TexturedRect::setProperties(int x, int y, int width, int height){
    m_rect.x = x;
    m_rect.y = y;
    m_rect.w = width;
    m_rect.h = height;
}