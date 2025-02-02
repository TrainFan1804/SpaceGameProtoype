//
// Created by o.le on 01.02.25.
//

#include "Planet.h"

Planet::Planet()
{
}

Planet::Planet(const Planet &planet)
    : _planet_name(planet._planet_name), _planet_rec(planet._planet_rec)
{

}

Planet::Planet(const std::string &planet_name, const sf::Vector2f &size)
    : _planet_name(planet_name)
{
    _planet_rec.setSize(size);
    _planet_rec.setOrigin(_planet_rec.getSize().x / 2, _planet_rec.getSize().y / 2);
    _planet_rec.setFillColor(sf::Color::Green);
}

const sf::Vector2f &Planet::getPos() const
{
    return _planet_rec.getPosition();
}

void Planet::setPos(const sf::Vector2f &pos)
{
    _planet_rec.setPosition(pos);
}

void Planet::draw(sf::RenderWindow &window)
{
    _planet_rec.rotate(0.2f);
    window.draw(_planet_rec);
}
