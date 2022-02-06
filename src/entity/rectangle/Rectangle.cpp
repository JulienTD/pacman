#include "Rectangle.hpp"

Rectangle::Rectangle(std::string id, int x, int y, int height, int width, bool filled, SDL_Color color):
Entity(id),
_rect({x, y, width, height}),
_filled(filled),
_color(color)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::render(Window *window) {
    SDL_SetRenderDrawColor(window->getRenderer(), this->_color.r, this->_color.g, this->_color.b, this->_color.a);

    if (this->_filled)
        SDL_RenderFillRect(window->getRenderer(), &this->_rect);
    else
        SDL_RenderDrawRect(window->getRenderer(), &this->_rect);
}
