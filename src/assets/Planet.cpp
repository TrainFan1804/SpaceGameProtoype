//
// Created by o.le on 01.02.25.
//

#include "assets/Planet.h"

#include <SFML/Graphics/RenderTarget.hpp>

Planet::Planet(const std::string &planet_name, const sf::Vector2f &size,
    const pts::PlanetType &type)
    : _planet_name(planet_name), _type(type)
{
    _planet_rec.setSize(size);
    _planet_rec.setOrigin(_planet_rec.getSize().x / 2, _planet_rec.getSize().y / 2);
    _planet_rec.setFillColor(pts::getPlanetColor(type));
    fillPlanetDeposit();
}

const sf::Vector2f &Planet::getPos() const
{
    return _planet_rec.getPosition();
}

void Planet::setPos(const sf::Vector2f &pos)
{
    _planet_rec.setPosition(pos);
}

int Planet::harvestResource(const res::ResourceType &type, int amount)
{
    if (_planet_deposit.removeResource(type, amount))
    {
        return amount;
    }
    return 0;
}

const std::string Planet::to_string() const
{
    return "[name=" + _planet_name
            + ", type=" + pts::getPlanetTypeName(_type)
            + "]";
}

void Planet::fillPlanetDeposit()
{
    for (int res = 0; res < res::COUNT; res++)
    {
        int amount = res::generateResource(_type,
            static_cast<res::ResourceType>(res));
        _planet_deposit.addResource(static_cast<res::ResourceType>(res), amount);
    }
}

void Planet::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    _planet_rec.rotate(0.2f);
    target.draw(_planet_rec);
}
