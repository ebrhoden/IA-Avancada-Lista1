#include "solution.hpp";

#include <iostream>
#include <string>
#include <vector>
#include "puzzle.hpp"
#include "bfs.hpp"
#include "gbfs.hpp"
#include "a_star.hpp"

using namespace std;

vector<vector<int>> get_inputed_arrays(int size_of_array, int argc, char *argv[]){
    int i = 2;
    string aux_string;

    vector<vector<int>> resulting_arrays;
    while(i < argc){
        vector<int> aux_array;
        for(int j = 0; j <= size_of_array; j++){
            aux_string = argv[i];
            aux_array.push_back(stoi(aux_string));
            i++;
        }
        resulting_arrays.push_back(aux_array);
    }

    return resulting_arrays;
}


int main(int argc, char *argv[]){
    static unsigned int node_counter = 0;
    string algorithm = "-bfs";
    vector<vector<int>> inputed_arrays;

    if(argc > 10){
        string aux_string;

        algorithm = argv[1];

        /*
        Could be:
        a) A single 16 puzzle
        b) Multiple 8 puzzles
        c) Multiple 16 puzzles
        */
        if(argc > 17){
            aux_string = argv[18];
            if (aux_string.find(',') != string::npos) {
                //MULTIPLE 16 arrays
                inputed_arrays = get_inputed_arrays(16, argc, argv);
            } else {
                aux_string = argv[10];
                if (aux_string.find(',') != string::npos){
                    //MULTIPLE 8 arrays
                    inputed_arrays = get_inputed_arrays(8, argc, argv);
                }
            }
        }

        // Can only be a singular 8 or 16 puzzle
        if(inputed_arrays.empty()){
            vector<int> aux_array;
            for(int i = 2; i < argc; i++){
                aux_array.push_back(stoi(argv[i]));
            }
            inputed_arrays.push_back(aux_array);
        }

        cout << "Algorithm: " << algorithm << endl;
        for(vector<int> inputed_array : inputed_arrays){
            if(algorithm == "-bfs"){
                Solution s = solve_bfs(inputed_array);
                s.print();
            } else if(algorithm == "-gbfs"){
                Solution s = solve_gbfs(inputed_array, HeuristicCalculator());
                s.print();
            } else if(algorithm == "-astar"){
                Solution s = solve_a_star(inputed_array, HeuristicCalculator());
                s.print();
            }
        }
    } else {
        vector<int> v1 {0,6,1,7,4,2,3,8,5};
        vector<int> v2 {6,0,1,7,4,2,3,8,5};
        vector<int> v3 {6,4,1,7,0,2,3,8,5};

        Puzzle p1(v1);
        Puzzle p2(v2, p1.state, 88);
        vector<State> states = p2.get_neighbor_states();
        for(State s : states){
            for(int i : s.tiles){
                cout << i << " ";
            }
            cout << endl;
        }


    }
    return 1;
}
