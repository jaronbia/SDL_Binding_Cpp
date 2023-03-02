#pragma once
#include <SDL2/SDL_stdinc.h>
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include "Renderer.hpp"

namespace SDL2 {

class Surface {
    friend class Renderer;
    private:
        bool         m_optimize{false};
        SDL_Surface* m_surface{nullptr};

        bool isOptimizedImg() { return m_optimize; }
        void optimize();

    public:
        Surface() = default;
        Surface(SDL_Surface* surface) : m_surface( surface ) {}
        ~Surface() = default;

        void load(std::string path);
        //void blit(Surface* updatedSurface);
        void create(SDL_Window* window);
        void setColorKey(int flag, Uint32 key) { SDL_SetColorKey( m_surface, flag, key ); }
        Uint32 mapRgb(Uint8 r, Uint8 g, Uint8 b) { return SDL_MapRGB( m_surface->format, r, g, b ); }

        int width()  { return m_surface->w; }
        int height() { return m_surface->h; }
};

}