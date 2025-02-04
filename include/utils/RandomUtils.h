//
// Created by o.le on 04.02.25.
//

#ifndef RANDOMUTILS_H
#define RANDOMUTILS_H

/**
 * This namespace contains helper functions for random number generating.
 */
namespace RandomUtils
{
    int randomInt(int min, int max);

    /**
     * Create a random float.
     *
     * @param min   The minimal value of the random value.
     * @param max   The maximal value of the random value.
     * @return  The generated random value.
     */
    float randomFloat(int min, int max);
}

#endif //RANDOMUTILS_H
