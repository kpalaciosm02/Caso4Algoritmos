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
#include "color.hpp"
#include "grayTone.hpp"

#include "geneticbase.h"
#include "cromodistribution.h"
#include "individual.h"


#define DISTRIBUTION_SIZE 35

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
  int pixeles = (area * 0.1);

  ProbabilisticBase probabilistic;
  quadrants = probabilistic.chooseRandomQuadrant(pixeles, /*distribucion,*/ generador, quadrants, pixelRandom, RGB, width, image,vec);
  //probabilistic.setQuadrantsProbabilistic(quadrants);

  GeneticBase genetic;

  cromodistribution distribution[35];

  genetic.createCromoDis(quadrants, distribution);

  for(int i=0; i<DISTRIBUTION_SIZE; i++) {
      genetic.addDistribution(&distribution[i]);
  }

  //Población inicial de individuos
    genetic.initPopulation(3000);

    cout << "initial population" << endl;
    vector<individual*> result = genetic.getPopulation();
    for(int i=0; i<result.size(); i++) {
        cout << result.at(i)->getCromosoma() << endl;
    }

    // 3. measure the fitness of the population and reproduce it until reach the target generations
    // la cantidad de generaciones y cuantos hijos quiero hacer por generacion
    genetic.produceGenerations(3, 20);

    // check final population
    cout << "final population" << endl;
    result = genetic.getPopulation();
    for(int i=0; i<result.size(); i++) {
        cout << result.at(i)->getCromosoma() << endl;
    }

  // Limpiar
  stbi_image_free(image);

  cout << "Llegue" << endl << endl;

  Color color1(79,29,69,255);
  GrayTone gray1;
  gray1.rgbtoGray(color1);

  return 0;
}