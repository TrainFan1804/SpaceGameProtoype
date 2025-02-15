//
// Created by o.le on 15.02.25.
//

#ifndef RESOURCEHOLDER_H
#define RESOURCEHOLDER_H

#include <unordered_map>

#include "ResourceType.h"
#include "assets/PlanetUtils.h"
#include "ui/ResourceOverlay.h"

class ResourceOverlay;

/**
 * This class represent the players resource inventory.
 *
 * To update the ResourceOverlay directly when collection / removing resources
 * from the inventory this class contains a pointer to the overlay that will be
 * updated the overlay directly when the internal state of the inventory changes.
 * I just added this because I don't want to handle the overlay manually.
 */
class ResourceInventory
{
public:
    int getResourceAmount(const Resource::ResourceType &res);

    /**
     * Adding resources to the inventory based on the planet type that is injected.
     *
     * @param type  The type of the planet that is farmed.
     */
    void addResource(const Resource::ResourceType &res, int amount);

    bool removeResource(const Resource::ResourceType &res, int amount);

    /**
     * This will set the overlay that is observing the inventory. Can set on
     * overlay at a time.
     *
     * @param overlay   The overlay that should be informed when the internal
     * state is updated.
     */
    void setOverlay(ResourceOverlay *overlay);
private:
    std::unordered_map<Resource::ResourceType, int> _resources;

    ResourceOverlay *_overlay;
};

#endif //RESOURCEHOLDER_H
