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

private:
    std::tuple<size_t, size_t> incrementCoordinates(size_t row, size_t col) const;
    bool isExcluded(size_t row, size_t col, int value) const;
};


#endif //SUDOKU_SOLVERS_NAIVESOLVER_H