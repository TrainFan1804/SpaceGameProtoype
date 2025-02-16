//
// Created by o.le on 15.02.25.
//

#include "resources/ResourceType.h"
#include "utils/RandomUtils.h"

#define ru RandomUtils

std::string res::getResourceTypeName(const ResourceType &type)
{
    switch (type)
    {
    case METAL: return "METAL";
    case WATER: return "WATER";
    case ORGANIC: return "ORGANIC";
    }
}

int res::generateResource(const pts::PlanetType &planet, const ResourceType &res)
{
    switch (planet)
    {
    case pts::EARTH_LIKE:
        switch (res)
        {
        case METAL: return ru::randomResourceAmount(25, 75);
        case WATER: return ru::randomResourceAmount(25, 75);
        case ORGANIC: return ru::randomResourceAmount(25, 75);
        }
        break;
    case pts::TOXIC:
        switch (res)
        {
        case METAL: return ru::randomResourceAmount(75, 100);
        case WATER: return ru::randomResourceAmount(25, 50);
        case ORGANIC: return ru::randomResourceAmount(25, 75);
        }
        break;
    case pts::HOT:
        switch (res)
        {
        case METAL: return ru::randomResourceAmount(75, 100);
        case WATER: return ru::randomResourceAmount(0, 25);
        case ORGANIC: return ru::randomResourceAmount(0, 25);
        }
        break;
    case pts::ICE:
        switch (res)
        {
        case METAL: return ru::randomResourceAmount(25, 50);
        case WATER: return ru::randomResourceAmount(75, 100);
        case ORGANIC: return ru::randomResourceAmount(25, 50);
        }
        break;
    }
    return 0;   // this is redundant but just in case
}
