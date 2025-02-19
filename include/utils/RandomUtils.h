//
// Created by o.le on 04.02.25.
//

#ifndef RANDOMUTILS_H
#define RANDOMUTILS_H

#include "assets/PlanetTypes.h"
#include "resources/ResourceType.h"

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

    /**
     * @param min
     * @param max
     * @return
     * @note    This is based on the saved seed!
     */
    int randomInt(unsigned int min, unsigned int max);

    /**
     * Create a random float.
     *
     * @param min   The minimal value of the random value.
     * @param max   The maximal value of the random value.
     * @return  The generated random value. The returned value will be ANY value
     * between min and max (excluded). So values like 2.34 are possible.
     */
    float randomFloat(unsigned int min, unsigned int max);

    pts::PlanetType randomPlanetType();

    /**
     * Will generate a random amount of the given resource type.
     * Because the amount of resources are constraint to the planet type this is
     * given as well.
     *
     * @param min   The minimal amount of resource generating.
     * @param max   The maximal amount of resource generating.
     * @return  The amount of resource.
     * @note    This will generate REAL random numbers WITHOUT a seed. So when
     * a galaxy is generated on a seed the planets may be the same but the
     * amount of resource on them are different. And that ok.
     */
    int randomResourceAmount(int min, int max);

    res::ResourceType randomResourceType();
}

#endif //RANDOMUTILS_H
