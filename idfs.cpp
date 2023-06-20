#include "idfs.hpp"

bool depth_limited_search(Puzzle& current_puzzle, int depth_limit, int& number_expanded_nodes, unordered_set<unsigned long long>& visited) {
    if (current_puzzle.state.is_goal()) {
        return true;
    }

    if (depth_limit > 0) {
        visited.insert(current_puzzle.state.internal_representation);
        number_expanded_nodes++;
        vector<State> neighbor_states = current_puzzle.get_neighbor_states();

        for (State neighbor_state : neighbor_states) {
            if (visited.find(neighbor_state.internal_representation) == visited.end()) {
                Puzzle child(neighbor_state, &current_puzzle, current_puzzle.depth + 1);
                bool is_done = depth_limited_search(child, depth_limit - 1, number_expanded_nodes, visited);
                if (is_done) {
                    return true;
                }
            }
        }
    }

    return false;
}

Solution solve_idfs(vector<int> user_input) {
    clock_t start_time = clock();

    State s(user_input);
    Puzzle initial_puzzle(user_input);

    int num_expanded_nodes = 0;
    int initial_heuristic_value = HeuristicCalculator().calculate(s);
    int depth_limit = 0;

    unordered_set<unsigned long long> visited;

    for (int depth_limit = 0; depth_limit < numeric_limits<int>::max(); depth_limit++) {
        visited.clear();
        bool is_done = depth_limited_search(initial_puzzle, depth_limit, num_expanded_nodes, visited);
        if (is_done) {
            return Solution(num_expanded_nodes, depth_limit, start_time, 0, initial_heuristic_value);
        }
    }

    return Solution();
}
