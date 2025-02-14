//
// Created by o.le on 04.02.25.
//

#include "utils/RandomUtils.h"

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
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return gen();
}

int RandomUtils::randomInt(unsigned int min, unsigned int max)
{
    // gen.seed(124);
    // static std::random_device rd;
    // static std::mt19937 gen(rd());
    std::uniform_int_distribution dist(min, max);
    return dist(gen);
}

float RandomUtils::randomFloat(unsigned int min, unsigned int max)
{
    // static std::random_device rd;
    // static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(min, max);
    return dist(gen);
}

PlanetUtils::PlanetType RandomUtils::randomPlanetType()
{
    // static std::random_device rd;
    // static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(0, 4);
    return static_cast<PlanetUtils::PlanetType>(dist(gen));
}

