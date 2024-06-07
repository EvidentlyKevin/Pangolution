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
            std::shuffle(population.begin(), population.end(), gen);
            population.erase(population.begin(), population.begin() + static_cast<int>(population.size() * MORTALITY_RATE));

            // Calculate average fitness
            float totalFitness = 0.0f;
            for (const Pangolin& p : population) {
                totalFitness += p.getFitness();
            }
            float avgFitness = population.empty() ? 0.0f : totalFitness / population.size();

            // Skip reproduction if population is too small
            if (population.size() < 2) {
                continue;
            }

            // Begin reproduction (could be more sophisticated)
            for (Pangolin& parent1 : population) {
                // Create list of potential partners (excluding the current parent)
                std::vector<Pangolin> potentialPartners;
                for (Pangolin& other : population) {
                    if (&other != &parent1) {
                        potentialPartners.push_back(other);
                    }
                }

                // Generate offspring
                std::vector<Pangolin> offspring = parent1.reproduce(potentialPartners);

                // Sort offspring by fitness
                std::sort(offspring.begin(), offspring.end(), [](const Pangolin& a, const Pangolin& b) {
                    return a.getFitness() > b.getFitness();
                });

                // Allocate resources to offspring with stochastic allocation
                std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
                for (Pangolin& child : offspring) {
                    float probability = (maxResourceConsumption - resourcesConsumed) / maxResourceConsumption;
                    if (resourcesConsumed + RESOURCE_CONSUMPTION_PER_OFFSPRING <= maxResourceConsumption &&
                        distribution(gen) < probability) {
                        environmentalResources[region] -= RESOURCE_CONSUMPTION_PER_OFFSPRING;
                        resourcesConsumed += RESOURCE_CONSUMPTION_PER_OFFSPRING;
                        newGeneration.push_back(child);
                    } else if (resourcesConsumed + RESOURCE_CONSUMPTION_PER_OFFSPRING > maxResourceConsumption) {
                        break; // Stop if resources are depleted
                    }
                }

            }

            newRegionalPopulations[region] = newGeneration; // Update generation
        }

        regionalPopulations = newRegionalPopulations;

        //WHAT IS HAPPENING HERE?
        // Replenish resources and record observations
        for (auto& [region, population] : regionalPopulations) {
            float currentResources = environmentalResources[region];
            currentResources += RESOURCE_REPLENISH_AMOUNT;
            currentResources = currentResources + RESOURCE_GROWTH_RATE * currentResources * (1 - currentResources / CARRYING_CAPACITY);
            environmentalResources[region] = currentResources;
        //WHAT IS HAPPENING HERE?

            outFile << static_cast<int>(region) + 1 << "," << generation + 1 << ",";
            if (population.empty()) {
                std::cout << "Region " << static_cast<int>(region) + 1 << " - Generation " << generation + 1 << ": Population is Extinct." << std::endl;
                outFile << "Extinct,0,0\n";
            } else {
                std::cout << "Region " << static_cast<int>(region) + 1 << " - Generation " << generation + 1 << ": Population Size = " << population.size() << std::endl;
                float avgFitness = calculateAverageFitnessSample(population, 10);
                std::cout << "Region " << static_cast<int>(region) + 1 << " - Generation " << generation + 1 << ": Average Fitness of Sample = " << avgFitness << std::endl;
                outFile << "Exists," << population.size() << "," << avgFitness << "\n";
            }
        }
        std::cout << std::endl;
    }

    outFile.close();
    return 0;
}
