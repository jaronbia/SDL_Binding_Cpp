#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_ttf.h>
#include <array>
#include <string>

namespace SDL2 {

class Window {
    private:
        int m_width;
        int m_height;
        SDL_Window*  m_window{nullptr};

    public:
        Window(int w = 0, int h = 0) : m_width(w), m_height(h) {}
        ~Window() = default;

        void create();
        void create(const std::string title, int xpos, int ypos, int width, int height, int flags);
        void close() { SDL_DestroyWindow( m_window ); }

        void setDimensions(int w, int h) {
            m_width = w;
            m_height = h;
        }

        SDL_Window* getWindow() { return m_window; }
};

}