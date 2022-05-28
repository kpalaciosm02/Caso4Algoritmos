#include <bits/stdc++.h>
#include <iostream>
#include "color.hpp"

using namespace std;

#ifndef PIXELM
#define PIXELM

class Pixel {

private:
    pair<float, float> coords;
    float distanceBoundery;
    Color pixelGrayTone;

public:
    Pixel(){
        this->coords = make_pair(0,0);
        this->distanceBoundery = 0;
        this->pixelGrayTone = Color(0,0,0,255);
    }

    Pixel(pair<int, int> _coords, float _distanceBoundery){
        this->coords = _coords;
        this->distanceBoundery = _distanceBoundery;
        this->pixelGrayTone = Color(0,0,0,255);
    }

    pair<int, int> getCoords(){
        return this->coords;
    }

    float getDistanceBoundery(){
        return this->distanceBoundery;
    }

    Color getGray(){
        return this->pixelGrayTone;
    }

    void setCoords(pair<int, int> _coords){
        this->coords = _coords;
    }

    void setDistanceBoundery(float _distanceBoundery){
        this->distanceBoundery = _distanceBoundery;
    }
    void setGray(Color gray){
        this->pixelGrayTone = gray;
    }
    void print(){
        std::cout << "X:" << coords.first << " Y:" << coords.second << " Distancia al borde:" << distanceBoundery << endl;
    }

};

#endif