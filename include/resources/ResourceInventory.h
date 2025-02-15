//
// Created by o.le on 15.02.25.
//

#ifndef RESOURCEHOLDER_H
#define RESOURCEHOLDER_H

#include "assets/PlanetUtils.h"

/**
 * This class represent the players resource inventory.
 */
class ResourceInventory
{
public:
    const unsigned int &metal_amount;
    const unsigned int &water_amount;

    ResourceInventory();

    /**
     * Adding resources to the inventory based on the planet type that is injected.
     *
     * @param type  The type of the planet that is farmed.
     */
    void addResource(const PlanetUtils::PlanetType &type);
private:
    unsigned int _metal_amount;
    unsigned int _water_amount;
};

#endif //RESOURCEHOLDER_H
