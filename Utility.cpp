#include "Utility.h"
#include <random>

float calculateAverageFitnessSample(const std::vector<Pangolin>& population, size_t sampleSize) {
    if (population.empty()) return 0.0f; // Return 0 if there is no population
    if (population.size() < sampleSize) sampleSize = population.size(); // Adjust sample size if larger than population

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, population.size() - 1);

    float totalFitness = 0.0f;
    for (size_t i = 0; i < sampleSize; ++i) {
        int index = dis(gen); // Random index
        totalFitness += population[index].getFitness();
    }

    return totalFitness / sampleSize;
}

float calculatePopulationModifier(int populationSize, int carryingCapacity, int generation) {
    // Start with a lenient modifier in the early generations
    if (generation < 10) { // For the first 10 generations
        return 1.0f;
    }

    // As the population approaches the carrying capacity, increase the modifier
    float ratio = static_cast<float>(populationSize) / carryingCapacity;
    float modifier = 1.0f - ratio;

    modifier = std::max(0.5f, modifier);

    return modifier;
}

int calculateCarryingCapacity(float resource) {
    float capacityFactor = 4.0f; // Factor to convert resources to carrying capacity
    return static_cast<int>(resource / capacityFactor);
}
