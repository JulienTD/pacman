#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_pixels.h>
#include "window/Window.hpp"
#include "entity/Entity.hpp"

class Rectangle : public Entity {
    public:
        Rectangle(std::string id, int x, int y, int height, int width, bool filled, SDL_Color color);
        ~Rectangle();

        void render(Window *window);

    protected:
    private:
        SDL_Rect _rect;
        bool _filled;
        SDL_Color _color;
};

#endif /* !RECTANGLE_HPP_ */
