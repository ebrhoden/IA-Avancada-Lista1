#include "idfs.hpp"

Puzzle depth_limited_search(Puzzle& current_puzzle, int depth_limit, int& number_expanded_nodes){
    if(current_puzzle.state.is_goal()){
        return current_puzzle;
    }

    if(depth_limit > 0){
        number_expanded_nodes ++;
        vector<State> neighbor_states = current_puzzle.get_neighbor_states();

        shared_ptr<Puzzle> current_puzzle_pointer = make_shared<Puzzle>(current_puzzle);
        for(State neighbor_state: neighbor_states){
            if(neighbor_state.is_goal()){
                return Puzzle(neighbor_state, current_puzzle_pointer, current_puzzle.depth + 1);
            } else {
                Puzzle child(neighbor_state, current_puzzle_pointer, current_puzzle.depth + 1);
                Puzzle result = depth_limited_search(child, depth_limit - 1, number_expanded_nodes);
                if(result.depth != -1){
                    return result;
                }
            }
        }
    }

    return Puzzle();
}

Solution solve_idfs(vector<int> user_input){

    clock_t start_time = clock();

    State s(user_input);
    Puzzle initial_puzzle(user_input);

    int num_expanded_nodes = 0;
    int initial_heuristic_value = HeuristicCalculator().calculate(s);

    for(int depth_limit = 0; depth_limit < numeric_limits<int>::max(); depth_limit++) {
        Puzzle result = depth_limited_search(initial_puzzle, depth_limit, num_expanded_nodes);
        if(result.depth != -1) {
            return Solution(num_expanded_nodes, result, start_time, 0, initial_heuristic_value);
        }
    }

    return Solution();
}

/*
Comments:
In this updated code, we perform a depth-limited search for each depth limit starting from 0
and increasing until the maximum integer value. If a solution is found at any depth limit, we
return the solution. This approach ensures that we explore the search space in a depth-first
manner while still guaranteeing completeness.
By using IDDFS, we can avoid the exponential time complexity of traditional depth-first search
and improve the performance of the IDFS algorithm.
*/
