#ifndef _generator_h_
#define _generator_h_

#include <vector>
#include <utility>

class generator {
    public:
        // Grid Type
        typedef std::vector<std::vector<std::vector<float> > > GRID;
        typedef std::pair<int, int> KERNAL_SIZE;
        typedef std::vector<std::vector<std::vector<std::vector<float> > > > WEIGHT;

        generator(const int Inchannels, const int OutChannels, 
                  const int width,const int height): in_channels_(Inchannels), out_channels_(OutChannels),
                                                     width_(width), height_(height) {};
        
        void generateGrid(int upper, int lower); // you can generate a grid with a range of random values
        void generateWeight(int upper, int lower); // you can generate a weight with a range of random values

        // Getters
        const GRID getGrid() const {return grid_;}
        const WEIGHT getWeight() const {return weight_;}
        const int numInChannels() const {return in_channels_;}
        const int numOutChannels() const {return in_channels_;}
        const int height() const {return height_;}
        const int width() const {return width_;}

        // Printer
        void printGrid();
        void printWeight();
        
    private:
        float randomFloat(int upper, int lower);
        GRID grid_;
        WEIGHT weight_;
        int in_channels_;
        int out_channels_;
        KERNAL_SIZE kernal_size_;
        int width_;
        int height_;
        
};
#endif