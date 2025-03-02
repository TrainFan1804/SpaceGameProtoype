//
// Created by o.le on 01.02.25.
//

#ifndef PLANET_H
#define PLANET_H

#include "PlanetTypes.h"
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
    Planet(const Planet &other)
        : _planet_name(other._planet_name), _type(other._type),
        _planet_rec(other._planet_rec),
        _planet_deposit(other._planet_deposit)
    {

    }
    Planet(const std::string &planet_name, const sf::Vector2f &size,
        const pts::PlanetType &type);
    const sf::Vector2f &getPos() const;
    void setPos(const sf::Vector2f &pos);
    int harvestResource(const res::ResourceType &type, int amount);
    const std::string to_string() const;
private:
    std::string _planet_name;
    pts::PlanetType _type;
    ResourceInventory _planet_deposit;
    mutable sf::RectangleShape _planet_rec;

    void fillPlanetDeposit();
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif //PLANET_H
