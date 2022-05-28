#include <bits/stdc++.h>
#include <stdlib.h>
#include <random>
#include "quadrant.hpp"
#include <vector>
#include "color.hpp"
#include "grayTone.hpp"
class ProbabilisticBase {
    private:
        std::vector<Quadrant> quadrantsProbabilistic;
    public:

        vector<Quadrant> getQuadrantsProbabilistic(){
            return this->quadrantsProbabilistic;
        }

        void setQuadrantsProbabilistic(vector<Quadrant> _quadrantsProbabilistic){
            this->quadrantsProbabilistic = _quadrantsProbabilistic;
        }

        Pixel PixelRandQuadrant(std::vector<Quadrant> quadrants, int numberQuadrant, int width, size_t RGB, unsigned char *image, Pixel pixelRandom){
            Quadrant quadrant = quadrants[numberQuadrant];
            float randomX = rand() % (quadrant.getUpRight().first - quadrant.getDownLeft().first) + quadrant.getDownLeft().first;
            float randomY = rand() % (quadrant.getUpRight().second - quadrant.getDownLeft().second) + quadrant.getDownLeft().second;
            pixelRandom.setCoords(std::make_pair(randomX, randomY));
            size_t index = RGB * (randomY * width + randomX);
            int red = image[index];
            int green = image[index + 1];
            int blue = image[index + 2];
            Color colorActual(red,green,blue,255);
            GrayTone grayTone1;
            Color gray = grayTone1.rgbtoGray(colorActual);
            pixelRandom.setGray(gray);
            //quadrant.verifyRange(red, green, blue);

            return pixelRandom;
        }

        void calculateDensity(vector<Quadrant> quadrants, int numberQuadrant){
            Quadrant quadrant = quadrants[numberQuadrant];
            float density = quadrant.getPixelRandomList().size() / (23400 * 0.2);
            quadrant.setDensityPixels(density);
        }

        vector<float> newDistribution(vector<float> vec, int index){    //baja la probabilidad de un indice y sube las demas
            float actualDist = vec.at(index);
            float newActualDist = actualDist/3;
            float distributeProb = newActualDist * 2;
            float addNumber = distributeProb/35;
            int vectorSize = vec.size();
            for (int i = 0; i < vectorSize; i++){
                if (i != index){
                    vec.at(i) = vec.at(i) + addNumber;
                }
                else{
                    vec.at(i) = newActualDist;
                }
            }
            return vec;
        }

