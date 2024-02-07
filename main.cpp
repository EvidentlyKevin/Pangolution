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
    const float resourceRenewalAmount = 7000.0f;
    const float resourceRenewalRate = 3.0f;
    const float resourceConsumptionPerOffspring = 1.0f;
    std::map<Pangolin::Region, std::vector<Pangolin>> regionalPopulations;
    std::map<Pangolin::Region, float> environmentalResources;
    std::random_device rd;
    std::mt19937 gen(rd());

    // Initialize populations and resources
    for (int i = 0; i < initialPopulationSize; ++i) {
        Pangolin::Region region = static_cast<Pangolin::Region>(i % Pangolin::NUM_REGIONS);
        regionalPopulations[region].push_back(Pangolin(region));
        environmentalResources[region] = 5000.0f; // Starting resource value for each region
    }

    std::ofstream outFile("pangolin_data.csv");
    //outFile << "Region,Generation,Exists,PopulationSize,AverageFitness,Resources\n";
    outFile << "Region,Generation,Exists,PopulationSize,AverageFitness\n";

    for (int generation = 0; generation < numberOfGenerations; ++generation) {
        std::map<Pangolin::Region, std::vector<Pangolin>> newRegionalPopulations;

        for (auto& [region, population] : regionalPopulations) {
            std::vector<Pangolin> newGeneration;

            // Apply mortality
            std::shuffle(population.begin(), population.end(), gen);
            population.erase(population.begin(), population.begin() + static_cast<int>(population.size() * mortalityRate));

            float totalFitness = 0.0f;
            for (const Pangolin& p : population) {
                totalFitness += p.getFitness();
            }
            float avgFitness = population.empty() ? 0 : totalFitness / population.size();

            if (population.size() < 2) {
                continue; // Skip reproduction if population is too small (will get hung otherwise)
            }

            for (Pangolin& parent1 : population) {
                std::uniform_int_distribution<> partnerDist(0, population.size() - 1);
                int partnerIndex;
                do {
                    partnerIndex = partnerDist(gen);
                } while (partnerIndex == &parent1 - &population[0]);

                Pangolin& partner = population[partnerIndex];
                std::vector<Pangolin> offspring = parent1.reproduce(partner);

                for (Pangolin& child : offspring) {
                    // Are there enough resources
                    if (environmentalResources[region] > (resourceConsumptionPerOffspring) * population.size()) {
                        environmentalResources[region] -= resourceConsumptionPerOffspring;
                        if (child.getFitness() >= avgFitness) {
                            newGeneration.push_back(child);
                        }
                    }
                }
            }

            newRegionalPopulations[region] = newGeneration;
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
                std::cout << "Region " << static_cast<int>(region) + 1 << " - Generation " << generation + 1 << ": Average Fitness of Sample = " << avgFitness << environmentalResources[region] << std::endl;
                outFile << "Exists," << population.size() << "," << avgFitness << "\n";
            }
        }
        std::cout << std::endl;
    }

    outFile.close();
    return 0;
}
