#include "quadrant.hpp"
#include <vector>
using namespace std;
//int xBorderSize = 150;
//int yBorderSize = 0;                                //borders from where the image will be processed (quadrant 2)

vector<Quadrant> generate_quadrants(int xBorderSize, int yBorderSize){
    int newImageWidth = 1080 - xBorderSize - xBorderSize;       //image size after taking the 2 exterior columns apart
    int newImageHeight = 1080 - yBorderSize - yBorderSize;

    int xQuadrantSize = newImageWidth / 6;                      //divided by the amount of columns
    int yQuadrantSize = newImageHeight / 6;                     //divided by the amount of rows

    int actualX = 0 + xBorderSize;                              //coordinates where the quadrants will start, also used to iterate through each quadrant creation
    int actualY = 0 + yBorderSize;

    int xBorder = newImageWidth + xBorderSize;                  //max coordinates where a quadrant can be
    int yBorder = newImageHeight + yBorderSize;

    vector<Quadrant> quadrants = {};
    
    while (actualX <= (xBorder-xQuadrantSize)){
        //cout << "ActualX:" << actualX << " xBorder-size:" << xBorder-xBorderSize << endl;
        int secondX = actualX + xQuadrantSize;
        while(actualY <= (yBorder-yBorderSize-yQuadrantSize)){
            int secondY = actualY + yQuadrantSize;
            pair<int,int> coord1 = make_pair(actualX,actualY);
            pair<int,int> coord2 = make_pair(secondX,secondY);
            Quadrant newQuadrant(coord1,coord2);
            //newQuadrant.print();
            quadrants.push_back(newQuadrant);
            actualY = secondY;
        }
        actualY = 0 + yBorderSize;
        actualX = secondX;
        //cout << actualX << endl;
    }
    return quadrants;
}