#include "generator.h"
#include "utils.h"
#include <iostream>


int main(){
    generator grid(2, 3, 3);
    grid.generate(10, 0);
    grid.printGrid();

    utils util(grid.getGrid());
    int numChannels = grid.numChannels();
    for(unsigned int i = 0; i < numChannels; i++){
        std::cout << "Channel " << i << " windows" << std::endl;
        util.slidingWindow(2, 2, 1, i);
    }
    


    return 0;
}