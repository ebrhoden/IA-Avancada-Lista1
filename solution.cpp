#include "solution.hpp"
using namespace std;

Solution::Solution(){
    this->is_valid = false;
}

Solution::Solution(int number_expanded_nodes, int depth, clock_t start_time, double average_heuristic_value, int initial_heuristic_value){
    this->number_expanded_nodes = number_expanded_nodes;
    this->depth = depth;
    this->start_time = start_time;
    this->average_heuristic_value = average_heuristic_value;
    this->initial_heuristic_value = initial_heuristic_value;
    this->is_valid = true;
}

void Solution::print(){
    if(this->is_valid){
        cout << std::fixed << std::showpoint;
        cout << setprecision(10);
        cout << number_expanded_nodes << "," << depth << "," << double(clock() - start_time) / double(CLOCKS_PER_SEC) << "," <<  average_heuristic_value << "," <<  initial_heuristic_value << endl;
    } else {
        cout << "-" << "," << "-" << "," << "-" << "," <<  "-" << "," <<  "-" << endl;
    }
}
