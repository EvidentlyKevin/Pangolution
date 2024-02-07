#include <vector>
#include <random>
#include <algorithm>
#include "Pangolin.h"

float calculateAverageFitnessSample(const std::vector<Pangolin>& population, size_t sampleSize);

// Not used (can delete)
float calculatePopulationModifier(int populationSize, int carryingCapacity, int generation);

int calculateCarryingCapacity(float resource);

// int resourceRenewalRate(int);