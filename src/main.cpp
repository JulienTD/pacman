#include <iostream>
#include <SDL2/SDL.h>
#include "utils/Utils.hpp"
#include "window/Window.hpp"
#include "entity/rectangle/Rectangle.hpp"
#include "entity/sprite/Sprite.hpp"
#include <SDL2/SDL_pixels.h>
#include "map/Map.hpp"

int main(int argc, char* argv[])
{
    try {
        Utils::initSDL();
    } catch(std::runtime_error exception) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[ERROR] > %s", exception.what());
        return EXIT_FAILURE;
    }

    Window *window = (new WindowBuilder())
                    ->setName(std::string("Pacman"))
                    ->setDimensions(31 * 32, 28 * 32)
                    ->setPosition(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED)
                    ->build();

    auto tiles = Map::readMapFromFile("./resources/map.txt", window);

    for (auto &tile : tiles) {
        window->addEntity(tile);
    }
    // window->addEntity(new Rectangle("foo", 100, 100, 100, 100, true, {0, 0, 255, 255}));
    // window->addEntity(new Rectangle("bar", 200, 200, 100, 100, false, {0, 0, 255, 255}));

    window->run();

    window->close();
    Utils::quitSDL();

    return EXIT_SUCCESS;
}
