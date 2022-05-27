#include <bits/stdc++.h>
#include <stdlib.h>
#include <random>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"
#include "quadrant.hpp"
#include "divide_image.hpp"

using namespace std;

Pixel PixelRandQuadrant(vector<Quadrant> quadrants, int numberQuadrant, int width, size_t RGB, unsigned char *image, Pixel pixelRandom){
  Quadrant quadrant = quadrants[numberQuadrant];
  float randomX = rand() % (quadrant.getUpRight().first - quadrant.getDownLeft().first) + quadrant.getDownLeft().first;
  float randomY = rand() % (quadrant.getUpRight().second - quadrant.getDownLeft().second) + quadrant.getDownLeft().second;
  pixelRandom.setCoords(make_pair(randomX, randomY));
  //pixelRandom.print();
  size_t index = RGB * (randomY * width + randomX);
  int red = image[index];
  int green = image[index + 1];
  int blue = image[index + 2];
  quadrant.verifyRange(red, green, blue);

  return pixelRandom;
}

void calculateDistancePercentage(Pixel pixelRandom){
  float distancePer = pixelRandom.getBoundery()/pixelRandom.getBounderyDistance();
  pixelRandom.setDistancePercentage(distancePer);
}

void calculateBoundery(Pixel pixelRandom){

}

void calculateBounderyDistance(Pixel pixelRandom){

}

