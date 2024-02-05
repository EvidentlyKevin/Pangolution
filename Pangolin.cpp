#include "Pangolin.h"
#include <random>

Pangolin::Pangolin(Region region) : location(region) {
    genes.resize(GeneCount, 1.0f);
}

std::vector<Pangolin> Pangolin::reproduce(const Pangolin& partner) const {
    std::vector<Pangolin> offspring;
    Pangolin offspring_t(Region1);
    std::uniform_int_distribution<> offspringCountDist(1, 3);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);
    std::bernoulli_distribution chooseParent(0.5);
    std::uniform_real_distribution<> mutationMagnitude(-1.0, 1.0); // Increased mutation range

    int offspringCount = offspringCountDist(gen);

    for (int i = 0; i < offspringCount; ++i) {
        
        for (int i = 0; i < GeneCount; ++i) {
            offspring_t.genes[i] = chooseParent(gen) ? genes[i] : partner.genes[i];
            // Mutation
            if (dis(gen) < 0.05) {
                offspring_t.genes[i] += mutationMagnitude(gen);
            }
        }

        offspring.push_back(offspring_t);
    }

    return offspring;
}

float Pangolin::getFitness() const {
    switch(location) {
        case Region1:
            return genes[SIZE]; // Region 1 favors SIZE
        case Region2:
            return genes[SPEED]; // Region 2 favors SPEED
        case Region3:
            return genes[COLOR]; // Region 3 favors COLOR
        case Region4:
            return (genes[SIZE] + genes[SPEED] + genes[COLOR]) / 3; // Region 4 favors the average
        default:
            return 0.0f;
    }
}

float Pangolin::getGene(GeneType geneType) const {
    return genes[geneType];
}

void Pangolin::setGene(GeneType geneType, float value) {
    genes[geneType] = value;
}

int Pangolin::getLocation() const {
    return location;
}

void Pangolin::setLocation(Region newLocation) {
    location = newLocation;
}
