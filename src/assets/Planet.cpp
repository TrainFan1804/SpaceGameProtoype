//
// Created by o.le on 01.02.25.
//

#include "assets/Planet.h"

#include <SFML/Graphics/RenderTarget.hpp>

Planet::Planet(const Planet &other)
    : _planet_name(other._planet_name), _planet_rec(other._planet_rec)
    , _planet_deposit(other._planet_deposit)
{

}

Planet::Planet(const std::string &planet_name, const sf::Vector2f &size,
    const pts::PlanetType &type)
    : _planet_name(planet_name)
{
    _planet_rec.setSize(size);
    _planet_rec.setOrigin(_planet_rec.getSize().x / 2, _planet_rec.getSize().y / 2);
    _planet_rec.setFillColor(pts::getPlanetColor(type));
    fillPlanetDeposit(type);
}

const sf::Vector2f &Planet::getPos() const
{
    return _planet_rec.getPosition();
}

void Planet::setPos(const sf::Vector2f &pos)
{
    _planet_rec.setPosition(pos);
}

int Planet::harvestResource(const res::ResourceType &type)
{
    int temp = _planet_deposit.getResourceAmount(type);
    if (_planet_deposit.removeResource(type, temp))
    {
        return temp;
    }
    return 0;
}

void Planet::fillPlanetDeposit(const pts::PlanetType &type)
{
    for (auto res : res::RESOURCE_TYPES)
    {
        int amount = res::generateResource(type, res);
        _planet_deposit.addResource(res, amount);
    }
}

void Planet::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    _planet_rec.rotate(0.2f);
    target.draw(_planet_rec);
}
