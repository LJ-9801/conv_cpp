#include "generator.h"
#include "utils.h"
#include <iostream>


int main(){
    // create a grid of 2 in channels, 4 out channels, 5x5
    generator grid(10, 3 ,5, 5);

    grid.generateGrid(2, -2);
    grid.setKernelSize(3, 3);
    grid.generateWeight(2, -2);
    grid.printGrid();
    grid.printWeight();


    utils util(grid, 1);
    //util.conv2d();
    
    


    return 0;
}