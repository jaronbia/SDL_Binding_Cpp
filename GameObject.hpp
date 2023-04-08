#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include "Window.hpp"
#include "Renderer.hpp"

namespace SDL2 {

class GameObjectState {
    private:
        bool contin{true};
        
    public:
        bool isRunning() { return contin; }
        void quit()      { contin = false; }
};

class GameObject {
    private:
        GameObjectState m_gameObjState;
        Window*         m_window{nullptr};
        Renderer*       m_renderer{nullptr};

        virtual void poll(SDL_Event& event);
        virtual void handleEvent(SDL_Event& event);

    protected:
        virtual void gameLogic() = 0;
        virtual void gameEvent(SDL_Event& event) = 0;

        Window*   getWindow()   { return m_window; }
        Renderer* getRenderer() { return m_renderer; }

    public:
        GameObject() : m_window{ new Window() }, 
                       m_renderer{ new Renderer() } {}
        virtual ~GameObject() = default;
        
        void initialize(int index, Uint32 flags);
        virtual void run();
        void quit();
};

}