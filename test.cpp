#include "generator.h"
#include "utils.h"
#include <iostream>


int main(){
    // create a grid of 2 in channels, 4 out channels, 3x3
    generator grid(2, 4 ,3, 3);
    grid.generate(10, 0);
    grid.printGrid();

    // process grid
    utils util(grid.getGrid());
    int numChannels = grid.numInChannels();

    // testing sliding kernel
    for(unsigned int i = 0; i < numChannels; i++){
        std::cout << "Channel " << i << " windows" << std::endl;
        util.slidingWindow(2, 2, 1, i);
    }
    


    return 0;
}