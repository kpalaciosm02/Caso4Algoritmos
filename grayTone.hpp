#include "color.hpp"
#include <iostream>
#ifndef GRAYTONE
#define GRAYTONE

class GrayTone{
    private:

    public:
        GrayTone(){
        }
        Color rgbtoGray(Color color){
            int average = (color.getR() + color.getG() + color.getB())/3;
            int sixteenMultiplier;                                          //numero multiplo de 16 mas cercano al average para hacer el gris
            if (average % 16 >= 8){
                sixteenMultiplier = (average/16) + 1;
            }
            else{
                sixteenMultiplier = average/16;
            }
            int grayCode = sixteenMultiplier * 16;
            Color finalGray(grayCode-1,grayCode-1,grayCode-1,255);
            //finalGray.print();
            return finalGray;
        }
};

#endif