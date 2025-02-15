//
// Created by o.le on 15.02.25.
//

#ifndef RESOURCETYPE_H
#define RESOURCETYPE_H

#include <string>

namespace Resource
{
    enum ResourceType
    {
        METAL, WATER, ORGANIC
    };

    std::string getResourceTypeName(const ResourceType &type);
}

#endif //RESOURCETYPE_H
