//
// Created by o.le on 15.02.25.
//

#ifndef RESOURCETYPE_H
#define RESOURCETYPE_H

#include <string>

#include "assets/PlanetTypes.h"

namespace res
{
    enum ResourceType
    {
        METAL, WATER, ORGANIC, COUNT
    };

    std::string getResourceTypeName(const ResourceType &type);

    /**
     * This method is just used when a planet is generated and need to be filled
     * with any resources.
     *
     * @param planet    Because each planet type has a different inventory the
     * type need to be injected into this function.
     * @param res   The type of resource that should be created.
     * @return  The amount of the given resource type based on the planet type.
     */
    int generateResource(const pts::PlanetType &planet, const ResourceType &res);
}

#endif //RESOURCETYPE_H
