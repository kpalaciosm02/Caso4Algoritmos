#include <bits/stdc++.h>
#include <iostream>
#include "color.hpp"

//using namespace std;

#ifndef PIXELM
#define PIXELM

class Pixel {

private:
    std::pair<float, float> coords;
    Color pixelGrayTone;

public:
    Pixel(){
        this->coords = std::make_pair(0,0);
        this->pixelGrayTone = Color(0,0,0,255);
    }

    Pixel(std::pair<int, int> _coords){
        this->coords = _coords;
        this->pixelGrayTone = Color(0,0,0,255);
    }

    std::pair<int, int> getCoords(){
        return this->coords;
    }

    Color getGray(){
        return this->pixelGrayTone;
    }

    void setCoords(std::pair<int, int> _coords){
        this->coords = _coords;
    }

    void setGray(Color gray){
        this->pixelGrayTone = gray;
    }
    void print(){
        std::cout << "X:" << coords.first << " Y:" << coords.second << std::endl;
    }

};

#endif