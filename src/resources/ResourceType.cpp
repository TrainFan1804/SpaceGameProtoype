//
// Created by o.le on 15.02.25.
//

#include "resources/ResourceType.h"

std::string Resource::getResourceTypeName(const ResourceType &type)
{
    switch (type)
    {
    case METAL: return "METAL";
    case WATER: return "WATER";
    case ORGANIC: return "ORGANIC";
    }
}
