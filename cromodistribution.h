#ifndef _CROMODISTRIBUTION_
#define _CROMODISTRIBUTION_ 1

#include <iostream>

#define CROMO_MAX_VALUE 65535
#define NIBBLE_SIZE 16

using namespace std;

struct cromodistribution {
    float x;
    float y;
    float x1;
    float y1;
    string shape;
    string size;
    int quantityPixels;
};

#endif