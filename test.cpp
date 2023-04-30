#include "generator.h"
#include "utils.h"
#include <iostream>


int main(){
    // create a grid of 1 in channels, 10 out channels, 18x18 grid
    generator grid(3, 64 ,28, 28);

    grid.generateGrid(2, -2);
    grid.setKernelSize(4, 4);
    grid.generateWeight(2, -2);
    grid.printGrid();
    grid.printWeight();

    // set stride 1
    utils util(grid, 4);
    util.conv2d();

    /*
    for(unsigned int i = 0; i<10000; i++){
        util.conv2d();
    }
    */
    return 0;
}