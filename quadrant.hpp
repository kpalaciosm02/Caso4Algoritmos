#include <bits/stdc++.h>
#include "range.hpp"

using namespace std;

#ifndef QUADRANTM
#define QUADRANTM

class Quadrant {

private:
    pair<int, int> downLeft;
    pair<int, int> upRight;
    vector<Range*> ranges;

public:
    Quadrant(pair<int, int> downLeft, pair<int, int> upRight){
        this->downLeft = downLeft;
        this->upRight = upRight;
    }

    pair<int, int> getDownLeft(){
        return this->downLeft;
    }
    pair<int, int> getUpRight(){
        return this->upRight;
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
        cout<<"El color predominante es: "<< ranges[index]->getRed()<<", "<<ranges[index]->getGreen()<<", "<<ranges[index]->getBlue()<<endl;
    }

    void getRanges() {
        for (Range* range : ranges) {
            cout << "Red: " << range->getRed() << " Green: " << range->getGreen() << " Blue: " << range->getBlue() << " Number of appearances: " << range->getNumberOfAppearances() << endl;
        }
    }
    void print(){
        cout << "DownLeftX:" << downLeft.first << " DownLeftY:" << downLeft.second << " UpRightX:" << upRight.first << " UpRightY:" << upRight.second << endl;
    }
};

#endif