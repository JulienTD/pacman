#include "Utils.hpp"

Utils::Utils()
{
}

Utils::~Utils()
{
}

void Utils::initSDL(Uint32 flags) {
    if (SDL_Init(flags) != 0) {
        throw std::runtime_error(SDL_GetError());
    }
}

void Utils::quitSDL() {
    SDL_Quit();
}

void Utils::delay(Uint32 ms) {
    SDL_Delay(ms);
}
