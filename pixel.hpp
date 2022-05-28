#include <bits/stdc++.h>
#include <iostream>
#include "color.hpp"

using namespace std;

#ifndef PIXELM
#define PIXELM

class Pixel {

private:
    pair<float, float> coords;
    Color pixelGrayTone;

public:
    Pixel(){
        this->coords = make_pair(0,0);
        this->pixelGrayTone = Color(0,0,0,255);
    }

    Pixel(pair<float, float> _coords){
        this->coords = _coords;
        this->pixelGrayTone = Color(0,0,0,255);
    }

    pair<float, float> getCoords(){
        return this->coords;
    }

    Color getGray(){
        return this->pixelGrayTone;
    }

    void setCoords(pair<float, float> _coords){
        this->coords = _coords;
    }

    void setGray(Color gray){
        this->pixelGrayTone = gray;
    }
    void print(){
        std::cout << "X:" << coords.first << " Y:" << coords.second << endl;
    }

};

#endif