#include "idfs.hpp"

bool depth_limited_search(Puzzle current_puzzle, int depth_limit, int& number_expanded_nodes){
    if(current_puzzle.state.is_goal()){
        return true;
    }

    if(depth_limit > 0){
        number_expanded_nodes ++;
        vector<State> neighbor_states = current_puzzle.get_neighbor_states();

        for(State neighbor_state: neighbor_states){
            Puzzle child(neighbor_state, current_puzzle.state, current_puzzle.depth);
            bool is_done = depth_limited_search(child, depth_limit - 1, number_expanded_nodes);
            if(is_done){
                return true;
            }
        }
    }
    return false;
}


Solution solve_idfs(vector<int> user_input){
    clock_t start_time = clock();
    int num_expanded_nodes = 0;
    int initial_heuristic_value = HeuristicCalculator().calculate(user_input);
    int depth_limit = 0;

    State s(user_input);
    Puzzle initial_puzzle(user_input);

    for (int depth_limit = 0; depth_limit < numeric_limits<int>::max(); depth_limit++) {
        bool is_done = depth_limited_search(initial_puzzle, depth_limit, num_expanded_nodes);
        if(is_done) {
            return Solution(num_expanded_nodes, depth_limit, start_time, 0, initial_heuristic_value);
        }
    }

    return Solution();
}
