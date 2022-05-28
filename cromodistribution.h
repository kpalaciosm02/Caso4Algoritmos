#ifndef _CROMODISTRIBUTION_
#define _CROMODISTRIBUTION_ 1

#include <iostream>

#define CROMO_MAX_VALUE 256
#define NIBBLE_SIZE 8

using namespace std;

struct cromodistribution {
    float x;
    float y;
    float x1;
    float x2;
    string greyTone;
    string shape;
    string size;
    int quantity;
    int distribution;
};

#endif