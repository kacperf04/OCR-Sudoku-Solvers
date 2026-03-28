//
// Created by kacperfilip on 3/27/26.
//

#ifndef SUDOKU_SOLVERS_NAIVESOLVER_H
#define SUDOKU_SOLVERS_NAIVESOLVER_H
#include <iostream>
#include "../Solver.h"

class NaiveSolver : public Solver {
public:
    NaiveSolver(SudokuGrid puzzle, float timeLimit) : Solver(std::move(puzzle), timeLimit) {}

    std::optional<SudokuGrid> solve() override;
    bool isSafe(size_t n, size_t m, int number);
};


#endif //SUDOKU_SOLVERS_NAIVESOLVER_H