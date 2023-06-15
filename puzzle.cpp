#include "puzzle.hpp"
#include "heuristic_calculator.hpp"

Puzzle::Puzzle(State state, int id) {
    this->state = state;
    this->parent_state = State();
    this->depth = 0;
    this->heuristic_value = 0;
    this->id = id;
}

Puzzle::Puzzle(State state, State parent_state, int depth, int id) {
    this->state = state;
    this->parent_state = parent_state;
    this->depth = depth;
    this->heuristic_value = 0;
    this->id = id;
}

Puzzle::Puzzle(State state, HeuristicCalculator &heuristicCalculator, int id) {
    this->state = state;
    this->parent_state = State();
    this->depth = 0;
    this->heuristic_value = heuristicCalculator.calculate(state.tiles);
    this->id = id;
}

Puzzle::Puzzle(State state, State parent_state, int depth, HeuristicCalculator &heuristicCalculator, int id) {
    this->state = state;
    this->parent_state = parent_state;
    this->depth = depth;
    this->heuristic_value = heuristicCalculator.calculate(state.tiles);
    this->id = id;
}

State Puzzle::move_blank_up(int blank_position, int n){
    vector<int> q = this->state.tiles;

    //blank tile receives the value of the tile in the line above
    q[blank_position] = this->state.tiles[blank_position - n];
    //tile from the line above is now blank
    q[blank_position - n] = 0;

    State s(q, UP);
    return s;

}

State Puzzle::move_blank_left(int blank_position){
    vector<int> q = this->state.tiles;

    //blank tile receives the value of the tile to its left
    q[blank_position] = this->state.tiles[blank_position - 1];
    //tile from the line above is now blank
    q[blank_position - 1] = 0;

    State s(q, LEFT);
    return s;
}

State Puzzle::move_blank_right(int blank_position){
    vector<int> q = this->state.tiles;

    //blank tile  receives the value of the tile in the line below
    q[blank_position] = this->state.tiles[blank_position + 1];
    //tile from the line above is now blank
    q[blank_position + 1] = 0;

    State s(q, RIGHT);
    return s;
}

State Puzzle::move_blank_down(int blank_position, int n){
    vector<int> q = this->state.tiles;

    //blank tile receives the value of the tile in the line above
    q[blank_position] = this->state.tiles[blank_position + n];
    //tile from the line above is now blank
    q[blank_position + n] = 0;

    State s(q, DOWN);
    return s;
}

bool Puzzle::is_parent_state_null(){
    return this->parent_state.tiles.empty();
}

bool Puzzle::is_given_state_equal_to_parent_state(State state){
    if(is_parent_state_null()){
        //cout << "Adding all the kids" << endl;
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

    return this->parent_state.tiles == state.tiles;
}

vector<State> Puzzle::get_neighbor_states(){
    vector<State> neighbors;
    int n = (int) sqrt(this->state.tiles.size());
    int blank_position = this->state.get_blank_position(n);

    if(this->state.can_move_blank_up(blank_position, n)){
        State generated_state = move_blank_up(blank_position, n);
        if(!(this->is_given_state_equal_to_parent_state(generated_state))){
            neighbors.push_back(generated_state);
        }
    }

    if(this->state.can_move_blank_left(blank_position, n)){
        State generated_state = move_blank_left(blank_position);
        if(!(this->is_given_state_equal_to_parent_state(generated_state))){
            neighbors.push_back(generated_state);
        }
    }

    if(this->state.can_move_blank_right(blank_position, n)){
        State generated_state = move_blank_right(blank_position);
        if(!(this->is_given_state_equal_to_parent_state(generated_state))){
            neighbors.push_back(generated_state);
        }
    }

    if(this->state.can_move_blank_down(blank_position, n)){
        State generated_state = move_blank_down(blank_position, n);
        if(!(this->is_given_state_equal_to_parent_state(generated_state))){
            neighbors.push_back(generated_state);
        }
    }

    return neighbors;

}

void Puzzle::print(){
    cout << "Depth: " << this->depth << endl;
    cout << "Previous action: " << this->state.previous_action << endl;
    cout << "Heuristic value: " << this->heuristic_value << endl;
    int n = sqrt(this->state.tiles.size());
    cout << "Imprimindo o board:" << endl;
    for(int i = 0; i < state.tiles.size(); i++){
        if((i != 0) && (i % n == 0)){
            cout << "|" << endl;
            cout << " --- --- ---" << endl;
        }
        cout << "| " << state.tiles[i] << " ";
    }
    cout << "|" << endl;
    cout << " --- --- ---" << endl;



}















