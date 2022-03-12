#include "solver.h"
#include <thread>
#include <iostream>

#include <queue>

using namespace std;

Solver::Solver() {
    
}

Solver::~Solver() {

}

ACTION Solver::getNextAction() {
    
    ACTION action = currentMoveSequence[move];
    
    if (move + 1 >= currentMoveSequence.size()) {
        move = -1;
    } else {
        move++;
    }

    return action;
}

int Solver::getMove() {
    return move;
}

bool isFaceSolved(std::vector<std::vector<int>> &face) {

    int centerColor = face[1][1];

    for (int i = 0; i < face.size(); i++) {

        for (int j = 0; j < face[i].size(); j++) {
            if (face[i][j] != centerColor) {
                return false;
            }
        }
    }
    return true;
}

bool isCubeSolved(Cube &cube) {

    if (!isFaceSolved(cube.frontFace)) return false;

    if (!isFaceSolved(cube.backFace)) return false;

    if (!isFaceSolved(cube.rightFace)) return false;

    if (!isFaceSolved(cube.leftFace)) return false;

    if (!isFaceSolved(cube.topFace)) return false;

    if (!isFaceSolved(cube.bottomFace)) return false;

    return true;
}

ACTION getInverseAction(ACTION action) {

    switch (action) {

        case ACTION::UP_RIGHT:
            return ACTION::UP_LEFT;
        case ACTION::UP_LEFT:
            return ACTION::UP_RIGHT;
        case ACTION::BOTTOM_LEFT:
            return ACTION::BOTTOM_RIGHT;
        case ACTION::BOTTOM_RIGHT:
            return ACTION::BOTTOM_LEFT;
        case ACTION::FRONT_LEFT:
            return ACTION::FRONT_RIGHT;
        case ACTION::FRONT_RIGHT:
            return ACTION::FRONT_LEFT;
        case ACTION::BACK_RIGHT:
            return ACTION::BACK_LEFT;
        case ACTION::BACK_LEFT:
            return ACTION::BACK_RIGHT;
        case ACTION::LEFT_UP:
            return ACTION::LEFT_DOWN;
        case ACTION::LEFT_DOWN:
            return ACTION::LEFT_UP;
        case ACTION::RIGHT_UP:
            return ACTION::RIGHT_DOWN;
        case ACTION::RIGHT_DOWN:
            return ACTION::RIGHT_UP;
    }

    return ACTION::NOTHING;
}

void printVect(std::vector<ACTION> list) {

    for (int i = 0; i < list.size(); i++) {

        std::cout << list[i] << ", ";

    }
    std::cout << std::endl;

}

std::vector<ACTION> getNextActions(Cube &cube) {

    Cube copyCube = cube;

    ACTION previousAction = ACTION::NOTHING;

    ACTION bannedFutureAction = ACTION::NOTHING;

    std::queue<std::pair<Cube, std::vector<ACTION>>> actions;

    actions.push({cube, {ACTION::NOTHING}});


    int steps = 0;

    while (!actions.empty() && steps < INT_MAX) {

        auto curr = actions.front();
        actions.pop();

        if (isCubeSolved(curr.first)) {
            return curr.second;
        }
        
        for (int i = 0; i < 12; i++) {

            if (bannedFutureAction != i) {
                
                std::vector<ACTION> v = curr.second;
                v.push_back(static_cast<ACTION>(i));
                Cube nextCube = curr.first;
                nextCube.updateCube(static_cast<ACTION>(i));
                actions.push({nextCube, v});

                if (previousAction == i) {
                    bannedFutureAction = static_cast<ACTION>(i);
                } else {
                    bannedFutureAction = ACTION::NOTHING;
                }
                previousAction = static_cast<ACTION>(i);
            }
        }
        steps++;
    }

    return {ACTION::NOTHING};
}

void Solver::solve(Cube &cube) {

    currentMoveSequence = getNextActions(cube);
    move = 0;

}