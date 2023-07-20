#ifndef IDASTAR_HPP_INCLUDED
#define IDASTAR_HPP_INCLUDED
#include <limits>
#include <utility>
#include "puzzle.hpp"
#include "solution.hpp"

using namespace std;

pair<int, Puzzle> depth_limited_search_idastar(Puzzle& p, HeuristicCalculator& h, int f_limit, int& number_expanded_nodes);
Solution solve_idastar(vector<int> user_input, HeuristicCalculator h);

#endif // IDASTAR_HPP_INCLUDED
