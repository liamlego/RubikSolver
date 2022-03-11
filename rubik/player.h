#ifndef RUBIKP_H
#define RUBIKP_H

#include "cube.h"
#include "SFML/Graphics.hpp"


class RubikPlayer {

public:

    RubikPlayer();
    ~RubikPlayer();

    void display(sf::RenderWindow&);
    void play();

private:

    Cube cube;

};
#endif