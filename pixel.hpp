#include <bits/stdc++.h>

//using namespace std;

#ifndef PIXELM
#define PIXELM

class Pixel {

private:
    pair<float, float> coords;
    float bounderyDistance;
    float boundery;
    float distancePercentage;

public:
    Pixel(){
        this->coords = make_pair(0,0);
        this->bounderyDistance = 0;
        this->boundery = 0;
        this->distancePercentage = 0;
    }

    Pixel(pair<int, int> coords, string greyTone, float bounderyDistance, float boundery, float distancePercentage){
        this->coords = coords;
        this->bounderyDistance = bounderyDistance;
        this->boundery = boundery;
        this->distancePercentage = distancePercentage;
    }

    pair<int, int> getCoords(){
        return this->coords;
    }

    float getBounderyDistance(){
        return this->bounderyDistance;
    }

    float getBoundery(){
        return this->boundery;
    }

    float getDistancePercentage(){
        return this->distancePercentage;
    }

    void setCoords(pair<int, int> _coords){
        this->coords = _coords;
    }

    void setBounderyDistance(float _bounderyDistance){
            this->bounderyDistance = _bounderyDistance;
    }

    void setBoundery(float _boundery){
            this-> boundery = _boundery;
    }

    void setDistancePercentage(float _distancePercentage){
            this->distancePercentage = _distancePercentage;
    }

    void print(){
        std::cout << "X:" << coords.first << " Y:" << coords.second << endl;
    }

};

#endif