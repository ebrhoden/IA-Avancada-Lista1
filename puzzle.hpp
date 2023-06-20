#ifndef PUZZLE_HPP_INCLUDED
#define PUZZLE_HPP_INCLUDED

#include "heuristic_calculator.hpp"
#include "state.hpp"
#include <vector>
#include<iostream>

using namespace std;


class Puzzle{
    public:
        State state;
        int depth; //g
        int heuristic_value; //h
        long long id; //used to keep LIFO ordering when necessary. Else, just use it as 0;
        Puzzle* parent_puzzle;

        //When heuristic doesnt matter
        Puzzle(State state, long long id = 0);
        Puzzle(State state, Puzzle* parent_puzzle, int depth, long long id = 0);

        //When heuristics matter
        Puzzle(State state, HeuristicCalculator &heuristic_calculator, long long id = 0);
        Puzzle(State state, Puzzle* parent_puzzle, int depth, HeuristicCalculator &heuristic_calculator, long long id = 0);

        bool is_parent_state_null();
        bool is_given_state_equal_to_parent_state(State state);

        // This DOES NOT include the parent state of the current state as a valid successor
        vector<State> get_neighbor_states();

        void print();
};

#endif // PUZZLE_HPP_INCLUDED
