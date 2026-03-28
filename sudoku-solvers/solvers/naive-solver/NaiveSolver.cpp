//
// Created by kacperfilip on 3/27/26.
//

#include "NaiveSolver.h"
#include <iostream>
#include <algorithm>

using namespace std;

bool NaiveSolver::isExcluded(size_t row, size_t col, int value) const {
    if (row >= _puzzle.getSize() || col >= _puzzle.getSize()) { throw out_of_range("Index out of range."); }

    vector<int> rowVector = _puzzle.getRow(row);
    vector<int> colVector = _puzzle.getCol(col);
    vector<int> blockVector = _puzzle.getBlock(_puzzle.getBlockIndex(row, col));

    if (ranges::find(rowVector.begin(), rowVector.end(), value) == rowVector.end() ||
        ranges::find(colVector.begin(), colVector.end(), value) == colVector.end() ||
        ranges::find(blockVector.begin(), blockVector.end(), value) == blockVector.end()) {
        return true;
    }
    return false;
}
