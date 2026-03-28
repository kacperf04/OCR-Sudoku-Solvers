cmake_minimum_required(VERSION 4.0)
project(sudoku_solvers)

set(CMAKE_CXX_STANDARD 20)

add_executable(sudoku_solvers main.cpp
        model/SudokuGrid.cpp
        model/SudokuGrid.h
        solvers/Solver.cpp
        solvers/Solver.h
        solvers/naive-solver/NaiveSolver.cpp
        solvers/naive-solver/NaiveSolver.h)
