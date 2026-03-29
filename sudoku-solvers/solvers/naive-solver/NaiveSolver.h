//
// Created by kacperfilip on 3/27/26.
//

#ifndef SUDOKU_SOLVERS_NAIVESOLVER_H
#define SUDOKU_SOLVERS_NAIVESOLVER_H
#include <iostream>
#include "../Solver.h"

class NaiveSolver : public Solver {
public:
    explicit NaiveSolver(SudokuGrid puzzle) : Solver(std::move(puzzle)) {}

    std::optional<SudokuGrid> solve() override;

private:
    std::tuple<size_t, size_t> isEmpty() const;
    bool isExcluded(size_t row, size_t col, int value) const;
    bool backtrack();


};


#endif //SUDOKU_SOLVERS_NAIVESOLVER_H