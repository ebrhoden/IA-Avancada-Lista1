#ifndef STATE_HPP_INCLUDED
#define STATE_HPP_INCLUDED
#include "vector"
#include <algorithm>
#include <math.h>

using namespace std;

enum Action {
    UP,
    LEFT,
    RIGHT,
    DOWN,
    NONE,
};

class State{
    public:
        vector<int> tiles;
        Action previous_action;
        unsigned long long internal_representation;
        int blank_position;
        int board_size; // 9 or 16
        int board_dimension; // 3 or 4 (n x n board)

        State();

        State(vector<int> &user_input, Action a = NONE);

        unsigned long long generate_internal_representation();

        bool is_goal();

        int get_blank_position();

        bool can_move_blank_up();
        bool can_move_blank_left();
        bool can_move_blank_right();
        bool can_move_blank_down();

        State move_blank_up();
        State move_blank_left();
        State move_blank_right();
        State move_blank_down();

};

#endif // STATE_HPP_INCLUDED
