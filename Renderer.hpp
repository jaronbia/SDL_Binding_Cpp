#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <string>
#include "Window.hpp"
#include "Texture.hpp"

namespace SDL2 {

class Surface;

class Renderer {
    private:
        SDL_Renderer* m_renderer{nullptr};

        SDL_Rect getRectParams(Texture* txt, int x, int y, SDL_Rect* src) const;

    public:
        Renderer() = default;
        ~Renderer() { SDL_DestroyRenderer( m_renderer ); }

        void create(Window* window, int index, Uint32 flags) { 
            m_renderer = SDL_CreateRenderer( window->getWindow(), index, flags ); 
        }

        void setLogicalSize(int w, int h) {
            SDL_RenderSetLogicalSize( m_renderer, w, h );
        }

        void render(Texture* txt, int x, int y, SDL_Rect* src = nullptr);
        void render(Texture* txt, int x, int y, SDL_Rect* src, double angle, SDL_Point* center, SDL_RendererFlip flip);

        void present() { SDL_RenderPresent( m_renderer ); }
        void clear()   { SDL_RenderClear( m_renderer ); }

        void setViewPoint(SDL_Rect& vp) {
            SDL_RenderSetViewport( m_renderer, &vp ); 
        }

        void copy(Texture* txt, const SDL_Rect* src, SDL_Rect* dst) { 
            SDL_RenderCopy( m_renderer, txt->getTexture(), src, dst ); 
        }

        void copy(Texture* txt, const SDL_Rect* src, SDL_Rect* dst, double angle, SDL_Point* center, SDL_RendererFlip flip) { 
            SDL_RenderCopyEx( m_renderer, txt->getTexture(), src, dst, angle, center, flip ); 
        }

        void fill(SDL_Rect& rect) {
            SDL_RenderFillRect( m_renderer, &rect );
        }

        void drawLine(int x1, int y1, int x2, int y2) {
            SDL_RenderDrawLine( m_renderer, x1, y1, x2, y2 );
        }
        
        void drawRect(SDL_Rect& rect) {
            SDL_RenderDrawRect( m_renderer, &rect );
        }

        void drawPoint(int x, int y) {
            SDL_RenderDrawPoint( m_renderer, x, y );
        }

        void setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) { 
            SDL_SetRenderDrawColor( m_renderer, r, g, b, a ); 
        }

        Texture* createTexture(Uint32 format, int access, int h, int w);
        Texture* createTexture(const std::string path);
        Texture* createTexture(Surface* surface);
        Texture* createTexture(TTF_Font* font, std::string text, SDL_Color color);
}; 

}