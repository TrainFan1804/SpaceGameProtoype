//
// Created by o.le on 01.02.25.
//

#ifndef PLANET_H
#define PLANET_H

#include "PlanetUtils.h"
#include "resources/ResourceInventory.h"

#include <string>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

/**
 *  This class represent a planet in the game.
 */
class Planet : public sf::Drawable
{
public:
    Planet() = default;
    ~Planet() = default;
    Planet(const Planet &other);
    Planet(const std::string &planet_name, const sf::Vector2f &size,
        const PlanetUtils::PlanetType &type);
    const sf::Vector2f &getPos() const;
    void setPos(const sf::Vector2f &pos);
    int harvestResource(const Resource::ResourceType &type);
private:
    std::string _planet_name;
    ResourceInventory _planet_deposit;
    mutable sf::RectangleShape _planet_rec;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif //PLANET_H
