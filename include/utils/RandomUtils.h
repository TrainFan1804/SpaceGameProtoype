//
// Created by o.le on 04.02.25.
//

#ifndef RANDOMUTILS_H
#define RANDOMUTILS_H

#include "assets/PlanetUtils.h"

/**
 * This namespace contains helper functions for random number generating.
 * All random functions beside randomSeed() are working with the same seed that
 * can be set with setSeed(unsigned int). So if you set the seed with setSeed
 * all random functions will generate a seed based on the seed that was set.
 * To generate a random seed use randomSeed. Will ALWAYS generate a new seed.
 */
namespace RandomUtils
{
    void setSeed(unsigned int seed);

    unsigned int randomSeed();

    int randomInt(unsigned int min, unsigned int max);

    /**
     * Create a random float.
     *
     * @param min   The minimal value of the random value.
     * @param max   The maximal value of the random value.
     * @return  The generated random value.
     */
    float randomFloat(unsigned int min, unsigned int max);

    PlanetUtils::PlanetType randomPlanetType();
}

#endif //RANDOMUTILS_H
