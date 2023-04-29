#include "generator.h"
#include <iostream>
#include <iomanip>
#include <omp.h>

void generator::generateWeight(int upper, int lower){
    // Generate the weight
    srand(time(0));

    int kh = kernal_size_.first;
    int kw = kernal_size_.second;

    #pragma omp parallel for shared(weight_)
    for (int i = 0; i < out_channels_; i++){
        std::vector<std::vector<std::vector<float> > > channel;
        for (int j = 0; j < in_channels_; j++){
            std::vector<std::vector<float> > row;
            for (int k = 0; k < kh; k++){
                std::vector<float> col;
                for (int l = 0; l < kw; l++){
                    col.push_back(randomFloat(upper, lower));
                }
                #pragma omp critical
                row.push_back(col);
            }
            #pragma omp critical
            channel.push_back(row);
        }
        #pragma omp critical
        weight_.push_back(channel);
    }
}

void generator::generateGrid(int upper, int lower){
    // Generate the grid
    srand(time(0));

    #pragma omp parallel for
    for (int i = 0; i < in_channels_; i++){
        std::vector<std::vector<float> > channel;
        for (int j = 0; j < width_; j++){
            std::vector<float> row;
            for (int k = 0; k < height_; k++){
                row.push_back(randomFloat(upper, lower));
            }
            #pragma omp critical
            channel.push_back(row);
        }
        #pragma omp critical
        grid_.push_back(channel);
    }
    #pragma omp barrier
}

void generator::clearGrid(){
    grid_.clear();
}

void generator::printGrid(){
    if (grid_.size() == 0){
        std::cout << "Grid is empty\n";
        return;
    }

    int front = 3;
    int back = 3;

    if(width_ < 8 || height_ < 8){
        front = width_;
        back = 0;
    }

    for (int i = 0; i < in_channels_; i++){
        std::cout << "Channel " << i << std::endl;
        for (int j = 0; j < front; j++){
            std::cout << "[";
            for (int k = 0; k < front; k++){
                std::cout << grid_[i][j][k] << " ";
            }
            if (back != 0){
                std::cout << "... ";
                for (int k = height_ - back; k < height_; k++){
                    std::cout << grid_[i][j][k] << " ";
                }
            }
            std::cout << "]\n";
        }

        if (back != 0){
            std::cout << std::setw(27) << "..." << std::endl;
            for (int j = width_ - back; j < width_; j++){
                std::cout << "[";
                for (int k = 0; k < front; k++){
                    std::cout << grid_[i][j][k] << " ";
                }
                std::cout << "... ";
                for (int k = height_ - back; k < height_; k++){
                    std::cout << grid_[i][j][k] << " ";
                }
                std::cout << "]\n";
            }
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
