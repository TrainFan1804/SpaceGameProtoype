//
// Created by o.le on 15.02.25.
//

#ifndef ASSETUTILS_H
#define ASSETUTILS_H

#include <assets/PlayerShip.h>
#include <assets/Planet.h>

namespace ats
{
    /**
     * This need to be optimized especially when working with multiple planets in
     * the galaxy.
     *
     * @param player    The player ship that want to land.
     * @param target_planet The target planet that can be landed on.
     * @return  The real distance between the ship and a planet
     */
    float calcDistanceBetweenAssets(const PlayerShip &player,
        const Planet &target_planet);

    float calcDistanceBetweenAssets(const Planet &source,
        const Planet &target);
}

#endif //ASSETUTILS_H
