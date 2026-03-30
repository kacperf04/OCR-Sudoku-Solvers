//
// Created by kacperfilip on 3/29/26.
//

#ifndef SUDOKU_SOLVERS_PROPOSITION_H
#define SUDOKU_SOLVERS_PROPOSITION_H
#include <iostream>

class Proposition {
public:
    size_t _row;
    size_t _col;
    int _value;
    int _id;

    Proposition(size_t row, size_t col, int value, int id) : _row(row), _col(col), _value(value), _id(id) {}
};


#endif //SUDOKU_SOLVERS_PROPOSITION_H