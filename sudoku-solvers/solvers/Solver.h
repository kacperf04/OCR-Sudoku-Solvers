//
// Created by kacperfilip on 3/27/26.
//

#ifndef SUDOKU_SOLVERS_SOLVER_H
#define SUDOKU_SOLVERS_SOLVER_H
#include <iostream>
#include <optional>

#include "../model/SudokuGrid.h"

class Solver {
protected:
    SudokuGrid _puzzle;
    float _timeLimit;

public:
    Solver(SudokuGrid puzzle, float timeLimit) : _puzzle(std::move(puzzle)), _timeLimit(timeLimit) {}
    virtual ~Solver() = default;

    virtual std::optional<SudokuGrid> solve() = 0;
};


#endif //SUDOKU_SOLVERS_SOLVER_H