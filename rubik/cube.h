#include <vector>
#include "SFML/Graphics.hpp"

// four faces change with any rotation
enum ACTION
{UP_RIGHT, UP_LEFT, 
RIGHT_UP, RIGHT_DOWN,
LEFT_UP, LEFT_DOWN,
BOTTOM_RIGHT, BOTTOM_LEFT,
FRONT_RIGHT, FRONT_LEFT,
BACK_RIGHT, BACK_LEFT};

class Cube {

public:
    Cube();
    ~Cube();


    void updateCube(ACTION);

    void displayCube(sf::RenderWindow&);

    void initGraphics();

private:

/*

RED: 255, 0, 0
GREEN: 0, 255, 0
BLUE: 0, 0, 255
ORANGE: 255, 165, 0
WHITE: 255, 255, 255
YELLOW: 255, 255, 0

BLUE:   0
GREEN:  1
ORANGE: 2
RED:    3
WHITE:  4
YELLOW: 5


*/
    std::vector<std::vector<int>> frontFace;  // blue
    std::vector<std::vector<int>> backFace;   // green
    std::vector<std::vector<int>> leftFace;   // orange
    std::vector<std::vector<int>> rightFace;  // red
    std::vector<std::vector<int>> bottomFace; // white
    std::vector<std::vector<int>> topFace;    // yellow


};