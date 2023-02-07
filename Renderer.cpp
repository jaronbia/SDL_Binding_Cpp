#include "Renderer.hpp"
#include <stdexcept>
#include "Surface.hpp"
#include "Texture.hpp"

//--------------------------------------------------------------------------------------------------------------
void Renderer::
render(Texture* txt, int x, int y, SDL_Rect* src) {
    SDL_Rect renderQuad = getRectParams( txt, x, y, src );
    copy( txt, src, &renderQuad );
}

//--------------------------------------------------------------------------------------------------------------
void Renderer::
render(Texture* txt, int x, int y, SDL_Rect* src, double angle, SDL_Point* center, SDL_RendererFlip flip) {
    SDL_Rect renderQuad = getRectParams( txt, x, y, src );
    copy( txt, src, &renderQuad, angle, center, flip );
}

//--------------------------------------------------------------------------------------------------------------
Texture* Renderer::
createTexture(Uint32 format, int access, int h, int w) {
    SDL_Texture* sdlTexture = SDL_CreateTexture( m_renderer, format, access, h, w );
    if(sdlTexture == nullptr) throw std::logic_error("SDL could not create texture"); 
    return new Texture( sdlTexture );
}

//--------------------------------------------------------------------------------------------------------------
Texture* Renderer::
createTexture(const std::string path) {
    SDL_Texture* sdlTexture = IMG_LoadTexture( m_renderer, path.c_str() );
    if( sdlTexture == nullptr ) throw std::logic_error("SDL could not create texture with path provided");
    return new Texture( sdlTexture );
}

//--------------------------------------------------------------------------------------------------------------
Texture* Renderer::
createTexture(Surface* surface) {
    SDL_Texture* sdlTexture;
    
    sdlTexture = SDL_CreateTextureFromSurface( m_renderer, surface->m_surface );
    if(sdlTexture == nullptr) throw std::logic_error("SDL could not create texture from surface"); 
    delete surface;

    return new Texture( sdlTexture, surface->width(), surface->height() );
}

//--------------------------------------------------------------------------------------------------------------
Texture* Renderer::
createTexture(TTF_Font* font, std::string text, SDL_Color color) {
    SDL_Surface* textSurface = TTF_RenderText_Solid( font, text.c_str(), color );
    Surface* surface = new Surface( textSurface );

	if( textSurface == nullptr )
		throw std::logic_error( "Unable to render text surface! SDL_ttf Error" );

    Texture* texture = createTexture( surface );

    return texture;
}

//--------------------------------------------------------------------------------------------------------------
SDL_Rect Renderer::
getRectParams(Texture* txt, int x, int y, SDL_Rect* src) const {
    SDL_Rect renderQuad = { x, y, txt->width(), txt->height() };

    if( src != nullptr ) {
        renderQuad.w = src->w;  
        renderQuad.h = src->h;
    }

    return renderQuad;
}