//
// Created by kacperfilip on 3/26/26.
//

#include "SudokuGrid.h"

#include <cmath>
#include <iostream>
#include <stdexcept>

using namespace std;

SudokuGrid::SudokuGrid(const std::vector<std::vector<int> > &grid) {
    if (grid.empty()) { throw invalid_argument("The grid cannot be empty."); }

    _n = grid.size();
    _block_size = static_cast<size_t>(sqrt(_n));
    if (_block_size * _block_size != _n) { throw invalid_argument("Grid dimensions must be a perfect square."); }

    _grid.reserve(_n * _n);
    for (size_t i = 0; i < _n; ++i) {
        if (grid[i].size() != _n) { throw invalid_argument("Row length mismatch."); }
        _grid.insert(_grid.end(), grid[i].begin(), grid[i].end());
    }
}

ostream& operator<< (ostream& os, const SudokuGrid& grid) {
    size_t horizontalSeparatorLength = grid._n + grid._block_size + grid._block_size * (grid._block_size - 1) + 1;
    string horizontalSeparator = string(horizontalSeparatorLength, '-');

    os << horizontalSeparator << endl;
    for (size_t i = 0; i < grid._n; ++i) {
        for (size_t j = 0; j < grid._n; ++j) {
            if (j % grid._block_size == 0) {
                os << '|';
            } else {
                os << " ";
            }
            os << grid._grid[i*grid._n + j];
        }
        os << '|' << endl;
        if (i % grid._block_size == (grid._block_size - 1)) os << horizontalSeparator << endl;
    }

    return os;
}

int& SudokuGrid::operator()(size_t row, size_t col) {
    if (row >= _n || col >= _n) { throw out_of_range("Index out of range."); }

    return _grid[row*_n + col];
}

int SudokuGrid::operator()(size_t row, size_t col) const {
    if (row >= _n || col >= _n) { throw out_of_range("Index out of range."); }

    return _grid[row*_n + col];
}

size_t SudokuGrid::getBlockIndex(size_t row, size_t col) const {
    if (row >= _n || col >= _n) { throw out_of_range("Index out of range."); }

    size_t block_row = row / _block_size;
    size_t block_col = col / _block_size;

    return block_row * _block_size + block_col;
}

vector<int> SudokuGrid::getBlock(size_t blockIndex) const {
    if (blockIndex >= _n) { throw out_of_range("Block index out of range."); }

    vector<int> block;
    block.reserve(_n);

    size_t startRow = (blockIndex / _block_size) * _block_size;
    size_t startCol = (blockIndex % _block_size) * _block_size;

    for (size_t i = 0; i < _block_size; ++i) {
        for (size_t j = 0; j < _block_size; ++j) {
            block.push_back((*this)(startRow + i, startCol + j));
        }
    }

    return block;
}

std::vector<int> SudokuGrid::getRow(size_t row) const {
    if (row >= _n) { throw out_of_range("Row index out of range."); }

    vector<int> rowVector = vector<int>();
    rowVector.reserve(_n);
    rowVector.insert(rowVector.end(), _grid.begin() + row * _n, _grid.begin() + row * _n + _n);

    return rowVector;
}

std::vector<int> SudokuGrid::getCol(size_t col) const {
    if (col >= _n) { throw out_of_range("Col index out of range"); }

    vector<int> colVetor = vector<int>();
    colVetor.reserve(_n);

    for (size_t i = 0; i < _n; ++i) {
        colVetor.insert(colVetor.end(), _grid[i * _n + col]);
    }

    return colVetor;
}