        vector<Quadrant> chooseRandomQuadrant(int pixeles/*, std::discrete_distribution<> distribucion*/, std::mt19937 generador, std::vector<Quadrant> quadrants, Pixel pixelRandom, size_t RGB, int width, unsigned char *image, std::vector<float> vec){
            int counter = 0;
            while(pixeles > 0){
                std::discrete_distribution<> distribucion(vec.begin(),vec.end());
                //std::cout << vec.at(0); 
                switch(distribucion(generador)){
                    case 0:
                        pixelRandom = PixelRandQuadrant(quadrants, 0, 780, RGB, image, pixelRandom);
                        quadrants[0].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 0);
                        vec = newDistribution(vec, 0);
                        break;
                    case 1: 
                        pixelRandom = PixelRandQuadrant(quadrants, 1, 780, RGB, image, pixelRandom);
                        quadrants[1].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 1);
                        vec = newDistribution(vec, 1);
                        break;
                    case 2: 
                        pixelRandom = PixelRandQuadrant(quadrants, 2, 780, RGB, image, pixelRandom);
                        quadrants[2].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 2);
                        vec = newDistribution(vec, 2);
                        break;
                    case 3: 
                        pixelRandom = PixelRandQuadrant(quadrants, 3, 780, RGB, image, pixelRandom);
                        quadrants[3].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 3);
                        vec = newDistribution(vec, 3);
                        break;
                    case 4: 
                        pixelRandom = PixelRandQuadrant(quadrants, 4, 780, RGB, image, pixelRandom);
                        quadrants[4].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 4);
                        vec = newDistribution(vec, 4);
                        break;
                    case 5: 
                        pixelRandom = PixelRandQuadrant(quadrants, 5, 780, RGB, image, pixelRandom);
                        quadrants[5].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 5);
                        vec = newDistribution(vec, 5);
                        break;
                    case 6: 
                        pixelRandom = PixelRandQuadrant(quadrants, 6, 780, RGB, image, pixelRandom);
                        quadrants[6].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 6);
                        vec = newDistribution(vec, 6);
                        break;
                    case 7: 
                        pixelRandom = PixelRandQuadrant(quadrants, 7, 780, RGB, image, pixelRandom);
                        quadrants[7].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 7);
                        vec = newDistribution(vec, 7);
                        break;
                    case 8: 
                        pixelRandom = PixelRandQuadrant(quadrants, 8, 780, RGB, image, pixelRandom);
                        quadrants[8].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 8);
                        vec = newDistribution(vec, 8);
                        break;
                    case 9: 
                        pixelRandom = PixelRandQuadrant(quadrants, 9, 780, RGB, image, pixelRandom);
                        quadrants[9].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 9);
                        vec = newDistribution(vec, 9);
                        break;
                    case 10: 
                        pixelRandom = PixelRandQuadrant(quadrants, 10, 780, RGB, image, pixelRandom);
                        quadrants[10].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 10);
                        vec = newDistribution(vec, 10);
                        break;
                    case 11: 
                        pixelRandom = PixelRandQuadrant(quadrants, 11, 780, RGB, image, pixelRandom);
                        quadrants[11].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 11);
                        vec = newDistribution(vec, 11);
                        break;
                    case 12: 
                        pixelRandom = PixelRandQuadrant(quadrants, 12, 780, RGB, image, pixelRandom);
                        quadrants[12].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 12);
                        vec = newDistribution(vec, 12);
                        break;
                    case 13: 
                        pixelRandom = PixelRandQuadrant(quadrants, 13, 780, RGB, image, pixelRandom);
                        quadrants[13].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 13);
                        vec = newDistribution(vec, 13);
                        break;
                    case 14: 
                        pixelRandom = PixelRandQuadrant(quadrants, 14, 780, RGB, image, pixelRandom);
                        quadrants[14].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 14);
                        vec = newDistribution(vec, 14);
                        break;
                    case 15: 
                        pixelRandom = PixelRandQuadrant(quadrants, 15, 780, RGB, image, pixelRandom);
                        quadrants[15].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 15);
                        vec = newDistribution(vec, 15);
                        break;
                    case 16: 
                        pixelRandom = PixelRandQuadrant(quadrants, 16, 780, RGB, image, pixelRandom);
                        quadrants[16].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 16);
                        vec = newDistribution(vec, 16);
                        break;
                    case 17: 
                        pixelRandom = PixelRandQuadrant(quadrants, 17, 780, RGB, image, pixelRandom);
                        quadrants[17].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 17);
                        vec = newDistribution(vec, 17);
                        break;
                    case 18: 
                        pixelRandom = PixelRandQuadrant(quadrants, 18, 780, RGB, image, pixelRandom);
                        quadrants[18].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 18);
                        vec = newDistribution(vec, 18);
                        break;
                    case 19:
                        pixelRandom = PixelRandQuadrant(quadrants, 19, 780, RGB, image, pixelRandom);
                        quadrants[19].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 19);
                        vec = newDistribution(vec, 19);
                        break;
                    case 20: 
                        pixelRandom = PixelRandQuadrant(quadrants, 20, 780, RGB, image, pixelRandom);
                        quadrants[20].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 20);
                        vec = newDistribution(vec, 20);
                        break;
                    case 21: 
                        pixelRandom = PixelRandQuadrant(quadrants, 21, 780, RGB, image, pixelRandom);
                        quadrants[21].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 21);
                        vec = newDistribution(vec, 21);
                        break;
                    case 22: 
                        pixelRandom = PixelRandQuadrant(quadrants, 22, 780, RGB, image, pixelRandom);
                        quadrants[22].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 22);
                        vec = newDistribution(vec, 22);
                        break;
                    case 23: 
                        pixelRandom = PixelRandQuadrant(quadrants, 23, 780, RGB, image, pixelRandom);
                        quadrants[23].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 23);
                        vec = newDistribution(vec, 23);
                        break;
                    case 24:
                        pixelRandom = PixelRandQuadrant(quadrants, 24, 780, RGB, image, pixelRandom);
                        quadrants[24].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 24);
                        vec = newDistribution(vec, 24);
                        break;
                    case 25: 
                        pixelRandom = PixelRandQuadrant(quadrants, 25, 780, RGB, image, pixelRandom);
                        quadrants[25].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 25);
                        vec = newDistribution(vec, 25);
                        break;
                    case 26: 
                        pixelRandom = PixelRandQuadrant(quadrants, 26, 780, RGB, image, pixelRandom);
                        quadrants[26].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 26);
                        vec = newDistribution(vec, 26);
                        break;
                    case 27: 
                        pixelRandom = PixelRandQuadrant(quadrants, 27, 780, RGB, image, pixelRandom);
                        quadrants[27].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 27);
                        vec = newDistribution(vec, 27);
                        break;
                    case 28: 
                        pixelRandom = PixelRandQuadrant(quadrants, 28, 780, RGB, image, pixelRandom);
                        quadrants[28].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 28);
                        vec = newDistribution(vec, 28);
                        break;
                    case 29: 
                        pixelRandom = PixelRandQuadrant(quadrants, 29, 780, RGB, image, pixelRandom);
                        quadrants[29].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 29);
                        vec = newDistribution(vec, 29);
                        break;
                    case 30: 
                        pixelRandom = PixelRandQuadrant(quadrants, 30, 780, RGB, image, pixelRandom);
                        quadrants[30].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 30);
                        vec = newDistribution(vec, 30);
                        break;
                    case 31: 
                        pixelRandom = PixelRandQuadrant(quadrants, 31, 780, RGB, image, pixelRandom);
                        quadrants[31].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 31);
                        vec = newDistribution(vec, 31);
                        break;
                    case 32: 
                        pixelRandom = PixelRandQuadrant(quadrants, 32, 780, RGB, image, pixelRandom);
                        quadrants[32].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 32);
                        vec = newDistribution(vec, 32);
                        break;
                    case 33: 
                        pixelRandom = PixelRandQuadrant(quadrants, 33, 780, RGB, image, pixelRandom);
                        quadrants[33].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 33);
                        vec = newDistribution(vec, 33);
                        break;
                    case 34: 
                        pixelRandom = PixelRandQuadrant(quadrants, 34, 780, RGB, image, pixelRandom);
                        quadrants[34].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 34);
                        vec = newDistribution(vec, 34);
                        break;
                    case 35: 
                        pixelRandom = PixelRandQuadrant(quadrants, 35, 780, RGB, image, pixelRandom);
                        quadrants[35].setPixelRan(pixelRandom);
                        calculateDensity(quadrants, 35);
                        vec = newDistribution(vec, 35);
                        break;
                    }
                pixeles--;
            }
            return quadrants;
        }
};