#include "generator.h"
#include "utils.h"
#include <iostream>


int main(){
    // create a grid of 1 in channels, 10 out channels, 18x18 grid
    generator grid(1, 10 ,28, 28);

    grid.generateGrid(2, -2);
    grid.setKernelSize(4, 4);
    grid.generateWeight(2, -2);
    grid.printGrid();
    grid.printWeight();


    utils util(grid, 1);

    generator::GRID newgrid = util.conv2d();
    
    return 0;
}