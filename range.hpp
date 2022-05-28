#include <bits/stdc++.h>

using namespace std;

#ifndef RANGEMACRO
#define RANGEMACRO

class Range {
protected:
    int NumberOfAppearances;
    int red;
    int green;
    int blue;
    int range;
    friend class Quadrant;
public:
    Range(int red, int green, int blue) {
        this->red = red;
        this->green = green;
        this->blue = blue;
        this->NumberOfAppearances = 1;
        this->range = 25;
    }

    bool isInRange(int red, int green, int blue) {
        if (red >= this->red && red <= this->red + range) {
            if (green >= this->green && green <= this->green + range) {
                if (blue >= this->blue && blue <= this->blue + range) {
                    return true;
                }
            }
        }
        return false;
    }

    int getNumberOfAppearances() {
        return NumberOfAppearances;
    }

    void incrementNumberOfAppearances() {
        NumberOfAppearances++;
    }

    int getRed() {
        return red+range;
    }
    
    int getGreen() {
        return green+range;
    }

    int getBlue() {
        return blue+range;
    }
};
#endif