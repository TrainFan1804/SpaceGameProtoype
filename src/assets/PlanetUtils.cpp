//
// Created by o.le on 09.02.25.
//

#include "assets/PlanetUtils.h"

sf::Color PlanetUtils::getPlanetColor(const PlanetType &type)
{
    switch (type)
    {
    case EARTH_LIKE: return sf::Color::Green;
    case TOXIC: return sf::Color::Magenta;
    case HOT: return sf::Color::Red;
    case ICE: return sf::Color::Cyan;
    }
}
