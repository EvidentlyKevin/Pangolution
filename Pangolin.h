#ifndef PANGOLIN_H
#define PANGOLIN_H
#include <vector>
#include <random>

class Pangolin {
public:
    enum Region { Region1, Region2, Region3, Region4, NUM_REGIONS };

    enum GeneType {
        SIZE = 0,
        SPEED,
        COLOR,
        NUM_GENES
    };

    static const int GeneCount = NUM_GENES;

    Pangolin(Region region);
    std::vector<Pangolin> reproduce(const std::vector<Pangolin>& potentialPartners) const;
    float getFitness() const;

    float getGene(GeneType geneType) const;
    void setGene(GeneType geneType, float value);
    int getLocation() const;
    void setLocation(Region newLocation);

    static void applyMortality(std::vector<Pangolin>& population, float mortalityRate, std::mt19937& gen);
    static float calculateAverageFitness(const std::vector<Pangolin>& population);
    std::vector<Pangolin> reproduceWithStochasticAllocation(const std::vector<Pangolin>& population, std::mt19937& gen, float maxResourceConsumption, float& resourcesConsumed, float resourceConsumptionPerOffspring) const;

private:
    std::vector<float> genes;
    Region location;
};

#endif // PANGOLIN_H
