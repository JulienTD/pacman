#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <string>
#include <SDL2/SDL.h>

class Window;

class Entity {
    public:
        Entity(std::string id);
        ~Entity();

        std::string getId();
        void update(Window *window);
        void setUpdateFunction(void (*updateFunction)(Entity *entity, Window *window));
        void onEvent(Window *window, SDL_Event *event);
        void setOnEventFunction(void (*updateFunction)(Entity *entity, Window *window, SDL_Event *event));
        int getX();
        int getY();
        void setX(int x);
        void setY(int y);

        virtual void render(Window *window) = 0;

    protected:
        std::string _id;
        int _x;
        int _y;

    private:
        void (*_updateFunction)(Entity *entity, Window *window);
        void (*_onEventFunction)(Entity *entity, Window *window, SDL_Event *event);
};

#endif /* !ENTITY_HPP_ */
