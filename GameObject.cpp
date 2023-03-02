#include "GameObject.hpp"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <cstddef>
#include <iostream>

namespace SDL2 {

void GameObject::
initialize(int index, Uint32 flags) {
    // Initialize SDL
    int init = SDL_Init( SDL_INIT_VIDEO );
    if(init < 0) throw std::logic_error("SDL could not be initialized"); 

    // Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
        throw std::logic_error("SDL_image could not initialize! SDL_image Error");

    // Initial TFT
    int tftInit = TTF_Init();
    if( tftInit == -1 ) 
        throw std::logic_error("SDL_ttf could not initialize! SDL_ttf Error");

    m_renderer->create( m_window, index, flags );
}

void GameObject::
run() {
    SDL_Event event;

    while( m_gameObjState.isRunning() ) {
        poll( event );
        gameLogic();
    }
}

void GameObject::
quit() {
    delete m_window;
    delete m_renderer;
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void GameObject::
poll(SDL_Event& event) {
    while( SDL_PollEvent( &event ) ) {
        handleEvent( event );
    }
}

void GameObject::
handleEvent(SDL_Event& event) {
    if( event.type == SDL_QUIT ) m_gameObjState.quit();
    else gameEvent( event );
}

}
