#include "Pangolin.h"
#include <random>

Pangolin::Pangolin(Region region) : location(region) {
    genes.resize(GeneCount, 1.0f);
}

std::vector<Pangolin> Pangolin::reproduce(const std::vector<Pangolin>& potentialPartners) const {
    std::vector<Pangolin> offspring;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> offspringCountDist(1, 3);
    std::uniform_real_distribution<> dis(0, 1);
    std::bernoulli_distribution chooseParent(0.5);
    std::uniform_real_distribution<> mutationMagnitude(-1.0, 1.0); // Increased mutation range

    // Choose a partner based on the display trait
    std::discrete_distribution<> choosePartner(potentialPartners.size(), 0, potentialPartners.size()-1, [&](size_t i) {
        return potentialPartners[i].getFitness();
    });
    const Pangolin& partner = potentialPartners[choosePartner(gen)];

    // Determine the number of offspring
    int offspringCount = offspringCountDist(gen);

    const float mutationRate = 0.05; // 5% mutation rate

    for (int i = 0; i < offspringCount; ++i) {
        Pangolin offspring_t(location); // offspring is born in the same location as the parent

        // Each gene is inherited from either the parent or the partner
        for (int j = 0; j < GeneCount; ++j) {
            float geneValue = chooseParent(gen) ? genes[j] : partner.genes[j];

            // Apply mutation
            if (dis(gen) < mutationRate) {
                geneValue += mutationMagnitude(gen);
            }

            offspring_t.setGene(static_cast<GeneType>(j), geneValue);
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
