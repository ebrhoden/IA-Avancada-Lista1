#ifndef PUZZLE_HPP_INCLUDED
#define PUZZLE_HPP_INCLUDED

#include "heuristic_calculator.hpp"
#include "state.hpp"
#include <vector>
#include<iostream>
#include<memory>
#include<map>

using namespace std;

class Puzzle{
    public:
        State state;
        int depth; //g
        int heuristic_value; //h
        unsigned long long id; //used to keep LIFO ordering when necessary. Else, just use it as 0;
        shared_ptr<Puzzle> parent_puzzle;

        Puzzle();

        //When heuristic doesnt matter
        Puzzle(const State &state, const unsigned long long &id = 0);
        Puzzle(const State &state, shared_ptr<Puzzle> parent_puzzle, const int &depth, const unsigned long long &id = 0);

        //When heuristics matter
        Puzzle(const State &state, HeuristicCalculator &heuristic_calculator, const unsigned long long &id = 0);
        Puzzle(const State &state, shared_ptr<Puzzle> parent_puzzle, const int &depth, HeuristicCalculator &heuristic_calculator, const unsigned long long &id = 0);

        bool is_parent_state_null();
        bool is_given_state_equal_to_parent_state(const State &state);

        // This DOES NOT include the parent state of the current state as a valid successor
        vector<State> get_neighbor_states();

        void print();

        void print_path();
};

#endif // PUZZLE_HPP_INCLUDED
