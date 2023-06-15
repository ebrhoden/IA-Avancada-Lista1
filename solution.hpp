#ifndef SOLUTION_HPP_INCLUDED
#define SOLUTION_HPP_INCLUDED

#include <time.h>
#include<iostream>
#include<iomanip>

class Solution{
    public:
        int number_expanded_nodes;
        int depth;
        clock_t start_time;
        double average_heuristic_value;
        int initial_heuristic_value;
        bool is_valid;

        Solution();

        Solution(int number_expanded_nodes, int depth, clock_t start_time, double average_heuristic_value, int initial_heuristic_value);
        void print();
};


#endif // SOLUTION_HPP_INCLUDED
