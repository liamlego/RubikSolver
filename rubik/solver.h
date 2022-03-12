#ifndef SOLVER_H
#define SOLVER_H

#include "cube.h"
#include "SFML/Graphics.hpp"

enum STATE {WHITE_CROSS, F2L, YELLOW_CROSS};

class Solver {

public:

    Solver();
    ~Solver();

    void solve(Cube&);
    ACTION getNextAction();
    int getMove();

private:

    std::vector<ACTION> currentMoveSequence;
    int move;

};
#endif