#include "heuristic_calculator.hpp"

using namespace std;

HeuristicCalculator::HeuristicCalculator() {
    this->called_count = 0;
    this->accumulator = 0;
}

int HeuristicCalculator::calculate(const State &state){
    int sum = 0;
    int n = state.tiles.size();
    int dim = (int)sqrt(n);
    /*

    int aux = 0;
    vector<vector<int>> matrix;
    vector<int> aux_array;
    for(int i = 0; i < n; i++){
        aux_array.push_back(tiles[i]);
        if(aux == dim - 1){
            matrix.push_back(aux_array);
            aux_array.clear();
            aux = 0;
        } else{
            aux++;
        }

    }

    for (int x = 0; x < dim; x++) // x-dimension, traversing rows (i)
        for (int y = 0; y < dim; y++) { // y-dimension, traversing cols (j)
            int value = matrix[x][y]; // tiles array contains board elements
            if (value != 0) { // we don't compute MD for element 0
                int targetX = (value) / dim; // expected x-coordinate (row)
                int targetY = (value) % dim; // expected y-coordinate (col)
                int dx = x - targetX; // x-distance to expected coordinate
                int dy = y - targetY; // y-distance to expected coordinate
                sum += abs(dx) + abs(dy);
            }
    }
    */



    for(int i = 0; i < n; i++){
        //Goal tile placement is ((n-1) div 3, (n-1) mod 3)
        //DO NOT CONSIDER THE BLANK TILE, OTHERWISE THE HEURISTIC IS NOT ADMISSIBLE
        if(state.tiles[i] != 0){
            sum += abs((int)state.tiles[i] / dim - (int)i / dim) + abs(state.tiles[i] % dim - i % dim);
        }
    }


    this->called_count++;
    this->accumulator += sum;

    return sum;

}

double HeuristicCalculator::average_result(){
    if(this->called_count == 0)
        return 0;
    else
        return (double)this->accumulator/this->called_count;
}
