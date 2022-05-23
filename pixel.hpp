#include <bits/stdc++.h>

using namespace std;

class Pixel {

private:
    pair<int, int> coords;
    string greyTone;
    float bounderyDistance;
    float boundery;
    float distancePercentage;

public:
    Pixel(pair<int, int> coords, string greyTone, float bounderyDistance, float boundery, float distancePercentage){
        this->coords = coords;
        this->greyTone = greyTone;
        this->bounderyDistance = bounderyDistance;
        this->boundery = boundery;
        this->distancePercentage = distancePercentage;
    }

    pair<int, int> getCoords(){
        return this->coords;
    }

    string getGreyTone(){
        return this->greyTone;
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

    void setGreyTone(float _greyTone){
            this->greyTone = _greyTone;
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
};