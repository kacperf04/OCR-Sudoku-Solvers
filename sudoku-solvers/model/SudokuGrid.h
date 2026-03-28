//
// Created by kacperfilip on 3/26/26.
//

#ifndef SUDOKU_SOLVERS_SUDOKUGRID_H
#define SUDOKU_SOLVERS_SUDOKUGRID_H
#include<iostream>
#include<vector>

class SudokuGrid {
    size_t _n;
    size_t _block_size;
    std::vector<int> _grid;

public:
    explicit SudokuGrid(const std::vector<std::vector<int>>& grid);

    friend std::ostream& operator<< (std::ostream& os, const SudokuGrid& grid);
    int& operator() (size_t row, size_t col);
    int operator() (size_t row, size_t col) const;

    size_t blockIndex(size_t row, size_t col) const;
    std::vector<int> block(size_t blockIndex) const;
};


#endif //SUDOKU_SOLVERS_SUDOKUGRID_H