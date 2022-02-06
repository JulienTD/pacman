#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <SDL2/SDL.h>

class Event {
    public:
        Event();
        ~Event();

        
    protected:
    private:
        SDL_Event events;
};

#endif /* !EVENT_HPP_ */
