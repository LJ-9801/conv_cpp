#ifndef _utils_h_
#define _utils_h_
#include "generator.h"
#include <vector>
#include <utility>

class utils{

    public:
        typedef std::vector<std::vector<float> > WINDOW;
        typedef std::pair<int, int> LOCATION;

        utils(generator grid, int stride): grid_(grid.getGrid()),
                               in_channels_(grid.numInChannels()), out_channels_(grid.numOutChannels()),
                               kh_(grid.kernalHeight()), kw_(grid.kernalWidth()),
                               weight_(grid.getWeight()), stride_(stride) {};


        void slidingWindow(const int& height, const int& width, const int& stride, const int& channel);
        WINDOW kernel(const int& height, const int& width, LOCATION loc, const int& channel);
        const void printWindow(WINDOW window) const;

        //Convolution
        generator::GRID conv2d();

    private:
       

        generator::GRID grid_;
        generator::WEIGHT weight_;
        int kh_;
        int kw_;
        int stride_;
        int in_channels_;
        int out_channels_;

};
#endif