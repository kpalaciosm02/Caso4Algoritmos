#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#ifndef PIXELM
#define PIXELM

class Pixel {

private:
    pair<float, float> coords;

public:
    Pixel(){
        this->coords = make_pair(0,0);
    }

    Pixel(pair<int, int> _coords, float _distanceBoundery){
        this->coords = _coords;
    }

    pair<int, int> getCoords(){
        return this->coords;
    }

    void setCoords(pair<int, int> _coords){
        this->coords = _coords;
    }

    void print(){
        std::cout << "X:" << coords.first << " Y:" << coords.second << endl;
    }

};

#endif