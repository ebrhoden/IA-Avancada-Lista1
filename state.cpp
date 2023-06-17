#include "state.hpp"
#include "iostream";

State::State(){};

State::State(vector<int> user_input, Action a){
    this->tiles = user_input;
    this->previous_action = a;
    this->internal_representation = generate_internal_representation();
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

int State::get_blank_position(int n){
    for(int i = 0; i < n * n - 1; i++){
        if(this->tiles[i] == 0){
            return i;
        }
    }
}

bool State::can_move_blank_up(int blank_position, int n){
    return blank_position >= n;
}

bool State::can_move_blank_left(int blank_position, int n){
    for(int i = 0; i < n * n - 1; i = i + n){
        if(blank_position == i){
            return false;
        }
    }
    return true;
}

bool State::can_move_blank_right(int blank_position, int n){
    for(int i = n * n - 1; i > 0; i = i - n){
        if(blank_position == i){
            return false;
        }
    }
    return true;
}

bool State::can_move_blank_down(int blank_position, int n){
    //n * n - 1 == board size
    //decrement n to skip the last line
    return blank_position <= (n * n - 1) - n;
}

