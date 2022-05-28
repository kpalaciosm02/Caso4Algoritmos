#include <bits/stdc++.h>
#include "range.hpp"
#include "pixel.hpp"

//using namespace std;

#ifndef QUADRANTM
#define QUADRANTM

class Quadrant {

private:
    std::pair<int, int> downLeft;
    std::pair<int, int> upRight;
    std::vector<Range*> ranges;
    std::vector<Pixel> pixelRandomList;
    float densityPixels;

public:
    Quadrant(){
    }
    Quadrant(std::pair<int, int> downLeft, std::pair<int, int> upRight){
        this->downLeft = downLeft;
        this->upRight = upRight;
    }

    std::pair<int, int> getDownLeft(){
        return this->downLeft;
    }
    std::pair<int, int> getUpRight(){
        return this->upRight;
    }

    std::vector<Pixel> getPixelRandomList(){
        return this->pixelRandomList;
    }

    void setPixelRan(Pixel pixelRandom){
        this->pixelRandomList.push_back(pixelRandom);
    }

    float getDensityPixels(){
        return this->densityPixels;
    }

    void setDensityPixels(float _densityPixels){
        this->densityPixels = _densityPixels;
    }

    void verifyRange(int red, int green, int blue) {
        for (Range* range : ranges) {
            if (range->isInRange(red, green, blue)) {
                range->incrementNumberOfAppearances();
                return;
            }
        }
        Range* newRange = new Range(red, green, blue);
        ranges.push_back(newRange);
    }

    void getPredominantColorRange(){
        int maxAppearances = 0;
        int index = 0;
        for (int i = 0; i < ranges.size(); i++) {
            if (ranges[i]->getNumberOfAppearances() > maxAppearances) {
                maxAppearances = ranges[i]->getNumberOfAppearances();
                index = i;
            }
        }
        std::cout<<"El color predominante es: "<< ranges[index]->getRed()<<", "<<ranges[index]->getGreen()<<", "<<ranges[index]->getBlue()<< std::endl;
    }

    void getRanges() {
        for (Range* range : ranges) {
            std::cout << "Red: " << range->getRed() << " Green: " << range->getGreen() << " Blue: " << range->getBlue() << " Number of appearances: " << range->getNumberOfAppearances() << std::endl;
        }
    }
    void print(){
        std::cout << "DownLeftX:" << downLeft.first << " DownLeftY:" << downLeft.second << " UpRightX:" << upRight.first << " UpRightY:" << upRight.second << std::endl;
    }
};

#endif