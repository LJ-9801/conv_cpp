#include <iostream>
#include "generator.h"
#include "utils.h"

utils::WINDOW utils::kernel(const int& height, const int& width, LOCATION loc, const int& channel){
    WINDOW window(height, std::vector<float>(width, 0));
    int x_start = loc.first;
    int y_start = loc.second;

    if (x_start + height > grid_[channel].size() || y_start + width > grid_[channel][0].size()){
        std::cout << "Error: window out of bounds\n";
        return window;
    }

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            window[i][j] = grid_[channel][x_start + i][y_start + j];
        }
    }

    return window;
}

void utils::slidingWindow(const int& height, const int& width, const int& stride, const int& channel){
    int x_start = 0;
    int y_start = 0;
    int x_end = x_start + height;
    int y_end = y_start + width;

    while (x_end <= grid_[channel].size()){
        while (y_end <= grid_[channel][0].size()){
            WINDOW window = kernel(height, width, std::make_pair(x_start, y_start), channel);
            printWindow(window);
            std::cout << "\n";
            y_start += stride;
            y_end += stride;
        }
        x_start += stride;
        x_end += stride;
        y_start = 0;
        y_end = y_start + width;
    }
}

generator::GRID utils::conv2d(){
    // Convolution
    int out_height = (grid_[0].size() - kh_) / stride_ + 1;
    int out_width = (grid_[0][0].size() - kw_) / stride_ + 1;
    int out_channels = out_channels_;
    int in_channels = in_channels_;
    int kernal_height = kh_;
    int kernal_width = kw_;

    generator::GRID output(std::vector<std::vector<std::vector<float> > >(out_channels, std::vector<std::vector<float> >(out_height, std::vector<float>(out_width, 0))));
    for (int i = 0; i < out_channels; i++){
        for (int j = 0; j < out_height; j++){
            for (int k = 0; k < out_width; k++){
                for (int l = 0; l < in_channels; l++){
                    WINDOW window = kernel(kernal_height, kernal_width, std::make_pair(j, k), l);
                    for (int m = 0; m < kernal_height; m++){
                        for (int n = 0; n < kernal_width; n++){
                            std::cout << "output[" << i << "][" << j << "][" << k << "] += window[" << m << "][" << n << "] * weight_[" << i << "][" << l << "][" << m << "][" << n << "]\n";
                            output[i][j][k] += window[m][n] * weight_[i][l][m][n];
                        }
                    }
                }
            }
        }
    }

    return output;
}


const void utils::printWindow(WINDOW window) const{
    for (int i = 0; i < window.size(); i++){
        std::cout << "[";
        for (int j = 0; j < window[i].size(); j++){
            std::cout << window[i][j] << " ";
        }
        std::cout << "]\n";
    }
}