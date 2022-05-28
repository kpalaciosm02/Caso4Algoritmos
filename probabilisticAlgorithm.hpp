#include <bits/stdc++.h>
#include <stdlib.h>
#include <random>
#include "quadrant.hpp"
#include <vector>

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
            quadrant.verifyRange(red, green, blue);

            return pixelRandom;
        }

        void calculateDistanceForPixel(vector<Quadrant> quadrants, int numberQuadrant, Pixel pixelRandom){
            Quadrant quadrant = quadrants[numberQuadrant];
            float distance = quadrant.getPixelRandomList().size() / (23400 / 0.2);
            pixelRandom.setDistanceBoundery(distance);
        }
            
        vector<Quadrant> chooseRandomQuadrant(int pixeles, std::discrete_distribution<> distribucion, std::mt19937 generador, std::vector<Quadrant> quadrants, Pixel pixelRandom, size_t RGB, int width, unsigned char *image){
            int counter = 0;
            while(pixeles > 0){
                switch(distribucion(generador)){
                    case 0:
                        pixelRandom = PixelRandQuadrant(quadrants, 0, 780, RGB, image, pixelRandom);
                        quadrants[0].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 0, pixelRandom);
                        break;
                    case 1: 
                        pixelRandom = PixelRandQuadrant(quadrants, 1, 780, RGB, image, pixelRandom);
                        quadrants[1].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 1, pixelRandom);
                        break;
                    case 2: 
                        pixelRandom = PixelRandQuadrant(quadrants, 2, 780, RGB, image, pixelRandom);
                        quadrants[2].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 2, pixelRandom);
                        break;
                    case 3: 
                        pixelRandom = PixelRandQuadrant(quadrants, 3, 780, RGB, image, pixelRandom);
                        quadrants[3].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 3, pixelRandom);
                        break;
                    case 4: 
                        pixelRandom = PixelRandQuadrant(quadrants, 4, 780, RGB, image, pixelRandom);
                        quadrants[4].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 4, pixelRandom);
                        break;
                    case 5: 
                        pixelRandom = PixelRandQuadrant(quadrants, 5, 780, RGB, image, pixelRandom);
                        quadrants[5].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 5, pixelRandom);
                        break;
                    case 6: 
                        pixelRandom = PixelRandQuadrant(quadrants, 6, 780, RGB, image, pixelRandom);
                        quadrants[6].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 6, pixelRandom);
                        break;
                    case 7: 
                        pixelRandom = PixelRandQuadrant(quadrants, 7, 780, RGB, image, pixelRandom);
                        quadrants[7].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 7, pixelRandom);
                        break;
                    case 8: 
                        pixelRandom = PixelRandQuadrant(quadrants, 8, 780, RGB, image, pixelRandom);
                        quadrants[8].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 8, pixelRandom);
                        break;
                    case 9: 
                        pixelRandom = PixelRandQuadrant(quadrants, 9, 780, RGB, image, pixelRandom);
                        quadrants[9].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 9, pixelRandom);
                        break;
                    case 10: 
                        pixelRandom = PixelRandQuadrant(quadrants, 10, 780, RGB, image, pixelRandom);
                        quadrants[10].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 10, pixelRandom);
                        break;
                    case 11: 
                        pixelRandom = PixelRandQuadrant(quadrants, 11, 780, RGB, image, pixelRandom);
                        quadrants[11].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 11, pixelRandom);
                        break;
                    case 12: 
                        pixelRandom = PixelRandQuadrant(quadrants, 12, 780, RGB, image, pixelRandom);
                        quadrants[12].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 12, pixelRandom);
                        break;
                    case 13: 
                        pixelRandom = PixelRandQuadrant(quadrants, 13, 780, RGB, image, pixelRandom);
                        quadrants[13].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 13, pixelRandom);
                        break;
                    case 14: 
                        pixelRandom = PixelRandQuadrant(quadrants, 14, 780, RGB, image, pixelRandom);
                        quadrants[14].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 14, pixelRandom);
                        break;
                    case 15: 
                        pixelRandom = PixelRandQuadrant(quadrants, 15, 780, RGB, image, pixelRandom);
                        quadrants[15].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 15, pixelRandom);
                        break;
                    case 16: 
                        pixelRandom = PixelRandQuadrant(quadrants, 16, 780, RGB, image, pixelRandom);
                        quadrants[16].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 16, pixelRandom);
                        break;
                    case 17: 
                        pixelRandom = PixelRandQuadrant(quadrants, 17, 780, RGB, image, pixelRandom);
                        quadrants[17].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 17, pixelRandom);
                        break;
                    case 18: 
                        pixelRandom = PixelRandQuadrant(quadrants, 18, 780, RGB, image, pixelRandom);
                        quadrants[18].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 18, pixelRandom);
                        break;
                    case 19:
                        pixelRandom = PixelRandQuadrant(quadrants, 19, 780, RGB, image, pixelRandom);
                        quadrants[19].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 19, pixelRandom);
                        break;
                    case 20: 
                        pixelRandom = PixelRandQuadrant(quadrants, 20, 780, RGB, image, pixelRandom);
                        quadrants[20].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 20, pixelRandom);
                        break;
                    case 21: 
                        pixelRandom = PixelRandQuadrant(quadrants, 21, 780, RGB, image, pixelRandom);
                        quadrants[21].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 21, pixelRandom);
                        break;
                    case 22: 
                        pixelRandom = PixelRandQuadrant(quadrants, 22, 780, RGB, image, pixelRandom);
                        quadrants[22].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 22, pixelRandom);
                        break;
                    case 23: 
                        pixelRandom = PixelRandQuadrant(quadrants, 23, 780, RGB, image, pixelRandom);
                        quadrants[23].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 23, pixelRandom);
                        break;
                    case 24:
                        pixelRandom = PixelRandQuadrant(quadrants, 24, 780, RGB, image, pixelRandom);
                        quadrants[24].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 24, pixelRandom);
                        break;
                    case 25: 
                        pixelRandom = PixelRandQuadrant(quadrants, 25, 780, RGB, image, pixelRandom);
                        quadrants[25].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 25, pixelRandom);
                        break;
                    case 26: 
                        pixelRandom = PixelRandQuadrant(quadrants, 26, 780, RGB, image, pixelRandom);
                        quadrants[26].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 26, pixelRandom);
                        break;
                    case 27: 
                        pixelRandom = PixelRandQuadrant(quadrants, 27, 780, RGB, image, pixelRandom);
                        quadrants[27].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 27, pixelRandom);
                        break;
                    case 28: 
                        pixelRandom = PixelRandQuadrant(quadrants, 28, 780, RGB, image, pixelRandom);
                        quadrants[28].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 28, pixelRandom);
                        break;
                    case 29: 
                        pixelRandom = PixelRandQuadrant(quadrants, 29, 780, RGB, image, pixelRandom);
                        quadrants[29].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 29, pixelRandom);
                        break;
                    case 30: 
                        pixelRandom = PixelRandQuadrant(quadrants, 30, 780, RGB, image, pixelRandom);
                        quadrants[30].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 30, pixelRandom);
                        break;
                    case 31: 
                        pixelRandom = PixelRandQuadrant(quadrants, 31, 780, RGB, image, pixelRandom);
                        quadrants[31].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 31, pixelRandom);
                        break;
                    case 32: 
                        pixelRandom = PixelRandQuadrant(quadrants, 32, 780, RGB, image, pixelRandom);
                        quadrants[32].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 32, pixelRandom);
                        break;
                    case 33: 
                        pixelRandom = PixelRandQuadrant(quadrants, 33, 780, RGB, image, pixelRandom);
                        quadrants[33].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 33, pixelRandom);
                        break;
                    case 34: 
                        pixelRandom = PixelRandQuadrant(quadrants, 34, 780, RGB, image, pixelRandom);
                        quadrants[34].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 34, pixelRandom);
                        break;
                    case 35: 
                        pixelRandom = PixelRandQuadrant(quadrants, 35, 780, RGB, image, pixelRandom);
                        quadrants[35].setPixelRan(pixelRandom);
                        calculateDistanceForPixel(quadrants, 35, pixelRandom);
                        break;
                    }
                pixeles--;
                counter++;
            }
            std::cout << counter << endl;
            return quadrants;
        }
};