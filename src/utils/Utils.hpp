#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <SDL2/SDL.h>
#include <stdexcept>
#include <random>

class Utils {
    public:
        Utils();
        ~Utils();

        static void initSDL(Uint32 flags = SDL_INIT_EVERYTHING);
        static void quitSDL();
        static void delay(Uint32 ms);
        static std::string generateUuid();

    protected:
    private:
};

#endif /* !UTILS_HPP_ */
