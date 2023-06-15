#ifndef A_STAR_HPP_INCLUDED
#define A_STAR_HPP_INCLUDED
#include "puzzle.hpp"
#include "solution.hpp"
#include "queue"
#include "set"

using namespace std;

struct AStarComparator {
    bool operator()(Puzzle &a, Puzzle &b) {
        // f = g + h
        int f_a = a.heuristic_value + a.depth;
        int f_b = b.heuristic_value + b.depth;

        if(f_a != f_b){
            return f_a > f_b;
        }
        // g
        else if(a.heuristic_value != b.heuristic_value){
            return a.heuristic_value > b.heuristic_value;
        }
        // LIFO
        return a.id < b.id;
    }
};

Solution solve_a_star(vector<int> user_input, HeuristicCalculator h);


#endif // A_STAR_HPP_INCLUDED
