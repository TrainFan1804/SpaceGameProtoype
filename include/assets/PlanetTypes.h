//
// Created by o.le on 09.02.25.
//

#ifndef PLANETTYPES_H
#define PLANETTYPES_H

#include <string>
#include <SFML/Graphics/Color.hpp>

namespace pts
{
    enum PlanetType
    {
        EARTH_LIKE, TOXIC, HOT, ICE, COUNT
    };

    sf::Color getPlanetColor(const PlanetType &planetType);
    std::string getPlanetTypeName(const PlanetType &type);
}

#endif //PLANETTYPES_H
