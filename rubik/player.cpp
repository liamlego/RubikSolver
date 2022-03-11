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
            }
        }


        window.clear();

        display(window);

        window.display();

        // Update cube

        if (action != ACTION::NOTHING) {
            cube.updateCube(action);
        }
        

        // Pause between updates
        this_thread::sleep_for(100ms);
        
    }

}

void RubikPlayer::display(sf::RenderWindow &window) {
    cube.displayCube(window);
}