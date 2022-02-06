#include "Entity.hpp"

Entity::Entity(std::string id):
_id(id),
_updateFunction(nullptr)
{
}

Entity::~Entity()
{
}

void Entity::update(Window *window)
{
    if (this->_updateFunction)
        this->_updateFunction(window);
}

void Entity::setUpdateFunction(void (*updateFunction)(Window *window))
{
    this->_updateFunction = updateFunction;
}

std::string Entity::getId()
{
    return this->_id;
}
