//
// Created by kacperfilip on 3/27/26.
//

#include "Solver.h"

#include <chrono>

using namespace std;

void Solver::benchmark() {
    auto start = chrono::high_resolution_clock::now();
    auto result = this->solve();
    auto end = chrono::high_resolution_clock::now();
    auto executionTime = end - start;
    chrono::duration<double> executionTimeSeconds = executionTime;

    cout << "==== " << typeid(*this).name() << " ====" << endl;
    if (result.has_value()) {
        cout << " - Execution time: " << executionTimeSeconds << endl;
        cout << *result;
    } else {
        cout << "Was not able to find a solution." << endl;
    }
}