//
// Created by o.le on 09.02.25.
//

#include "assets/PlanetTypes.h"

sf::Color pts::getPlanetColor(const PlanetType &type)
{
    switch (type)
    {
    case EARTH_LIKE: return sf::Color::Green;
    case TOXIC: return sf::Color::Magenta;
    case HOT: return sf::Color::Red;
    case ICE: return sf::Color::Cyan;
    }
    return static_cast<sf::Color>(NULL);    // this should never be returned
}

std::string pts::getPlanetTypeName(const PlanetType &type)
{
    switch (type)
    {
    case EARTH_LIKE: return "EARTH_LIKE";
    case TOXIC: return "TOXIC";
    case HOT: return "HOT";
    case ICE: return "ICE";
    }
    return "NULL"; // shouldn't happen. Ever.
}
