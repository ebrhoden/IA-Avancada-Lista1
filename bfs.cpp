#include "bfs.hpp"

Solution solve_bfs(vector<int> user_input){
    clock_t start_time = clock();
    int num_expanded_nodes = 0;
    int initial_heuristic_value = HeuristicCalculator().calculate(user_input);

    State s(user_input);
    if(s.is_goal()){
        return Solution(0, 0, start_time, 0, initial_heuristic_value);
    }

    queue<Puzzle>* open = new queue<Puzzle>();
    unordered_set<int>* closed = new unordered_set<int>();
    open->push(Puzzle(s));
    closed->insert(s.internal_representation);

    while(!open->empty()){

        Puzzle current_puzzle = open->front();
        open->pop();

        num_expanded_nodes++;

        vector<State> neighbor_states = current_puzzle.get_neighbor_states();

        for(State neighbor_state: neighbor_states){
            if(neighbor_state.is_goal()){
                return Solution(num_expanded_nodes, current_puzzle.depth + 1, start_time, 0, initial_heuristic_value);
            } else if(closed->find(neighbor_state.internal_representation) == closed->end()){
                Puzzle neighbor_puzzle(neighbor_state, current_puzzle.state.internal_representation, current_puzzle.depth + 1);
                closed->insert(neighbor_puzzle.state.internal_representation);
                open->push(neighbor_puzzle);
            }
        }
    }


    return Solution();
}
