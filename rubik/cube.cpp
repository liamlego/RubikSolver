#include "cube.h"

/*
BLUE:   0
GREEN:  1
ORANGE: 2
RED:    3
WHITE:  4
YELLOW: 5

*/

static const int WIDTH = 35;
static const int HEIGHT = 35;

Cube::Cube() {

    frontFace.resize(3);

    for (int i = 0; i < frontFace.size(); i++) {
        for (int j = 0; j < 3; j++) {
            frontFace[i].push_back(0);
        }
    }

    backFace.resize(3);

    for (int i = 0; i < backFace.size(); i++) {
        for (int j = 0; j < 3; j++) {
            backFace[i].push_back(1);
        }
    }

    leftFace.resize(3);

    for (int i = 0; i < leftFace.size(); i++) {
        for (int j = 0; j < 3; j++) {
            leftFace[i].push_back(2);
        }
    }

    rightFace.resize(3);

    for (int i = 0; i < rightFace.size(); i++) {
        for (int j = 0; j < 3; j++) {
            rightFace[i].push_back(3);
        }
    }

    bottomFace.resize(3);

    for (int i = 0; i < bottomFace.size(); i++) {
        for (int j = 0; j < 3; j++) {
            bottomFace[i].push_back(4);
        }
    }

    topFace.resize(3);

    for (int i = 0; i < topFace.size(); i++) {
        for (int j = 0; j < 3; j++) {
            topFace[i].push_back(5);
        }
    }

}



Cube::~Cube() {

}



void Cube::initGraphics() {




}

void Cube::updateCube(ACTION action) {


    if (action == UP_RIGHT) {

    }
    else if (action == UP_LEFT) {

    }
    else if (action == RIGHT_UP) {

    }
    else if (action == RIGHT_DOWN) {
        
    }
    else if (action == LEFT_UP) {
        
    }
    else if (action == LEFT_DOWN) {
        
    }
    else if (action == BOTTOM_RIGHT) {
        
    }
    else if (action == BOTTOM_LEFT) {
        
    }
    else if (action == FRONT_RIGHT) {
        
    }
    else if (action == FRONT_LEFT) {
        
    }
    else if (action == BACK_RIGHT) {
        
    }
    else if (action == BACK_LEFT) {
        
    }



}

/*
BLUE:   0
GREEN:  1
ORANGE: 2
RED:    3
WHITE:  4
YELLOW: 5

*/

void drawSquare(sf::RenderWindow &window, float x, float y, int colorCode) {

    sf::RectangleShape square;

    sf::Vector2f drawSize;

    drawSize.x = WIDTH;
    drawSize.y = HEIGHT;

    sf::Vector2f drawLocation;

    drawLocation.x = x;
    drawLocation.y = y;

    square.setSize(drawSize);

    square.setPosition(drawLocation);


    sf::Color color;

    switch (colorCode) {

        case 0:
            {
            sf::Color co(0, 0, 255);
            square.setFillColor(co);
            break;
            }

        case 1:
            {
            sf::Color co1(0, 255, 0);
            square.setFillColor(co1);
            break;
            }

        case 2:
            {
            sf::Color co2(255, 165, 0);
            square.setFillColor(co2);
            break;
            }

        case 3:
            {
            sf::Color co3(255, 0, 0);
            square.setFillColor(co3);
            break;
            }

        case 4:
            {
            sf::Color co4(255, 255, 255);
            square.setFillColor(co4);
            break;
            }

        case 5:
            {
            sf::Color co5(255, 255, 0);
            square.setFillColor(co5);
            break;
            }
    }

    sf::Color outlineColor(128, 128, 128);

    square.setOutlineColor(outlineColor);
    square.setOutlineThickness(1);

    window.draw(square);
}

void drawFace(sf::RenderWindow &window, float startX, float startY, std::vector<std::vector<int>> &face) {

    float x = startX;
    float y = startY;

    for (int i = 0; i < face.size(); i++) {
        for (int j = 0; j < face[i].size(); j++) {
            drawSquare(window, x, y, face[i][j]);
            x += WIDTH;
        }
        x = startX;
        y += HEIGHT;
    }

}

void Cube::displayCube(sf::RenderWindow &window) {


    int pivotX = 1000/2-40;
    int pivotY = 800/2-40;

    drawFace(window, pivotX, pivotY, frontFace);
    drawFace(window, (pivotX)-35*3, pivotY, leftFace);
    drawFace(window, (pivotX)+35*3, pivotY, rightFace);
    drawFace(window, (pivotX)+35*6, pivotY, backFace);
    drawFace(window, (pivotX), pivotY+35*3, bottomFace);
    drawFace(window, (pivotX), pivotY-35*3, topFace);

    
}