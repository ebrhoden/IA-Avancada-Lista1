#ifndef IDFS_HPP_INCLUDED
#define IDFS_HPP_INCLUDED
#include <limits>
#include "puzzle.hpp"
#include "solution.hpp"

using namespace std;

bool depth_limited_search(Puzzle p, int depth_limit, int& number_expanded_ndoes);
Solution solve_idfs(vector<int> user_input);

#endif // IDFS_HPP_INCLUDED
