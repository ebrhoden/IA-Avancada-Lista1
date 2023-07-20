#include "idastar.hpp"

pair<int, Puzzle> depth_limited_search_idastar(Puzzle& current_puzzle, HeuristicCalculator &h, int f_limit, int &number_expanded_nodes) {
    int current_f = current_puzzle.heuristic_value + current_puzzle.depth;
    if (current_f > f_limit) {
        return pair<int, Puzzle>{current_f, Puzzle()};
    }

    if (current_puzzle.state.is_goal()) {
        return pair<int, Puzzle>{-1, current_puzzle};
    }

    int next_limit = numeric_limits<int>::max();

    number_expanded_nodes++;
    vector<State> neighbor_states = current_puzzle.get_neighbor_states();

    shared_ptr<Puzzle> current_puzzle_pointer = make_shared<Puzzle>(current_puzzle);
    for (State neighbor_state : neighbor_states) {
        Puzzle child(neighbor_state, current_puzzle_pointer, current_puzzle.depth + 1, h);
        pair<int, Puzzle> recursive_result = depth_limited_search_idastar(child, h, f_limit, number_expanded_nodes);

        if (recursive_result.second.depth != -1) {
            return pair<int, Puzzle>{-1, recursive_result.second};
        }

        next_limit = min<int>(next_limit, recursive_result.first);
    }

    return pair<int, Puzzle>{next_limit, Puzzle()};
}

Solution solve_idastar(vector<int> user_input, HeuristicCalculator h){
    int number_expanded_nodes = 0;
    int f_limit;
    int initial_heuristic_value;

    clock_t start_time = clock();

    State s(user_input);

    Puzzle initial_puzzle(user_input, h);

    initial_heuristic_value = initial_puzzle.heuristic_value;

    f_limit = initial_puzzle.heuristic_value;

    while(f_limit < numeric_limits<int>::max()){
        Puzzle initial_puzzle(user_input, h);
        pair<int, Puzzle> solution = depth_limited_search_idastar(initial_puzzle, h, f_limit, number_expanded_nodes);
        if(solution.second.depth != -1){
            //return Solution(number_expanded_nodes, solution.second, start_time, h.average_result(), initial_heuristic_value);
            return Solution(number_expanded_nodes, solution.second, start_time, h.average_result(), initial_heuristic_value);
        }
        f_limit = solution.first;
        // I belive this is the line we should instantiate the initial puzzle again,
        // but then results dont match with the professor's.
        //Puzzle initial_puzzle(user_input, h);

    }

    return Solution();
}

