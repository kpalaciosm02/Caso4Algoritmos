#include <bits/stdc++.h>
#include <stdlib.h>
#include <random>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image.h"
#include "stb_image_write.h"

#include <vector>

#include "SocketClient.h"
#include "quadrant.hpp"
#include "divide_image.hpp"
#include "probabilisticAlgorithm.hpp"
#include "color.hpp"
#include "grayTone.hpp"


#include "geneticbase.h"
#include "cromodistribution.h"
#include "individual.h"


#define DISTRIBUTION_SIZE 35

//using namespace std;

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

    std::cout << "initial population" << std::endl;
    vector<individual*> result = genetic.getPopulation();
    /*for(int i=0; i<result.size(); i++) {
        cout << result.at(i)->getCromosoma() << endl;
    }*/
    std::cout << "Llegue1" << endl;
    // 3. measure the fitness of the population and reproduce it until reach the target generations
    // la cantidad de generaciones y cuantos hijos quiero hacer por generacion
    genetic.produceGenerations(3, 20);

    // check final population
    std::cout << "final population" << std::endl;
    result = genetic.getPopulation();
    /*for(int i=0; i<result.size(); i++) {
        cout << result.at(i)->getCromosoma() << endl;
    }*/
    std::cout << "Llegue:2" << std::endl;
    // Limpiar
    stbi_image_free(image);

    Color color1(79,29,69,255);
    GrayTone gray1;
    gray1.rgbtoGray(color1);

    SocketClient client;

    client.init();

    client.clear();
    std::vector<cromodistribution*>* chromo = genetic.getRepresentation();
    for(int i = 0; i < chromo->size(); i++){
      cromodistribution * actual = chromo->at(i);
      client.paintDot(255,255,255,255,actual->x1,actual->y1,25);
    }
    //client.paintLine(100, 255, 176, 255, 100, 100, 250, 600);
    //client.paintDot(200, 0, 15, 200, 500, 600, 15);
    //client.paintDot(220, 150, 15, 200, 600, 600, 20);
    client.closeConnection();

  return 0;
}