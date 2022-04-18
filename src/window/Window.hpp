#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <string>
#include <stdexcept>
#include <iostream>
#include <chrono>
#include <vector>
#include "entity/Entity.hpp"

class Window {
    public:
        ~Window();
        Window(std::string name, int x, int y, int height, int width, int flags);
        SDL_Window *getSDLWindow();
        SDL_Renderer *getRenderer();
        void addEntity(Entity *entity);
        void run();
        void close();
    protected:
    private:
        std::chrono::high_resolution_clock::time_point _timeRender;
        SDL_Window *_window;
        SDL_Renderer *_renderer;

        std::vector<Entity*> _entities;
        bool _closed;
};

class WindowBuilder {
    public:
        WindowBuilder();
        ~WindowBuilder();

        WindowBuilder *setName(std::string name);
        WindowBuilder *setPosition(int x, int y);
        WindowBuilder *setDimensions(int height, int width);
        /**
         * @brief Set the Flags object
         *         The flags for the window, a mask of any of the following:
         *         ::SDL_WINDOW_FULLSCREEN, ::SDL_WINDOW_OPENGL, ::SDL_WINDOW_HIDDEN, ::SDL_WINDOW_BORDERLESS,
         *         ::SDL_WINDOW_RESIZABLE, ::SDL_WINDOW_MAXIMIZED, ::SDL_WINDOW_MINIMIZED, ::SDL_WINDOW_INPUT_GRABBED,
         *         ::SDL_WINDOW_ALLOW_HIGHDPI, ::SDL_WINDOW_VULKAN.
         * @param flags Mask of the flags
         * @return WindowBuilder same instance of window builder
         */
        WindowBuilder *setFlags(Uint32 flags);
        Window *build();

    protected:
    private:
        std::string _name;
        int _x;
        int _y;
        int _height;
        int _width;
        Uint32 _flags;
};

#endif /* !WINDOW_HPP_ */
