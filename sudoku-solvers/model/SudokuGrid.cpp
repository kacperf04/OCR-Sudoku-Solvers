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

size_t SudokuGrid::blockIndex(size_t row, size_t col) const {
    if (row >= _n || col >= _n) { throw out_of_range("Index out of range."); }

    size_t col_n = col / _block_size;

    return row + col_n;
}

std::vector<int> SudokuGrid::block(size_t blockIndex) const {
    if (blockIndex >= _n) { throw out_of_range("Block index out of range."); }

    vector<int> block;
    block.reserve(_n);

    size_t blockRow = blockIndex / _block_size;
    size_t blockCol = blockIndex % _block_size;
    size_t start = _n * blockRow * _block_size + blockCol * _block_size;

    for (size_t i = 0; i < _block_size; ++i) {
        block.insert(block.end(), &_grid[start + i * _n], &_grid[start + i * _n + _block_size]);
    }

    return block;
}



