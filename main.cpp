#include "Pangolin.h"
#include "Utility.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cmath>
#include <random>

int main() {
    const int INITIAL_POPULATION_SIZE = 500;
    const int NUMBER_OF_GENERATIONS = 50;
    const float MORTALITY_RATE = 0.25f;
    const float RESOURCE_CONSUMPTION_PER_OFFSPRING = 1.25f;
    const float INITIAL_RESOURCES = 1000.0f;
    const float RESOURCE_REPLENISH_AMOUNT = 0;
    const float RESOURCE_GROWTH_RATE = 2.0f; // Exponential growth rate
    const float CARRYING_CAPACITY = 5000.0f; // Carrying capacity for resources

    std::map<Pangolin::Region, std::vector<Pangolin>> regionalPopulations;
    std::map<Pangolin::Region, float> environmentalResources;
    std::random_device rd;
    std::mt19937 gen(rd());

    // Initialize populations and resources
    for (int i = 0; i < INITIAL_POPULATION_SIZE; ++i) {
        Pangolin::Region region = static_cast<Pangolin::Region>(i % Pangolin::NUM_REGIONS);
        regionalPopulations[region].push_back(Pangolin(region));
        environmentalResources[region] = INITIAL_RESOURCES;
    }

    // Initialize the output CSV file
    std::ofstream outFile("pangolin_data.csv");
    outFile << "Region,Generation,Exists,PopulationSize,AverageFitness\n";

    // Master loop for generations
    for (int generation = 0; generation < NUMBER_OF_GENERATIONS; ++generation) {
        std::map<Pangolin::Region, std::vector<Pangolin>> newRegionalPopulations;

        // Process each region
        for (auto& [region, population] : regionalPopulations) {
            std::vector<Pangolin> newGeneration;

            // Define max resource consumption for the generation
            float maxResourceConsumption = environmentalResources[region] * 0.8;
            float resourcesConsumed = 0.0f;

            // Apply mortality
            Pangolin::applyMortality(population, MORTALITY_RATE, gen);

            // Calculate average fitness
            float avgFitness = Pangolin::calculateAverageFitness(population);

            // Skip reproduction if population is too small
            if (population.size() < 2) {
                continue;
            }

            // Begin reproduction (could be more sophisticated)
            for (Pangolin& parent1 : population) {
                // Generate offspring
                std::vector<Pangolin> offspring = parent1.reproduceWithStochasticAllocation(population, gen, maxResourceConsumption, resourcesConsumed, RESOURCE_CONSUMPTION_PER_OFFSPRING);

                // Allocate resources to offspring with stochastic allocation
                newGeneration.insert(newGeneration.end(), offspring.begin(), offspring.end());
            }

            newRegionalPopulations[region] = newGeneration; // Update generation
        }

        regionalPopulations = newRegionalPopulations;

        // Replenish resources and record observations
        for (auto& [region, population] : regionalPopulations) {
            float currentResources = environmentalResources[region];
            currentResources += RESOURCE_REPLENISH_AMOUNT + RESOURCE_GROWTH_RATE * (1 - (currentResources / CARRYING_CAPACITY)) * currentResources;
            environmentalResources[region] = std::min(currentResources, CARRYING_CAPACITY);

            // Log data to the output CSV file
            bool exists = !population.empty();
            float avgFitness = exists ? Pangolin::calculateAverageFitness(population) : 0.0f;
            outFile << region << "," << generation << "," << (exists ? 1 : 0) << "," << population.size() << "," << avgFitness << "\n";
        }
    }

    outFile.close();

    return 0;
}
