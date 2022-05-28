#include <bits/stdc++.h>
#include <iostream>
#include "color.hpp"

using namespace std;

#ifndef PIXELM
#define PIXELM

class Pixel {

private:
    pair<float, float> coords;
<<<<<<< HEAD
=======
    float distanceBoundery;
    Color pixelGrayTone;
>>>>>>> Kenneth

public:
    Pixel(){
        this->coords = make_pair(0,0);
<<<<<<< HEAD
=======
        this->distanceBoundery = 0;
        this->pixelGrayTone = Color(0,0,0,255);
>>>>>>> Kenneth
    }

    Pixel(pair<int, int> _coords, float _distanceBoundery){
        this->coords = _coords;
<<<<<<< HEAD
=======
        this->distanceBoundery = _distanceBoundery;
        this->pixelGrayTone = Color(0,0,0,255);
>>>>>>> Kenneth
    }

    pair<int, int> getCoords(){
        return this->coords;
    }

<<<<<<< HEAD
=======
    float getDistanceBoundery(){
        return this->distanceBoundery;
    }

    Color getGray(){
        return this->pixelGrayTone;
    }

>>>>>>> Kenneth
    void setCoords(pair<int, int> _coords){
        this->coords = _coords;
    }

<<<<<<< HEAD
=======
    void setDistanceBoundery(float _distanceBoundery){
        this->distanceBoundery = _distanceBoundery;
    }
    void setGray(Color gray){
        this->pixelGrayTone = gray;
    }
>>>>>>> Kenneth
    void print(){
        std::cout << "X:" << coords.first << " Y:" << coords.second << endl;
    }

};

#endif