#include <bits/stdc++.h>
#include <stdlib.h>
#include <random>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image.h"
#include "stb_image_write.h"

#include <vector>

#include "quadrant.hpp"
#include "divide_image.hpp"
#include "probabilisticAlgorithm.hpp"

#include "geneticbase.h"
#include "cromodistribution.h"
#include "individual.h"


#define DISTRIBUTION_SIZE 3

using namespace std;

int main(){
  random_device device;
  mt19937 generador(device());
  vector<float> vec = {2.77, 2.77, 2.77, 2.77, 2.77, 2.77, 2.77, 2.77, 2.77, 2.77,
                       2.77, 2.77, 2.77, 2.77, 2.77, 2.77, 2.77, 2.77, 2.77, 2.77,
                       2.77, 2.77, 2.77, 2.77, 2.77, 2.77, 2.77, 2.77, 2.77, 2.77,
                       2.77, 2.77, 2.77, 2.77, 2.77, 2.77};
  discrete_distribution<> distribucion(vec.begin(), vec.end());

//picture processing
  int width, height, channels;
  unsigned char *image = stbi_load("cara.jpg", &width, &height, &channels, 0);
  size_t imageSize = width * height * channels;

  if (image == NULL){
    std::cout << ("Error cargando imagen") << endl;
  }

  vector<Quadrant> quadrants = generate_quadrants(150, 0);
  Pixel pixelRandom;
  const size_t RGB = 3;
  int area = 780 * 1080;
  int pixeles = (area * 0.2);

  ProbabilisticBase probabilistic;
  quadrants = probabilistic.chooseRandomQuadrant(pixeles, distribucion, generador, quadrants, pixelRandom, RGB, width, image);
  probabilistic.setQuadrantsProbabilistic(quadrants);

  // Limpiar
  stbi_image_free(image);

  cout << "Llegue" << endl << endl;

  return 0;
}