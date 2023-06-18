#ifndef GBFS_HPP_INCLUDED
#define GBFS_HPP_INCLUDED
#include "heuristic_calculator.hpp"
#include "solution.hpp"
#include "puzzle.hpp"
#include <queue>
#include <unordered_set>

using namespace std;

struct GBFSComparator {
    bool operator()(Puzzle &a, Puzzle &b) {
        // h
        if(a.heuristic_value != b.heuristic_value){
            return a.heuristic_value > b.heuristic_value;
        }
        // g
        else if(a.depth != b.depth){
            return a.depth < b.depth;
        }
        // LIFO
        return a.id < b.id;
    }
};

Solution solve_gbfs(vector<int> user_input, HeuristicCalculator h);


#endif // GBFS_HPP_INCLUDED
