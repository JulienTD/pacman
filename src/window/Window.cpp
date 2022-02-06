#include "Window.hpp"

Window::Window(std::string name, int x, int y, int height, int width, int flags):
_window(SDL_CreateWindow(name.c_str(), x, y, width, height, flags)),
_renderer(nullptr),
_closed(false)
{
    if (!this->_window) {
        throw std::runtime_error(SDL_GetError());
    }
    this->_renderer = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED);
    if (!this->_renderer) {
        throw std::runtime_error(SDL_GetError());
    }
}

Window::~Window()
{

}

void Window::run() {
    SDL_Event events;

    while (!this->_closed)
    {
        while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
                case SDL_QUIT:
                    this->_closed = true;
                    break;
            }
        }

        SDL_SetRenderDrawColor(this->_renderer, 0, 0, 0, 0);
        SDL_RenderClear(this->_renderer);
        for (Entity *entity : this->_entities) {
            entity->render(this);
        }
        SDL_RenderPresent(this->_renderer);
    }

}

SDL_Window *Window::getSDLWindow()
{
    return this->_window;
}

SDL_Renderer *Window::getRenderer()
{
    return this->_renderer;
}

void Window::addEntity(Entity *entity)
{
    this->_entities.push_back(entity);
}

void Window::close() {
    if (this->_renderer)
        SDL_DestroyRenderer(this->_renderer);
    if (this->_window)
        SDL_DestroyWindow(this->_window);
}

WindowBuilder::WindowBuilder():
_name(std::string("")),
_x(0),
_y(0),
_height(0),
_width(0),
_flags(0)
{
}

WindowBuilder::~WindowBuilder()
{
}

WindowBuilder *WindowBuilder::setName(std::string name)
{
    this->_name = name;
    return this;
}

WindowBuilder *WindowBuilder::setPosition(int x, int y)
{
    this->_x = x;
    this->_y = y;
    return this;
}

WindowBuilder *WindowBuilder::setDimensions(int height, int width)
{
    this->_height = height;
    this->_width = width;
    return this;
}

WindowBuilder *WindowBuilder::setFlags(Uint32 flags)
{
    this->_flags = flags;
    return this;
}

Window *WindowBuilder::build()
{
    return new Window(this->_name, this->_x, this->_y, this->_height, this->_width, this->_flags);
}
