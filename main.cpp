#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"
#include "quadrant.hpp" 

using namespace std;

int main (){

    int width, height, channels;

    unsigned char *image = stbi_load("cara.jpg", &width, &height, &channels, 0);
    size_t imageSize = width * height * channels;


    if(image == NULL){
      cout << ("Error cargando imagen") << endl;
    }

    
    int gray_channels = channels == 4 ? 2 : 1;
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
    const size_t RGB = 3;
    int xPosition = 3, yPosition = 80;
    size_t index = RGB * (yPosition * width + xPosition);
    cout << "RGB pixel @ (x=3, y=80): " 
          << static_cast<int>(image[index + 0]) << " "  //red value
          << static_cast<int>(image[index + 1]) << " "  //green value
          << static_cast<int>(image[index + 2]) << " "<<endl; //blue value

    //Limpiar 
    stbi_image_free(image);
    stbi_image_free(imageGrey);

    return 0;
}