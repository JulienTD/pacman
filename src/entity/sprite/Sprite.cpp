#include "Sprite.hpp"

Sprite::Sprite(std::string id, std::string spritePath, Window *window, int x, int y, int width, int height):
Entity(id),
// _x(x),
// _y(y),
_width(width),
_height(height),
_stateNbr(0),
_maxStateNbr(0),
_xStateGap(0),
_yStateGap(0),
_spriteX(0),
_spriteY(0),
_spriteWidth(0),
_spriteHeight(0),
_xAnimation(false),
_yAnimation(false),
_currentTick(0),
_tickRate(20),
_tickStep(1)
{
    this->setX(x);
    this->setY(y);
    this->_image = IMG_Load(spritePath.c_str());
    this->_texture = SDL_CreateTextureFromSurface(window->getRenderer(), this->_image);
}

Sprite::~Sprite()
{
}

void Sprite::setMaxStateNbr(int stateNbr)
{
    if (stateNbr <= 0)
        stateNbr = 1;
    this->_maxStateNbr = stateNbr - 1;
}

void Sprite::setXStateGap(int xGap)
{
    this->_xStateGap = xGap;
}

void Sprite::setYStateGap(int yGap)
{
    this->_yStateGap = yGap;
}

void Sprite::setSpriteX(int spriteX)
{
    this->_spriteX = spriteX;
}

void Sprite::setSpriteY(int spriteY)
{
    this->_spriteY = spriteY;
}

void Sprite::setSpriteHeight(int spriteHeight)
{
    this->_spriteHeight = spriteHeight;
}

void Sprite::setSpriteWidth(int spriteWidth)
{
    this->_spriteWidth = spriteWidth;
}

void Sprite::setXAnimation(bool xAnimation)
{
    this->_xAnimation = xAnimation;
}

void Sprite::setYAnimation(bool yAnimation)
{
    this->_yAnimation = yAnimation;
}

void Sprite::setTickRate(int tickRate)
{
    this->_tickRate = tickRate;
}

void Sprite::render(Window *window) {

        if (this->_currentTick > this->_tickRate) {
            this->_stateNbr++;
            this->_currentTick = 0;
        }

        if (this->_stateNbr > this->_maxStateNbr)
            this->_stateNbr = 0;

        SDL_Rect srcrect = {
            this->_spriteX + this->_stateNbr * (this->_xStateGap + this->_spriteWidth) * this->_xAnimation,
            this->_spriteY + this->_stateNbr * (this->_yStateGap + this->_spriteHeight) * this->_yAnimation,
            this->_spriteWidth,
            this->_spriteHeight
        };

        SDL_Rect dstrect = { this->_x, this->_y, this->_width, this->_height };

        SDL_RenderCopy(window->getRenderer(), this->_texture, &srcrect, &dstrect);
        this->_currentTick++;
}
