#ifndef HEURISTIC_CALCULATOR_HPP_INCLUDED
#define HEURISTIC_CALCULATOR_HPP_INCLUDED

#include <vector>
#include <stdlib.h>
#include "math.h"
#include<iostream>

using namespace std;

class HeuristicCalculator {
  public:
    int called_count;
    int accumulator;

    HeuristicCalculator();

    // Manhattan distance
    int calculate(const vector<int> tiles);

    double average_result();
};

#endif // HEURISTIC_CALCULATOR_HPP_INCLUDED
