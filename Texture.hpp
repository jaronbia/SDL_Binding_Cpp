#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_stdinc.h>
#include <cstddef>
#include "Surface.hpp"

namespace SDL2 {

class Texture {
    private:
        int m_width;
        int m_height;
        SDL_Texture* m_texture{nullptr};

    public:
        Texture(SDL_Texture* t, int w = 0, int h = 0) : m_texture(t), m_width(w), m_height(h) {}
        ~Texture() { SDL_DestroyTexture( m_texture ); }

        int  width()  { return m_width; }
        int  height() { return m_height; }

        void query(Uint32* format, int* access, int* w, int* h) { SDL_QueryTexture( m_texture, format, access, w, h ); }

        void adjustColor(Uint8 red, Uint8 green, Uint8 blue) { SDL_SetTextureColorMod( m_texture, red, green, blue ); }
        void setBlendMode(SDL_BlendMode blending) { SDL_SetTextureBlendMode( m_texture, blending ); }
        void setAlpha(Uint8 alpha) { SDL_SetTextureAlphaMod( m_texture, alpha ); }
        
        SDL_Texture* getTexture() { return m_texture; }
};

}