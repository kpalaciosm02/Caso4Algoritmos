#ifndef _GENETICBASE_
#define _GENETICBASE_ 1
#include <vector>
#include "cromodistribution.h"
#include "individual.h"
#include <stdlib.h>
#include <cmath>

using namespace std;

class GeneticBase {
    private:
        vector<cromodistribution*> *representation;
        vector<individual*> *population;
        vector<individual*> *fitnessPopulation;
        vector<individual*> *unfitnessPopulation;
        int populationQuantity;
        int targetGenerations;

        void evaluateFitness() {
            fitnessPopulation->clear();
            unfitnessPopulation->clear();

            for(int i=0;i<population->size(); i++) {
               population->at(i)->setFitnessValue(fitness(population->at(i)));
                if (population->at(i)->getFitnessValue()> 40) {  
                    fitnessPopulation->push_back(population->at(i));
                } else {
                    unfitnessPopulation->push_back(population->at(i));
                }
            }
        }

        Quadrant getRangesCromo(individual *pIndividual){
            unsigned char cromosoma = pIndividual->getCromosoma();
            Quadrant quadrantActualCromo;
            ProbabilisticBase probabilistic;
            vector<Quadrant> prob = probabilistic.getQuadrantsProbabilistic();
            if(cromosoma > 0 && cromosoma < 1820)
                quadrantActualCromo = prob[0];
            if(cromosoma > 1821 && cromosoma < 3641)
                quadrantActualCromo = prob[1];
            if(cromosoma > 3642 && cromosoma < 5462)
                quadrantActualCromo = prob[2];
            if(cromosoma > 5463 && cromosoma < 7283)
                quadrantActualCromo = prob[3];
            if(cromosoma > 7284 && cromosoma < 9104)
                quadrantActualCromo = prob[4];
            if(cromosoma > 9105 && cromosoma < 10925)
                quadrantActualCromo = prob[5];
            if(cromosoma > 10926  && cromosoma < 12746)
                quadrantActualCromo = prob[6];
            if(cromosoma > 12747 && cromosoma < 14567)
                quadrantActualCromo = prob[7];
            if(cromosoma > 14568 && cromosoma < 16388)
                quadrantActualCromo = prob[8];
            if(cromosoma > 16389 && cromosoma < 18209)
                quadrantActualCromo = prob[9];
            if(cromosoma > 18210 && cromosoma < 20030)
                quadrantActualCromo = prob[10];
            if(cromosoma > 20031 && cromosoma < 21851)
                quadrantActualCromo = prob[11];
            if(cromosoma > 21852 && cromosoma < 23672)
                quadrantActualCromo = prob[12];
            if(cromosoma > 23673 && cromosoma < 25493)
                quadrantActualCromo = prob[13];
            if(cromosoma > 25494 && cromosoma < 27314)
                quadrantActualCromo = prob[14];
            if(cromosoma > 27315 && cromosoma < 29135)
                quadrantActualCromo = prob[15];
            if(cromosoma > 29136 && cromosoma < 30956)
                quadrantActualCromo = prob[16];
            if(cromosoma > 30957 && cromosoma < 32777)
                quadrantActualCromo = prob[17];
            if(cromosoma > 32778 && cromosoma < 34598)
                quadrantActualCromo = prob[18];
            if(cromosoma > 34599 && cromosoma < 36419)
                quadrantActualCromo = prob[19];
            if(cromosoma > 36420 && cromosoma < 38240)
                quadrantActualCromo = prob[20];
            if(cromosoma > 38241 && cromosoma < 40061)
                quadrantActualCromo = prob[21];
            if(cromosoma > 40062 && cromosoma < 41882)
                quadrantActualCromo = prob[22];
            if(cromosoma > 41883 && cromosoma < 43703)
                quadrantActualCromo = prob[23];
            if(cromosoma > 43704 && cromosoma < 45524)
                quadrantActualCromo = prob[24];
            if(cromosoma > 45525 && cromosoma < 47345)
                quadrantActualCromo = prob[25];
            if(cromosoma > 47346 && cromosoma < 49166)
                quadrantActualCromo = prob[26];
            if(cromosoma > 49167 && cromosoma < 50987)
                quadrantActualCromo = prob[27];
            if(cromosoma > 50988 && cromosoma < 52808)
                quadrantActualCromo = prob[28];
            if(cromosoma > 52809 && cromosoma < 54629)
                quadrantActualCromo = prob[29];
            if(cromosoma > 54630 && cromosoma < 56450)
                quadrantActualCromo = prob[30];
            if(cromosoma > 56451 && cromosoma < 58271)
                quadrantActualCromo = prob[31];
            if(cromosoma > 58272 && cromosoma < 60092)
                quadrantActualCromo = prob[32];
            if(cromosoma > 60093 && cromosoma < 61913)
                quadrantActualCromo = prob[33];
            if(cromosoma > 61914 && cromosoma < 63734)
                quadrantActualCromo = prob[34];
            else{
                quadrantActualCromo = prob[35];
            }
            return quadrantActualCromo;
        }

