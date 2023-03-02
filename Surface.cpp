#include "Surface.hpp"
#include "Window.hpp"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_surface.h>
#include <stdexcept>

namespace SDL2 {

//--------------------------------------------------------------------------------------------------------------
void Surface::
create(SDL_Window* window) {
    m_surface = SDL_GetWindowSurface( window );
    SDL_FillRect( m_surface, nullptr, SDL_MapRGB( m_surface->format, 0xFF, 0xFF, 0xFF ) );
}

//--------------------------------------------------------------------------------------------------------------
void Surface::
load(std::string path) {
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == nullptr ) throw std::logic_error("SDL could not load surface");
    m_surface = loadedSurface;
    if( isOptimizedImg() ) optimize();
}

//--------------------------------------------------------------------------------------------------------------
void Surface::
optimize() {
    SDL_Surface* optimizedSurface = SDL_ConvertSurface( m_surface, m_surface->format, 0 );
    if( optimizedSurface == nullptr ) throw std::logic_error("SDL could not optimize the surface");
    m_surface = optimizedSurface;
}

//--------------------------------------------------------------------------------------------------------------
// void Surface::
// blit(Surface* updatedSurface, int x, int y, int w, int h) {
//     SDL_Rect stretchRect;
//     stretchRect.x = x;
//     stretchRect.y = y;
//     stretchRect.w = w;
//     stretchRect.h = h;
//     SDL_BlitScaled( updatedSurface->m_surface, NULL, m_surface, &stretchRect );
// }

}