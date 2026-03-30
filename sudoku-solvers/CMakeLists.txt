cmake_minimum_required(VERSION 4.0)
project(sudoku_solvers)

set(CMAKE_CXX_STANDARD 20)

add_executable(sudoku_solvers main.cpp
        model/SudokuGrid/SudokuGrid.cpp
        model/SudokuGrid/SudokuGrid.h
        solvers/Solver.cpp
        solvers/Solver.h
        solvers/naive-solver/NaiveSolver.cpp
        solvers/naive-solver/NaiveSolver.h
        model/Proposition/Proposition.h
        solvers/sat-solver/SudokuCNF.cpp
        solvers/sat-solver/SudokuCNF.h
)

target_link_libraries(sudoku_solvers PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib/libcadical.a)
