#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_image.h>
#include "window/Window.hpp"
#include "entity/Entity.hpp"

class Sprite : public Entity {
    public:
        Sprite(std::string id, std::string spritePath, Window *window, int x, int y, int width, int height);
        ~Sprite();

        void setMaxStateNbr(int stateNbr);
        void setXStateGap(int xGap);
        void setYStateGap(int yGap);
        void setSpriteX(int spriteX);
        void setSpriteY(int spriteY);
        void setSpriteHeight(int spriteHeight);
        void setSpriteWidth(int spriteWidth);
        void setXAnimation(bool xAnimation);
        void setYAnimation(bool yAnimation);
        void render(Window *window);
    protected:
    private:
        SDL_Surface *_image;
        SDL_Texture *_texture;
        int _x;
        int _y;
        int _width;
        int _height;
        int _stateNbr;
        int _maxStateNbr;
        int _xStateGap;
        int _yStateGap;
        int _spriteX;
        int _spriteY;
        int _spriteWidth;
        int _spriteHeight;
        bool _xAnimation;
        bool _yAnimation;
};

#endif /* !SPRITE_HPP_ */
