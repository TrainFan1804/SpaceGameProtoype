//
// Created by o.le on 15.02.25.
//

#include "resources/ResourceInventory.h"

ResourceInventory::ResourceInventory()
    : _metal_amount(0), metal_amount(_metal_amount),
    _water_amount(0), water_amount(_water_amount)
{

}

void ResourceInventory::addResource(const PlanetUtils::PlanetType &type)
{
    switch (type)
    {
        case PlanetUtils::EARTH_LIKE: _metal_amount += 20; break;
        case PlanetUtils::TOXIC:  _metal_amount += 10; break;
        case PlanetUtils::HOT: _metal_amount += 30; break;
        case PlanetUtils::ICE: _metal_amount += 50; break;
    }
}