int main (){
  random_device device;
  mt19937 generador(device());
  vector<float> vec = {2.77, 2.77, 2.77, 2.77, 2.77, 2.77, 2.77, 2.77, 2.77, 2.77,
                       2.77, 2.77, 2.77, 2.77, 2.77, 2.77, 2.77, 2.77, 2.77, 2.77,
                       2.77, 2.77, 2.77, 2.77, 2.77, 2.77, 2.77, 2.77, 2.77, 2.77,
                       2.77, 2.77, 2.77, 2.77, 2.77, 2.77};
  discrete_distribution<> distribucion(vec.begin(), vec.end());

  int width, height, channels;
  unsigned char *image = stbi_load("cara.jpg", &width, &height, &channels, 0);
  size_t imageSize = width * height * channels;

  if(image == NULL){
    cout << ("Error cargando imagen") << endl;
  }

  vector<Quadrant> quadrants = generate_quadrants(150,0);
  Pixel pixelRandom;
  const size_t RGB = 3;
  int area = 780 * 1080;
  int pixeles = (area*0.40)/36;
  int counter = 0;

  while(pixeles > 0){
    switch(distribucion(generador)){
      case 0:
        cout << "Cuadrante 1";
        pixelRandom = PixelRandQuadrant(quadrants, 0, 780, RGB, image, pixelRandom);
        quadrants[0].setPixelRan(pixelRandom);
        calculateBoundery(pixelRandom);
        calculateBounderyDistance(pixelRandom);
        calculateDistancePercentage(pixelRandom);
        break;
      case 1: 
        cout << "Cuadrante 2"; 
        pixelRandom = PixelRandQuadrant(quadrants, 1, 780, RGB, image, pixelRandom);
        quadrants[1].setPixelRan(pixelRandom);
        calculateBoundery(pixelRandom);
        calculateBounderyDistance(pixelRandom);
        calculateDistancePercentage(pixelRandom);
        break;
      case 2: 
        cout << "Cuadrante 3";
        pixelRandom = PixelRandQuadrant(quadrants, 2, 780, RGB, image, pixelRandom);
        quadrants[2].setPixelRan(pixelRandom);
        calculateBoundery(pixelRandom);
        calculateBounderyDistance(pixelRandom);
        calculateDistancePercentage(pixelRandom);
        break;
      case 3: 
        cout << "Cuadrante 4"; 
        pixelRandom = PixelRandQuadrant(quadrants, 3, 780, RGB, image, pixelRandom);
        quadrants[3].setPixelRan(pixelRandom);
        calculateBoundery(pixelRandom);
        calculateBounderyDistance(pixelRandom);
        calculateDistancePercentage(pixelRandom);
        break;
      case 4: cout << "Cuadrante 5"; break;
      case 5: cout << "Cuadrante 6"; break;
      case 6: cout << "Cuadrante 7"; break;
      case 7: cout << "Cuadrante 8"; break;
      case 8: cout << "Cuadrante 9"; break;
      case 9: cout << "Cuadrante 10"; break;
      case 10: cout << "Cuadrante 11"; break;
      case 11: cout << "Cuadrante 12"; break;
      case 12: cout << "Cuadrante 13"; break;
      case 13: cout << "Cuadrante 14"; break;
      case 14: cout << "Cuadrante 15"; break;
      case 15: cout << "Cuadrante 16"; break;
      case 16: cout << "Cuadrante 17"; break;
      case 17: cout << "Cuadrante 18"; break;
      case 18: cout << "Cuadrante 19"; break;
      case 19: cout << "Cuadrante 20"; break;
      case 20: cout << "Cuadrante 21"; break;
      case 21: cout << "Cuadrante 22"; break;
      case 22: cout << "Cuadrante 23"; break;
      case 23: cout << "Cuadrante 24"; break;
      case 24: cout << "Cuadrante 25"; break;
      case 25: cout << "Cuadrante 26"; break;
      case 26: cout << "Cuadrante 27"; break;
      case 27: cout << "Cuadrante 28"; break;
      case 28: cout << "Cuadrante 29"; break;
      case 29: cout << "Cuadrante 30"; break;
      case 30: cout << "Cuadrante 31"; break;
      case 31: cout << "Cuadrante 32"; break;
      case 32: cout << "Cuadrante 33"; break;
      case 33: cout << "Cuadrante 34"; break;
      case 34: cout << "Cuadrante 35"; break;
      case 35: 
        cout << "Cuadrante 36"; 
        pixelRandom = PixelRandQuadrant(quadrants, 35, 780, RGB, image, pixelRandom);
        quadrants[35].setPixelRan(pixelRandom);
        break;
    }
    pixeles--;
    counter++;
  }
    cout << "n" << counter << endl;
  
    vector<Pixel> pix = quadrants[35].getPixelRandomList();
    for(vector<Pixel>::const_iterator i = pix.begin(); i != pix.end(); i++){
      Pixel p = *i;
      p.print();
    }

    /*int gray_channels = channels == 4 ? 2 : 1;
    size_t gray_img_size = width * height * gray_channels;

    unsigned char *gray_image = (unsigned char *)malloc(gray_img_size);
    if(gray_image == NULL){
      printf("hOLA");
    }

    for(unsigned char *p = image, *pg = gray_image; p!= image + imageSize; p += channels, pg += gray_channels){
      *pg = (uint8_t)((*p + *(p + 1) + *(p + 2))/3.0);
      if(channels == 4){
        *(pg + 1) = *(p + 3);
      }
    }

    stbi_write_jpg("cara_gris.jpg", width, height, gray_channels, gray_image, 100);

    unsigned char *imageGrey = stbi_load("cara_gris.jpg", &width, &height, &channels, 0);


    cout<<"Width of the image: "<<width<<endl;
    cout<<"Height of the image: "<<height<<endl;
    cout<<"Number of channels of the image: "<<channels<<endl;
    cout<<endl;

    //recorrer los primeros 10 pixeles de la imagen

    for(unsigned char *p = image; p!=image + 30; p+=channels){
      cout<< *p+0<<" "<<*p+1<<" "<<*p +2<<endl;
    }
    
  //Retornar valores RGB de un pixel en especifico
    
    int xPosition = 3, yPosition = 80;
    size_t index = RGB * (yPosition * width + xPosition);
    cout << "RGB pixel @ (x=3, y=80): " 
          << static_cast<int>(image[index + 0]) << " "  //red value
          << static_cast<int>(image[index + 1]) << " "  //green value
          << static_cast<int>(image[index + 2]) << " "<<endl; //blue value*/

    //Limpiar 
    stbi_image_free(image);
    //stbi_image_free(imageGrey);

    

    return 0;
}