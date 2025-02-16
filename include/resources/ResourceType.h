//
// Created by o.le on 15.02.25.
//

#ifndef RESOURCETYPE_H
#define RESOURCETYPE_H

#include <array>
#include <string>

#include "assets/PlanetTypes.h"

namespace res
{
    enum ResourceType
    {
        METAL, WATER, ORGANIC, COUNT
    };

    std::string getResourceTypeName(const ResourceType &type);

    int generateResource(const pts::PlanetType &planet, const ResourceType &res);

    constexpr std::array<ResourceType, static_cast<std::size_t>(COUNT)> RESOURCE_TYPES = {
        METAL,
        WATER,
        ORGANIC
    };
}

#endif //RESOURCETYPE_H
