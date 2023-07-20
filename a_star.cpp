#include "a_star.hpp"

/*
    The cost to get from Puzzle "p" to Puzzle "p + 1" is always one.

    This means that we DO NOT have to keep track of the f value of every Puzzle that is put into open or closed,
    since that as soon as a puzzle is inserted to open or closed the next time we too into that Puzzle its f value will be bigger,
    therefore it's a bad path, since it's g (depth) will also be bigger.
*/

Solution solve_a_star(vector<int> user_input, HeuristicCalculator h){
    unsigned long long puzzle_counter = 1;
    int num_expanded_nodes = 0;
    priority_queue<Puzzle, vector<Puzzle>, AStarComparator> open = priority_queue<Puzzle, vector<Puzzle>, AStarComparator>();
    unordered_set<unsigned long long> closed = unordered_set<unsigned long long>();
    int initial_heuristic_value;
    vector<State> neighbor_states = vector<State>();

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
            neighbor_states = current_puzzle.get_neighbor_states();

            shared_ptr<Puzzle> current_puzzle_pointer = make_shared<Puzzle>(current_puzzle);
            for(State neighbor_state: neighbor_states){
                puzzle_counter++;
                open.push(Puzzle(neighbor_state, current_puzzle_pointer, current_puzzle.depth + 1, h, puzzle_counter));
            }
        }
    }

    return Solution();
}


