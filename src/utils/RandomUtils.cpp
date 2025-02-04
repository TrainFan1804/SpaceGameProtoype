//
// Created by o.le on 04.02.25.
//

#include "utils/RandomUtils.h"

#include <random>

int RandomUtils::randomInt(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution dist(min, max);
    return dist(gen);
}

float RandomUtils::randomFloat( int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(min, max);
    return dist(gen);
}
