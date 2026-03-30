//
// Created by kacperfilip on 3/29/26.
//

#ifndef SUDOKU_SOLVERS_SUDOKUCNF_H
#define SUDOKU_SOLVERS_SUDOKUCNF_H

#include <iostream>
#include <unordered_map>

#include "../../lib/cadical.hpp"
#include "../../model/Proposition/Proposition.h"
#include "../../model/SudokuGrid/SudokuGrid.h"


class SudokuCNF {
    CaDiCaL::Solver _solver;
    std::unordered_map<int, Proposition> _propositions;
    SudokuGrid _puzzle;

public:
    explicit SudokuCNF(SudokuGrid& puzzle) : _puzzle(std::move(puzzle)) {}
    auto test() { findPossiblePropositions(); return _propositions; }

private:
    void findPossiblePropositions();
};


#endif //SUDOKU_SOLVERS_SUDOKUCNF_H