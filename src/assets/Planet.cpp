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
    const PlanetUtils::PlanetType &type)
    : _planet_name(planet_name)
{
    _planet_rec.setSize(size);
    _planet_rec.setOrigin(_planet_rec.getSize().x / 2, _planet_rec.getSize().y / 2);
    _planet_rec.setFillColor(PlanetUtils::getPlanetColor(type));
    // TODO why is the next line executed multiple times? Probably is something
    // wrong with the copy or move constructor...
    _planet_deposit.addResource(Resource::ResourceType::METAL, 10);
}

const sf::Vector2f &Planet::getPos() const
{
    return _planet_rec.getPosition();
}

void Planet::setPos(const sf::Vector2f &pos)
{
    _planet_rec.setPosition(pos);
}

int Planet::harvestResource(const Resource::ResourceType &type)
{
    int temp = _planet_deposit.getResourceAmount(type);
    if (_planet_deposit.removeResource(type, temp))
    {
        return temp;
    }
    return 0;
}

void Planet::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    _planet_rec.rotate(0.2f);
    target.draw(_planet_rec);
}
