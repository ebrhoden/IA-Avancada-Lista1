#include "puzzle.hpp"
#include "heuristic_calculator.hpp"

Puzzle::Puzzle(State state, long long id) {
    this->state = state;
    this->parent_puzzle = nullptr;
    this->depth = 0;
    this->heuristic_value = 0;
    this->id = id;
}

Puzzle::Puzzle(State state, Puzzle* parent_puzzle, int depth, long long id) {
    this->state = state;
    this->parent_puzzle = parent_puzzle;
    this->depth = depth;
    this->heuristic_value = 0;
    this->id = id;
}

Puzzle::Puzzle(State state, HeuristicCalculator &heuristic_calculator, long long id) {
    this->state = state;
    this->parent_puzzle = nullptr;
    this->depth = 0;
    this->heuristic_value = heuristic_calculator.calculate(state);
    this->id = id;
}

Puzzle::Puzzle(State state, Puzzle* parent_puzzle, int depth, HeuristicCalculator &heuristic_calculator, long long id) {
    this->state = state;
    this->parent_puzzle = parent_puzzle;
    this->depth = depth;
    this->heuristic_value = heuristic_calculator.calculate(state);
    this->id = id;
}

bool Puzzle::is_parent_state_null() {
    return this->parent_puzzle == nullptr;
}

bool Puzzle::is_given_state_equal_to_parent_state(State state) {
    if (is_parent_state_null()) {
        return false;
    }

    /*
    cout << "***************************" << endl;
    cout << "I am: ";
    for(int w : this->state.tiles){
        cout << w << " ";
    }
    cout << endl;

    cout << "Parent tiles: ";
    for(int x : this->parent_state.tiles){
        cout << x << " ";
    }
    cout << endl;

    cout<< "Given tiles: ";
    for(int z : state.tiles){
        cout << z << " ";
    }
    cout << endl;
    cout << "***************************" << endl << endl;
    */

    return this->parent_puzzle->state.internal_representation == state.internal_representation;
}

vector<State> Puzzle::get_neighbor_states() {
    vector<State> neighbors;
    neighbors.reserve(4);

    if (this->state.can_move_blank_up()) {
        State generated_state = this->state.move_blank_up();
        if (!(this->is_given_state_equal_to_parent_state(generated_state))) {
            neighbors.push_back(generated_state);
        }
    }

    if (this->state.can_move_blank_left()) {
        State generated_state = this->state.move_blank_left();
        if (!(this->is_given_state_equal_to_parent_state(generated_state))) {
            neighbors.push_back(generated_state);
        }
    }

    if (this->state.can_move_blank_right()) {
        State generated_state = this->state.move_blank_right();
        if (!(this->is_given_state_equal_to_parent_state(generated_state))) {
            neighbors.push_back(generated_state);
        }
    }

    if (this->state.can_move_blank_down()) {
        State generated_state = this->state.move_blank_down();
        if (!(this->is_given_state_equal_to_parent_state(generated_state))) {
            neighbors.push_back(generated_state);
        }
    }

    return neighbors;
}

void Puzzle::print() {
    cout << "Depth: " << this->depth << endl;
    cout << "Previous action: " << this->state.previous_action << endl;
    cout << "Heuristic value: " << this->heuristic_value << endl;
    int n = sqrt(this->state.tiles.size());
    cout << "Imprimindo o board:" << endl;
    for (int i = 0; i < state.tiles.size(); i++) {
        if ((i != 0) && (i % n == 0)) {
            cout << "|" << endl;
            cout << " --- --- ---" << endl;
        }
        cout << "| " << state.tiles[i] << " ";
    }
    cout << "|" << endl;
    cout << " --- --- ---" << endl;
}















