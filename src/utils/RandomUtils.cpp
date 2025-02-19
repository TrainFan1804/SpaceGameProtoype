//
// Created by o.le on 04.02.25.
//

#include "utils/RandomUtils.h"
#include "resources/ResourceType.h"

#include <random>

namespace
{
    std::mt19937_64 gen(std::random_device{}());
}

void RandomUtils::setSeed(unsigned int seed)
{
    gen.seed(seed);
}

unsigned int RandomUtils::randomSeed()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    return gen();
}

int RandomUtils::randomInt(unsigned int min, unsigned int max)
{
    std::uniform_int_distribution dist(min, max);
    return dist(gen);
}

float RandomUtils::randomFloat(unsigned int min, unsigned int max)
{
    std::uniform_real_distribution<float >dist(min, max);
    return dist(gen);
}

pts::PlanetType RandomUtils::randomPlanetType()
{
    std::uniform_int_distribution dist(0, pts::COUNT - 1);
    return static_cast<pts::PlanetType>(dist(gen));
}

int RandomUtils::randomResourceAmount(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution dist(min, max);
    return dist(gen);
}

res::ResourceType RandomUtils::randomResourceType()
{
    // int_distribution will create a value between a and b (included) so
    // COUNT - 1
    std::uniform_int_distribution dist(0, res::COUNT - 1);
    return static_cast<res::ResourceType>(dist(gen));
}
