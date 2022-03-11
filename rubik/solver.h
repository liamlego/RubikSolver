#include "cube.h"
#include "SFML/Graphics.hpp"

class Solver {

public:

    Solver();
    ~Solver();

    void solve();
    void display(sf::RenderWindow&);

private:

    Cube cube;

};