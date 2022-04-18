#ifndef MAP_HPP_
#define MAP_HPP_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "entity/rectangle/Rectangle.hpp"
#include "entity/pacman/Pacman.hpp"

class Map {
    public:
        Map();
        ~Map();
        static std::vector<Entity *> readMapFromFile(std::string mapPath, Window *window);

    protected:
    private:
};

#endif /* !MAP_HPP_ */
