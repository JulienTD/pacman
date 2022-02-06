#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <string>

class Window;

class Entity {
    public:
        Entity(std::string id);
        ~Entity();

        std::string getId();
        void update(Window *window);
        void setUpdateFunction(void (*updateFunction)(Window *window));
        virtual void render(Window *window) = 0;

    protected:
        std::string _id;

    private:
        void (*_updateFunction)(Window *window);
};

#endif /* !ENTITY_HPP_ */
