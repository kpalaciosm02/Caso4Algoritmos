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
                // ajustarlo al fitness y fitness criteria del problema
                if (population->at(i)->getFitnessValue()>50) {  
                    fitnessPopulation->push_back(population->at(i));
                } else {
                    unfitnessPopulation->push_back(population->at(i));
                }
            }
        }

        float fitness(individual *pIndividual) {
            return rand()%65000;
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