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
                if (event.key.code == sf::Keyboard::U) {
                    action = ACTION::UP_RIGHT;
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