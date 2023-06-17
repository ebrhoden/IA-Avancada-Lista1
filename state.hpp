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

        State();

        State(vector<int> user_input, Action a = NONE);

        unsigned long long generate_internal_representation();

        bool is_goal();

        int get_blank_position(int n);

        bool can_move_blank_up(int blank_position, int n);
        bool can_move_blank_left(int blank_position, int n);
        bool can_move_blank_right(int blank_position, int n);
        bool can_move_blank_down(int blank_position, int n);

};

#endif // STATE_HPP_INCLUDED
