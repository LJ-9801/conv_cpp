#ifndef _utils_h_
#define _utils_h_
#include "generator.h"
#include <vector>
#include <utility>

class utils{

    public:
        typedef std::vector<std::vector<float> > WINDOW;
        typedef std::pair<int, int> LOCATION;

        utils(generator grid): grid_(grid.getGrid()) {};


        void slidingWindow(const int& height, const int& width, const int& stride, const int& channel);
        
        

    private:
        WINDOW kernel(const int& height, const int& width, LOCATION loc, const int& channel);
        const void printWindow(WINDOW window) const;

        generator::GRID grid_;
        int kh_;
        int kw_;
        int stride_;
        int in_channels_;
        int out_channels_;

};
#endif