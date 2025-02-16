//
// Created by o.le on 15.02.25.
//

#include "resources/ResourceInventory.h"

int ResourceInventory::getResourceAmount(const res::ResourceType &res)
{
    return _resources[res];
}

void ResourceInventory::addResource(const res::ResourceType &res, int amount)
{
    _resources[res] += amount;
    if (_overlay)
        _overlay->setData(this);
}

bool ResourceInventory::removeResource(const res::ResourceType &res, int amount)
{
    if (amount >= _resources[res])
    {
        _resources[res] -= amount;
        return true;
    }
    return false;
}

void ResourceInventory::setOverlay(ResourceOverlay *overlay)
{
    _overlay = overlay;
}

