#include "Window.hpp"
#include <SDL2/SDL.h>
#include <cstddef>
#include <iostream>
#include <map>
#include <utility>
#include "Renderer.hpp"

namespace SDL2 {

//--------------------------------------------------------------------------------------------------------------
void Window::
create() {
    setDimensions( 640, 480 );
    m_window = SDL_CreateWindow("Undefined", 
                                SDL_WINDOWPOS_UNDEFINED, 
                                SDL_WINDOWPOS_UNDEFINED, 
                                m_width, 
                                m_height, 
                                SDL_WINDOW_SHOWN);

    if( m_window == nullptr ) throw std::logic_error("Window could not be created"); 
}

//--------------------------------------------------------------------------------------------------------------
void Window::
create(const std::string title, int xpos, int ypos, int width, int height, int flags) {
    setDimensions( width, height );

    m_window = SDL_CreateWindow(title.c_str(), 
                                xpos, 
                                ypos, 
                                m_width, 
                                m_height, 
                                flags);

    if( m_window == nullptr ) throw std::logic_error("Window could not be created"); 
}

}