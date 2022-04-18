#include "Entity.hpp"

Entity::Entity(std::string id):
_id(id),
_updateFunction(nullptr),
_onEventFunction(nullptr)
{
}

Entity::~Entity()
{
}

void Entity::update(Window *window)
{
    if (this->_updateFunction)
        this->_updateFunction(this, window);
}

void Entity::setUpdateFunction(void (*updateFunction)(Entity *entity, Window *window))
{
    this->_updateFunction = updateFunction;
}

void Entity::onEvent(Window *window, SDL_Event *event)
{
    if (this->_onEventFunction != nullptr)
        this->_onEventFunction(this, window, event);
}

void Entity::setOnEventFunction(void (*updateFunction)(Entity *entity, Window *window, SDL_Event *event))
{
    this->_onEventFunction = updateFunction;
}

std::string Entity::getId()
{
    return this->_id;
}

int Entity::getX()
{
    return this->_x;
}

int Entity::getY()
{
    return this->_y;
}

void Entity::setX(int x)
{
    this->_x = x;
}

void Entity::setY(int y)
{
    this->_y = y;
}
