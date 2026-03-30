//
// Created by kacperfilip on 3/27/26.
//

#ifndef SUDOKU_SOLVERS_SOLVER_H
#define SUDOKU_SOLVERS_SOLVER_H
#include <iostream>
#include <optional>

#include "../model/SudokuGrid/SudokuGrid.h"

class Solver {
protected:
    SudokuGrid _puzzle;

public:
    Solver(SudokuGrid puzzle) : _puzzle(std::move(puzzle)) {}
    virtual ~Solver() = default;

    virtual std::optional<SudokuGrid> solve() = 0;
    virtual void benchmark();
};


#endif //SUDOKU_SOLVERS_SOLVER_H