#include "player.h"
#include <thread>
#include <iostream>

using namespace std;


RubikPlayer::RubikPlayer() {

}


RubikPlayer::~RubikPlayer() {



}

void RubikPlayer::play() {

    sf::RenderWindow window(sf::VideoMode(1000, 800), "Rubik");

    bool solveIt = false;
    bool doSequence = false;

    std::chrono::milliseconds time = 100ms;

    while (window.isOpen()) {

        ACTION action = NOTHING;


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::W) {
                    action = ACTION::UP_RIGHT;
                }
                else if (event.key.code == sf::Keyboard::Q) {
                    action = ACTION::UP_LEFT;
                } 
                else if (event.key.code == sf::Keyboard::E) {
                    action = ACTION::BOTTOM_LEFT;
                } 
                else if (event.key.code == sf::Keyboard::R) {
                    action = ACTION::BOTTOM_RIGHT;
                }
                else if (event.key.code == sf::Keyboard::A) {
                    action = ACTION::FRONT_LEFT;
                }
                else if (event.key.code == sf::Keyboard::S) {
                    action = ACTION::FRONT_RIGHT;
                }
                else if (event.key.code == sf::Keyboard::D) {
                    action = ACTION::BACK_LEFT;
                }
                else if (event.key.code == sf::Keyboard::F) {
                    action = ACTION::BACK_RIGHT;
                }
                else if (event.key.code == sf::Keyboard::O) {
                    action = ACTION::RIGHT_UP;
                }
                else if (event.key.code == sf::Keyboard::P) {
                    action = ACTION::RIGHT_DOWN;
                }
                else if (event.key.code == sf::Keyboard::U) {
                    action = ACTION::LEFT_UP;
                }
                else if (event.key.code == sf::Keyboard::I) {
                    action = ACTION::LEFT_DOWN;
                }
                else if (event.key.code == sf::Keyboard::Space) {
                    action = ACTION::NOTHING;
                    solveIt = true;
                }
            }
        }


        window.clear();

        display(window);

        window.display();

        // Update cube

        if (action != ACTION::NOTHING && !solveIt && !doSequence) {
            cube.updateCube(action);
        }
        else if (solveIt) {
            solver.solve(cube, 0);
            std::cout << "DONE!" << std::endl;
            solveIt = false;
            doSequence = true;
            time = 1000ms;
            std::cout << "STARTING SEQUENCE!" << std::endl;
        }
        else if (doSequence) {
            
            if (solver.getMove() == -1) {
                time = 100ms;
                doSequence = false;
            } else {
                cube.updateCube(solver.getNextAction());
            }

        }
        

        // Pause between updates
        this_thread::sleep_for(time);
        
    }

}

void RubikPlayer::display(sf::RenderWindow &window) {
    cube.displayCube(window);
}