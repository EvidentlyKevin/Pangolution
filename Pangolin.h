#ifndef PANGOLIN_H
#define PANGOLIN_H
#include <vector>

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

    // Incomplete
    float getGene(GeneType geneType) const;
    void setGene(GeneType geneType, float value);
    int getLocation() const;
    void setLocation(Region newLocation);

private:
    std::vector<float> genes;
    Region location;
};

#endif // PANGOLIN_H
