//
// Created by kacperfilip on 3/27/26.
//

#include "NaiveSolver.h"
#include <iostream>
#include <algorithm>

using namespace std;

std::optional<SudokuGrid> NaiveSolver::solve() {
    if (backtrack()) {
        return SudokuGrid{_puzzle};
    }
    return {};
}


std::tuple<size_t, size_t> NaiveSolver::isEmpty() const {
    for (size_t i = 0; i < _puzzle.getSize() * _puzzle.getSize(); ++i) {
        size_t row = i / _puzzle.getSize();
        size_t col = i % _puzzle.getSize();

        if (_puzzle(row, col) == 0) { return tuple{row, col}; }
    }

    return tuple{_puzzle.getSize(), _puzzle.getSize()};
}


bool NaiveSolver::isExcluded(size_t row, size_t col, int value) const {
    if (row >= _puzzle.getSize() || col >= _puzzle.getSize()) { throw out_of_range("Index out of range."); }

    vector<int> rowVector = _puzzle.getRow(row);
    vector<int> colVector = _puzzle.getCol(col);
    vector<int> blockVector = _puzzle.getBlock(_puzzle.getBlockIndex(row, col));

    bool inRow = ranges::find(rowVector.begin(), rowVector.end(), value) != rowVector.end();
    bool inCol = ranges::find(colVector.begin(), colVector.end(), value) != colVector.end();
    bool inBlock = ranges::find(blockVector.begin(), blockVector.end(), value) != blockVector.end();

    return inRow || inCol || inBlock;
}

bool NaiveSolver::backtrack() {
    auto [row, col] = isEmpty();
    if (row == _puzzle.getSize()) return true;

    for (int num = 1; num <= _puzzle.getSize(); ++num) {
        if (!isExcluded(row, col, num)) {
            _puzzle(row, col) = num;
            if (backtrack()) {
                return true;
            }
            _puzzle(row, col) = 0;
        }
    }

    return false;
}

