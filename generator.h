#ifndef _generator_h_
#define _generator_h_

#include <vector>

class generator {
    public:
        // Grid Type
        typedef std::vector<std::vector<std::vector<float> > > GRID;

        generator(int channels, int width, int height): channels_(channels), 
                                                        width_(width), 
                                                        height_(height) {};
        
        void generate(int upper, int lower); // you can generate a grid with a range of random values

        // Getters
        const GRID getGrid() const {return grid_;}
        const int numChannels() const {return channels_;}
        const int width() const {return width_;}

        // Printer
        void printGrid();
        
    private:
        float randomFloat(int upper, int lower);
        GRID grid_;
        int channels_;
        int width_;
        int height_;
};
#endif