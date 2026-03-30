//
// Created by kacperfilip on 3/29/26.
//

#include "SudokuCNF.h"

#include <unordered_set>
#include <ranges>

using namespace std;

namespace unorderedHelpers {
    template<typename UnorderedIn, typename UnorderedOut = UnorderedIn>
    UnorderedOut makeUnion(const UnorderedIn& in1, const UnorderedIn& in2, const UnorderedIn& in3) {
        UnorderedOut out;
        out.insert(in1.begin(), in1.end());
        out.insert(in2.begin(), in2.end());
        out.insert(in3.begin(), in3.end());
        return out;
    }
}

void SudokuCNF::findPossiblePropositions() {
    int currentId = 1;
    size_t puzzleSize = _puzzle.getSize();

    for (size_t row = 0; row < puzzleSize; ++row) {
        for (size_t col = 0; col < puzzleSize; ++col) {
            if (_puzzle(row, col) == 0) {
                auto valuesInRow = unordered_set<int>();
                auto valuesInCol = unordered_set<int>();
                auto valuesInBlock = unordered_set<int>();
                valuesInRow.reserve(puzzleSize);
                valuesInCol.reserve(puzzleSize);
                valuesInBlock.reserve(puzzleSize);

                for (size_t cellRow = 0; cellRow < puzzleSize; ++cellRow) {
                    if (_puzzle(cellRow, col) != 0) { valuesInCol.insert(_puzzle(cellRow, col)); }
                }
                for (size_t cellCol = 0; cellCol < puzzleSize; ++cellCol) {
                    if (_puzzle(row, cellCol) != 0) { valuesInRow.insert(_puzzle(row, cellCol)); }
                }

                auto currentBlock = _puzzle.getBlock(_puzzle.getBlockIndex(row, col));

                for (const int cell: currentBlock) {
                    if (cell != 0) { valuesInBlock.insert(cell); }
                }

                auto usedValues = unorderedHelpers::makeUnion(valuesInRow, valuesInCol, valuesInBlock);
                auto possibleValuesRange = views::iota(1, static_cast<int>(puzzleSize) + 1)
                                            | views::filter([&](int val) {
                                                return !usedValues.contains(val);
                                            });
                vector<int> possibleValues = vector(possibleValuesRange.begin(), possibleValuesRange.end());

                for (auto possibleValue: possibleValues) {
                    auto proposition = Proposition(row, col, possibleValue, currentId);
                    _propositions.insert({currentId, proposition});
                    ++currentId;
                }
            }
        }
    }
}