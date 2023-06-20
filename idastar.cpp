#include "idastar.hpp"

pair<int, int> depth_limited_search_idastar(Puzzle& current_puzzle, HeuristicCalculator &h, int f_limit, int &number_expanded_nodes) {
    int current_f = current_puzzle.heuristic_value + current_puzzle.depth;
    if (current_f > f_limit) {
        return pair<int, int>{current_f, -1};
    }

    if (current_puzzle.state.is_goal()) {
        return pair<int, int>{-1, current_puzzle.depth};
    }

    int next_limit = numeric_limits<int>::max();
    number_expanded_nodes++;
    vector<State> neighbor_states = current_puzzle.get_neighbor_states();

    for (State neighbor_state : neighbor_states) {
        Puzzle child(neighbor_state, &current_puzzle, current_puzzle.depth + 1, h);
        pair<int, int> recursive_result = depth_limited_search_idastar(child, h, f_limit, number_expanded_nodes);

        if (recursive_result.second != -1) {
            return pair<int, int>{-1, recursive_result.second};
        }

        next_limit = min<int>(next_limit, recursive_result.first);
    }

    if (next_limit == numeric_limits<int>::max()) {
        return pair<int, int>{next_limit, -1};
    }

    return pair<int, int>{next_limit, -1};
}

Solution solve_idastar(vector<int> user_input, HeuristicCalculator h){
    State s(user_input);

    Puzzle initial_puzzle(user_input, h);

    clock_t start_time = clock();
    int initial_heuristic_value = initial_puzzle.heuristic_value;

    int number_expanded_nodes = 0;
    int f_limit = initial_puzzle.heuristic_value;

    while(f_limit != numeric_limits<int>::max()){
        Puzzle initial_puzzle(user_input, h);
        pair<int,int> solution = depth_limited_search_idastar(initial_puzzle, h, f_limit, number_expanded_nodes);
        if(solution.second != -1){
            return Solution(number_expanded_nodes, solution.second, start_time, h.average_result(), initial_heuristic_value);
        }
        f_limit = solution.first;
        // I belive this is the line we should instantiate the initial puzzle again,
        // but then results dont match with the professor's.
        //Puzzle initial_puzzle(user_input, h);

    }

    return Solution();
}

