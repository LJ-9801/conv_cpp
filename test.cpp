#include "generator.h"
#include "utils.h"
#include <iostream>


int main(){
    // create a grid of 2 in channels, 4 out channels, 3x3
    generator grid(10, 3 ,5, 5);

    grid.generateGrid(10, 0);
    grid.generateWeight(10, 0);
    grid.printGrid();
    // process grid
    //utils util(grid.getGrid());
    //int numChannels = grid.numInChannels();
    


    return 0;
}