#include "generator.h"
#include <iostream>
//#include <omp.h>

void generator::generateWeight(int upper, int lower){
    // Generate the weight
    srand(time(0));

    int kh = kernal_size_.first;
    int kw = kernal_size_.second;

    for (int i = 0; i < out_channels_; i++){
        std::vector<std::vector<std::vector<float> > > channel;
        for (int j = 0; j < in_channels_; j++){
            std::vector<std::vector<float> > row;
            for (int k = 0; k < kh; k++){
                std::vector<float> col;
                for (int l = 0; l < kw; l++){
                    col.push_back(randomFloat(upper, lower));
                }
                row.push_back(col);
            }
            channel.push_back(row);
        }
        weight_.push_back(channel);
    }
}

void generator::generateGrid(int upper, int lower){
    // Generate the grid
    srand(time(0));

    for (int i = 0; i < in_channels_; i++){
        std::vector<std::vector<float> > channel;
        for (int j = 0; j < width_; j++){
            std::vector<float> row;
            for (int k = 0; k < height_; k++){
                row.push_back(randomFloat(upper, lower));
            }
            channel.push_back(row);
        }
        grid_.push_back(channel);
    }
}

void generator::printGrid(){
    for (int i = 0; i < in_channels_; i++){
        std::cout << "Channel " << i << std::endl;
        for (int j = 0; j < width_; j++){
            std::cout << "[";
            for (int k = 0; k < height_; k++){
                std::cout << grid_[i][j][k] << " ";
            }
            std::cout << "]\n";
        }
        std::cout << "\n";
    }


}


float generator::randomFloat(int upper, int lower){
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = upper - lower;
    float r = random * diff;
    return lower + r;
}
