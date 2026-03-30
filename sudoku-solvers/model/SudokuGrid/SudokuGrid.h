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

    size_t getSize() const { return _n; }
    size_t getBlockIndex(size_t row, size_t col) const;
    std::vector<int> getBlock(size_t blockIndex) const;
    std::vector<int> getRow(size_t row) const;
    std::vector<int> getCol(size_t col) const;
};


#endif //SUDOKU_SOLVERS_SUDOKUGRID_H