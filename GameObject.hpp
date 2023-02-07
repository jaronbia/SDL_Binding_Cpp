#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include "Window.hpp"
#include "Renderer.hpp"

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

        void poll(SDL_Event& event);
        void handleEvent(SDL_Event& event);

    protected:
        virtual void gameLogic() = 0;
        virtual void gameEvent(SDL_Event& event) = 0;

    public:
        GameObject() = default;
        ~GameObject() = default;
        
        void initialize(int index, Uint32 flags);
        void run();
        void quit();
};