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
        int id; //used to keep LIFO ordering when necessary. Else, just use it as 0;
        unsigned long long parent_state_representation;

        //When heuristic doesnt matter
        Puzzle(State state, int id = 0);
        Puzzle(State state, int parent_state_representation, int depth, int id = 0);

        //When heuristics matter
        Puzzle(State state, HeuristicCalculator &heuristic_calculator, int id = 0);
        Puzzle(State state, int parent_state_representation, int depth, HeuristicCalculator &heuristic_calculator, int id = 0);

        State move_blank_up(int blank_position, int n);
        State move_blank_left(int blank_position);
        State move_blank_right(int blank_position);
        State move_blank_down(int blank_position, int n);

        bool is_parent_state_null();
        bool is_given_state_equal_to_parent_state(State state);

        // This DOES NOT include the parent state of the current state as a valid successor
        vector<State> get_neighbor_states();

        void print();
};


#endif // PUZZLE_HPP_INCLUDED
