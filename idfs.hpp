#ifndef IDFS_HPP_INCLUDED
#define IDFS_HPP_INCLUDED
#include <limits>
#include "puzzle.hpp"
#include "solution.hpp"
#include <unordered_set>

using namespace std;

bool depth_limited_search(Puzzle& current_puzzle, int depth_limit, int& number_expanded_nodes, unordered_set<unsigned long long>& visited);
Solution solve_idfs(vector<int> user_input);

#endif // IDFS_HPP_INCLUDED
