#include "bfs.hpp"

Solution solve_bfs(vector<int> user_input){
    queue<Puzzle> open = queue<Puzzle>();
    unordered_set<unsigned long long> closed = unordered_set<unsigned long long>();
    vector<State> neighbor_states = vector<State>();
    int num_expanded_nodes = 0;
    int initial_heuristic_value;

    clock_t start_time = clock();

    State s(user_input);
    initial_heuristic_value = HeuristicCalculator().calculate(s);
    open.push(Puzzle(s));
    closed.insert(s.internal_representation);

    while(!open.empty()){

        Puzzle current_puzzle = open.front();
        open.pop();

        if(current_puzzle.state.is_goal()){
            return Solution(num_expanded_nodes, current_puzzle, start_time, 0, initial_heuristic_value);
        }

        num_expanded_nodes++;
        neighbor_states = current_puzzle.get_neighbor_states();

        shared_ptr<Puzzle> current_puzzle_pointer = make_shared<Puzzle>(current_puzzle);
        for(State neighbor_state: neighbor_states){
            if(neighbor_state.is_goal()){
                return Solution(num_expanded_nodes, Puzzle(neighbor_state, current_puzzle_pointer, current_puzzle.depth + 1), start_time, 0, initial_heuristic_value);
            }
            else if(closed.find(neighbor_state.internal_representation) == closed.end()){
                closed.insert(neighbor_state.internal_representation);
                open.push(Puzzle(neighbor_state, current_puzzle_pointer, current_puzzle.depth + 1));
            }
        }
    }

    return Solution();
}
