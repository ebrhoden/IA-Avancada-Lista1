#include "gbfs.hpp"

Solution solve_gbfs(vector<int> user_input, HeuristicCalculator h){
    unsigned long long puzzle_counter = 1;
    int num_expanded_nodes = 0;
    priority_queue<Puzzle, vector<Puzzle>, GBFSComparator> open = priority_queue<Puzzle, vector<Puzzle>, GBFSComparator>();
    unordered_set<unsigned long long> closed = unordered_set<unsigned long long>();
    int initial_heuristic_value;

    clock_t start_time = clock();

    State s(user_input);
    Puzzle initial_puzzle = Puzzle(s, h);
    initial_heuristic_value = initial_puzzle.heuristic_value;
    open.push(initial_puzzle);


    while(!open.empty()){
        Puzzle current_puzzle = open.top();
        open.pop();

        if(closed.find(current_puzzle.state.internal_representation) == closed.end()){
            closed.insert(current_puzzle.state.internal_representation);
            if(current_puzzle.state.is_goal()){
                return Solution(num_expanded_nodes, current_puzzle, start_time, h.average_result(), initial_heuristic_value);
            }

            num_expanded_nodes++;
            vector<State> neighbor_states = current_puzzle.get_neighbor_states();

            shared_ptr<Puzzle> current_puzzle_pointer = make_shared<Puzzle>(current_puzzle);
            for(State neighbor_state: neighbor_states){
                puzzle_counter++;
                open.push(Puzzle(neighbor_state, current_puzzle_pointer, current_puzzle.depth + 1, h, puzzle_counter));
            }
        }
    }


    return Solution();
}
