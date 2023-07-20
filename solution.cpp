#include "solution.hpp"
using namespace std;

Solution::Solution(){
    this->is_valid = false;
}

Solution::Solution(int number_expanded_nodes, Puzzle solution_puzzle, clock_t start_time, double average_heuristic_value, int initial_heuristic_value){
    this->number_expanded_nodes = number_expanded_nodes;
    this->solution_puzzle = solution_puzzle;
    this->start_time = start_time;
    this->average_heuristic_value = average_heuristic_value;
    this->initial_heuristic_value = initial_heuristic_value;
    this->is_valid = true;
}

void Solution::print(){
    if(this->is_valid){
        cout << std::fixed << std::showpoint;
        cout << setprecision(10);
        cout << number_expanded_nodes << "," << solution_puzzle.depth << "," << double(clock() - start_time) / double(CLOCKS_PER_SEC) << "," <<  average_heuristic_value << "," <<  initial_heuristic_value << endl;
    } else {
        cout << "-" << "," << "-" << "," << "-" << "," <<  "-" << "," <<  "-" << endl;
    }
}

void Solution::print_path(){
    stack<Puzzle> steps = stack<Puzzle>();
    Puzzle current_puzzle = this->solution_puzzle;

    while(current_puzzle.parent_puzzle != nullptr){
        steps.push(current_puzzle);
        current_puzzle = *current_puzzle.parent_puzzle;
    }

    steps.push(current_puzzle);

    while(!steps.empty()){
        steps.top().print();
        steps.pop();
    }
}
