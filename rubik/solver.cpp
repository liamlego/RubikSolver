#include "solver.h"
#include <thread>
#include <iostream>

using namespace std;

Solver::Solver() {

}

Solver::~Solver() {

}


void Solver::solve() {

    sf::RenderWindow window(sf::VideoMode(1000, 800), "Rubik");

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();

        display(window);

        window.display();

        // Update cube

        

        // Pause between updates
        this_thread::sleep_for(100ms);
        
    }

}

void Solver::display(sf::RenderWindow &window) {
    cube.displayCube(window);
}