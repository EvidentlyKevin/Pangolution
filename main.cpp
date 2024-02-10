#include "Pangolin.h"
#include "Utility.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <random> //fix this

int main() {
    const int initialPopulationSize = 40;
    const int numberOfGenerations = 16;
    const float mortalityRate = 0.1f;
    const float resourceRenewalAmount = 100.0f;
    const float resourceRenewalRate = 2.0f;
    const float resourceConsumptionPerOffspring = 1.0f;
    std::map<Pangolin::Region, std::vector<Pangolin>> regionalPopulations;
    std::map<Pangolin::Region, float> environmentalResources;
    std::random_device rd;
    std::mt19937 gen(rd());

    // Initialize populations and resources
    for (int i = 0; i < initialPopulationSize; ++i) {
        Pangolin::Region region = static_cast<Pangolin::Region>(i % Pangolin::NUM_REGIONS);
        regionalPopulations[region].push_back(Pangolin(region));
        environmentalResources[region] = 500.0f; // Starting resource value for each region
    }

    // Init the output CSV file
    std::ofstream outFile("pangolin_data.csv");
    //outFile << "Region,Generation,Exists,PopulationSize,AverageFitness,Resources\n";
    outFile << "Region,Generation,Exists,PopulationSize,AverageFitness\n";

    // Begin the master loop
    for (int generation = 0; generation < numberOfGenerations; ++generation) {
        std::map<Pangolin::Region, std::vector<Pangolin>> newRegionalPopulations;

        // Make region specific loop
        for (auto& [region, population] : regionalPopulations) {
            std::vector<Pangolin> newGeneration;

            // Apply mortality by randomly eliminating a fraction of Pangolins
            std::shuffle(population.begin(), population.end(), gen);
            population.erase(population.begin(), population.begin() + static_cast<int>(population.size() * mortalityRate));

            // Poll for the region populations average fitness
            float totalFitness = 0.0f;
            for (const Pangolin& p : population) {
                totalFitness += p.getFitness();
            }
            float avgFitness = population.empty() ? 0 : totalFitness / population.size();

            if (population.size() < 2) {
                continue; // Skip reproduction if population is too small (will get hung otherwise)
            }

            // Begin generational reproduction
            for (Pangolin& parent1 : population) {
                // Create a list of potential partners (excluding the current parent)
                std::vector<Pangolin> potentialPartners;
                for (Pangolin& other : population) {
                    if (&other != &parent1) {
                        potentialPartners.push_back(other);
                    }
                }

                std::vector<Pangolin> offspring = parent1.reproduce(potentialPartners);

                // **INSPECT**
                for (Pangolin& child : offspring) {
                    // Are there enough resources?
                    if (environmentalResources[region] > (resourceConsumptionPerOffspring) * population.size()) {
                        environmentalResources[region] -= resourceConsumptionPerOffspring;
                        if (child.getFitness() >= avgFitness) {
                            newGeneration.push_back(child);
                        }
                    }
                }
            }

            newRegionalPopulations[region] = newGeneration; // Overwrite old generation
        }

        regionalPopulations = newRegionalPopulations;

        // Replenish environmental resources and record observations
        for (auto& [region, population] : regionalPopulations) {
            environmentalResources[region] *= resourceRenewalRate; // Replenish resources

            outFile << static_cast<int>(region) + 1 << "," << generation + 1 << ",";
            if (population.empty()) {
                std::cout << "Region " << static_cast<int>(region) + 1 << " - Generation " << generation + 1 << ": Population is Extinct." << std::endl;
                outFile << "Extinct,0,0\n";
                // outFile << "Extinct,0,0,0\n";
            } else {
                std::cout << "Region " << static_cast<int>(region) + 1 << " - Generation " << generation + 1 << ": Population Size = " << population.size() << std::endl;
                float avgFitness = calculateAverageFitnessSample(population, 10);
                std::cout << "Region " << static_cast<int>(region) + 1 << " - Generation " << generation + 1 << ": Average Fitness of Sample = " << avgFitness << /*environmentalResources[region] <<*/std::endl;
                outFile << "Exists," << population.size() << "," << avgFitness << "\n";
            }
        }
        std::cout << std::endl;
    }

    outFile.close();
    return 0;
}
