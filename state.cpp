#include "state.hpp"
#include "iostream";

State::State(){};

State::State(vector<int> user_input, Action a){
    this->tiles = user_input;
    this->previous_action = a;
    this->internal_representation = generate_internal_representation();
    this->board_size = user_input.size();
    this->board_dimension = (int) sqrt(user_input.size());
    this->blank_position = this->get_blank_position();
}

unsigned long long State::generate_internal_representation(){
    unsigned long long result = 0;

    for(int element : this->tiles){
        result = result * 10 + element;
    }
    return result;

}

bool State::is_goal(){
    return this->internal_representation == 12345678;
}

int State::get_blank_position(){
    for(int i = 0; i < this->board_size; i++){
        if(this->tiles[i] == 0){
            return i;
        }
    }
}

bool State::can_move_blank_up(){
    return this->blank_position >= this->board_dimension;
}

bool State::can_move_blank_left(){
    for(int i = 0; i < this->board_size; i = i + this->board_dimension){
        if(this->blank_position == i){
            return false;
        }
    }
    return true;
}

bool State::can_move_blank_right(){
    for(int i = this->board_size - 1; i > 0; i = i - this->board_dimension){
        if(blank_position == i){
            return false;
        }
    }
    return true;
}

bool State::can_move_blank_down(){
    return blank_position <= (this->board_size - 1) - this->board_dimension;
}

State State::move_blank_up(){
    vector<int> q = this->tiles;

    //blank tile receives the value of the tile in the line above
    q[this->blank_position] = this->tiles[this->blank_position - this->board_dimension];
    //tile from the line above is now blank
    q[this->blank_position - this->board_dimension] = 0;

    State s(q, UP);
    return s;

}

State State::move_blank_left(){
    vector<int> q = this->tiles;

    //blank tile receives the value of the tile to its left
    q[this->blank_position] = this->tiles[this->blank_position - 1];
    //tile from the line above is now blank
    q[this->blank_position - 1] = 0;

    State s(q, LEFT);
    return s;
}

State State::move_blank_right(){
    vector<int> q = this->tiles;

    //blank tile  receives the value of the tile in the line below
    q[this->blank_position] = this->tiles[this->blank_position + 1];
    //tile from the line above is now blank
    q[this->blank_position + 1] = 0;

    State s(q, RIGHT);
    return s;
}

State State::move_blank_down(){
    vector<int> q = this->tiles;

    //blank tile receives the value of the tile in the line above
    q[this->blank_position] = this->tiles[this->blank_position + this->board_dimension];
    //tile from the line above is now blank
    q[this->blank_position + this->board_dimension] = 0;

    State s(q, DOWN);
    return s;
}

