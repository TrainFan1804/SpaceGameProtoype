//
// Created by o.le on 09.02.25.
//

#ifndef PLANETTYPES_H
#define PLANETTYPES_H

#include <SFML/Graphics/Color.hpp>

namespace PlanetUtils
{
    enum PlanetType
    {
        EARTH_LIKE, TOXIC, HOT, ICE
    };

    sf::Color getPlanetColor(const PlanetType &planetType);
}

#endif //PLANETTYPES_H
