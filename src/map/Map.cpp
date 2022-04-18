/*
** EPITECH PROJECT, 2022
** pacman
** File description:
** Map
*/

#include "Map.hpp"

Map::Map()
{
}

Map::~Map()
{
}

std::vector<Entity *> Map::readMapFromFile(std::string mapPath, Window *window)
{
    auto map = std::vector<Entity *>();
    std::ifstream infile(mapPath);

    std::string line;
    int y = 0;

    while (std::getline(infile, line)) {
        for (std::string::size_type i = 0; i < line.size(); i++) {
            if (line[i] == 'X') {
                auto rect = new Rectangle("", i * 32, y * 32, 32, 32, false, {0, 0, 255, 255});
                map.push_back(rect);
            }
            if (line[i] == 'P') {
                map.push_back(new Pacman(window, i * 32, y * 32));
            }
        }
        y++;
        std::cout << line << std::endl;
    }
    return map;
}
