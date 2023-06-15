#include "gbfs.hpp"

Solution solve_gbfs(vector<int> user_input, HeuristicCalculator h){
    int puzzle_counter = 1;
    int num_expanded_nodes = 0;
    priority_queue<Puzzle, vector<Puzzle>, GBFSComparator>* open = new priority_queue<Puzzle, vector<Puzzle>, GBFSComparator>();
    set<vector<int>>* closed = new set<vector<int>>();
    int initial_heuristic_value;
    clock_t start_time = clock();

    State s(user_input);
    Puzzle p(s, h);
    initial_heuristic_value = p.heuristic_value;
    open->push(p);

    while(!open->empty()){
        Puzzle current_puzzle = open->top();
        open->pop();

        if(closed->find(current_puzzle.state.tiles) == closed->end()){
            closed->insert(current_puzzle.state.tiles);
            if(current_puzzle.state.is_goal()){
                return Solution(num_expanded_nodes, current_puzzle.depth, start_time, (double)h.accumulator/h.called_count, initial_heuristic_value);
            }

            num_expanded_nodes++;

            vector<State> neighbor_states = current_puzzle.get_neighbor_states();

            for(State neighbor_state: neighbor_states){
                Puzzle p(neighbor_state, current_puzzle.state, current_puzzle.depth + 1, h, puzzle_counter);
                puzzle_counter++;
                open->push(p);
            }
        }
    }

    return Solution();
}