        void getPixelQuadrantCromo(Quadrant quadrant){
            Pixel p1, p2;
            pair<float, float> coordsPixel, coordsNeigh1, coordsNeigh2;
            std::vector<Pixel> pixels = quadrant.getPixelRandomList();
            int randomIndex = rand()%pixels.size()-1;
            for(int i = 0; i < pixels.size(); i++){
                int pixelIndex = i;
                if(pixelIndex == randomIndex){
                    Pixel p = pixels[i];
                    if(randomIndex == pixels.size()){
                        p1 = pixels[i-1];
                        p2 = pixels[i-2];
                    }else{
                        p1 = pixels[i+1];
                        p2 = pixels[i+2];
                    }
                    coordsPixel = p.getCoords();
                    coordsNeigh1 = p1.getCoords();
                    coordsNeigh2 = p2.getCoords();
                }
            }
            pixelNeighbours(coordsPixel, coordsNeigh1, coordsNeigh2);
        }

        float pixelNeighbours(pair<float, float> coordsPixel, pair<float, float> coordsNeigh1, pair<float, float> coordsNeigh2){
            float subsXNeigh1 = coordsNeigh1.first - coordsPixel.first;
            float subsYNeigh1 = coordsNeigh1.second - coordsPixel.second;
            float subsXNeigh2 = coordsNeigh2.first - coordsPixel.first;
            float subsYNeigh2 = coordsNeigh2.second - coordsPixel.second;

            float distanceNeigh1 = sqrt(pow((subsXNeigh1), 2)  + pow((subsYNeigh1), 2));
            float distanceNeigh2 = sqrt(pow((subsXNeigh2), 2)  + pow((subsYNeigh2), 2));

            float distanceDivTotal1 = distanceNeigh1 / 20;
            float distanceDivTotal2 = distanceNeigh2 / 20;

            float distanceDivOne1 = 1 / distanceDivTotal1;
            float distanceDivOne2 = 1 / distanceDivTotal2;

            float fitnessValue = distanceDivOne1 + distanceDivOne2;

            return fitnessValue;
        }

        float fitness(individual *pIndividual) {
            float fitness;
            Quadrant quadrantActualCromo = getRangesCromo(pIndividual);
            getPixelQuadrantCromo(quadrantActualCromo);

            return fitness;
        }

        void reproduce(int pAmountOfChildrens) {
            population->clear();

            for(int i=0; i<pAmountOfChildrens; i++) {
                int parent_a_index = rand()%fitnessPopulation->size();
                individual* parent_a = fitnessPopulation->at(parent_a_index);

                int parent_b_index = rand()%fitnessPopulation->size();
                individual* parent_b = fitnessPopulation->at(parent_b_index);

                population->push_back(cross(parent_a, parent_b));
            }
        }

        individual* cross(individual *pParent_a, individual *pParent_b) {
            // this operation will depends on: nibble size, si el punto de corte es fixed o variable point

            int cut_position = (rand() % (NIBBLE_SIZE-MIN_GENOTYPE_SIZE_BY_PARENT*2)) + MIN_GENOTYPE_SIZE_BY_PARENT;

            unsigned char mask_a = CROMO_MAX_VALUE - 1; // 255 -> 11111111
            mask_a <<= cut_position;

            unsigned char mask_b = CROMO_MAX_VALUE - 1; // 255 -> 11111111
            mask_b >>= NIBBLE_SIZE - cut_position;

            unsigned char kid = (pParent_a->getCromosoma() & mask_a) | (pParent_b->getCromosoma() & mask_b);

            individual *children = new individual(kid);

            // hace falta la mutación, hay que agregar el % de mutación y la mutación en si misma
            return children;
        }

    public:
        GeneticBase() {
            this->population = new vector<individual*>();
            this->fitnessPopulation = new vector<individual*>();
            this->unfitnessPopulation = new vector<individual*>();
            this->representation = new vector<cromodistribution*>(); 
            this->populationQuantity = 0;
            this->targetGenerations = 20;
        }

        std::vector<cromodistribution*>* getRepresentation(){
            return representation;
        }
        void addDistribution(cromodistribution* pDistribution) {
            representation->push_back(pDistribution);
        }

        void initPopulation(int pAmountOfIndividuals) {
            population->clear();

            for(int i=0; i<pAmountOfIndividuals; i++) {
                individual* p = new individual((unsigned char) rand()%CROMO_MAX_VALUE);
                population->push_back(p);
            }
        }
        
        void produceGenerations(int ptargetGenerations, int pChildrensPerGenerations) {
            for(int i=0; i<ptargetGenerations; i++) {
                evaluateFitness();
                reproduce(pChildrensPerGenerations);
            }
        }

        void createCromoDis(vector<Quadrant> quadrants, cromodistribution distribution[35]){
            for(int i = 0; i < 35; i++){
                Quadrant quadrant = quadrants[i];
                distribution[i].x = quadrant.getUpRight().first;
                distribution[i].y = quadrant.getUpRight().second;
                distribution[i].x1 = quadrant.getDownLeft().first;
                distribution[i].y1 = quadrant.getDownLeft().second;
                float density = quadrant.getDensityPixels();
                if(density < 0.60){
                distribution[i].shape = "linea";
                if(density > 0.0 && density < 0.2){
                    distribution[i].size = "grande";
                }
                else if(density > 0.2 && density < 0.4){
                    distribution[i].size = "mediano";
                }
                else{
                    distribution[i].size = "pequeño";
                }
                }else{
                distribution[i].shape = "punto";
                if(density > 0.6 && density < 0.7){
                    distribution[i].size = "grande";
                }
                else if(density > 0.7 && density < 0.9){
                    distribution[i].size = "mediano";
                }
                else{
                    distribution[i].size = "pequeño";
                }
                }
                distribution[i].quantityPixels = quadrant.getPixelRandomList().size();
            }
        }

        vector<individual*> getPopulation() {
            return *this->population;
        }
};

#endif