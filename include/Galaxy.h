//
// Created by o.le on 02.02.25.
//

#ifndef GALAXY_H
#define GALAXY_H

#include "Planet.h"

#include "vector"
#include "string"

#include <SFML/Graphics/RenderWindow.hpp>

/**
 *  This class represent a galaxy in the game. A galaxy contains several
 *  planets the player can interact with. RN this is mainly a wrapper class for
 *  multiple planet instances.
 */
class Galaxy
{
public:
    Galaxy(const std::string &galaxy_name, int planet_amount);

    const std::string &getGalaxyName();

    std::vector<Planet> &getGalaxyPlanets();

    /**
     *  Will draw all planets of a galaxy into a window.
     *
     * @param window  The window the planets are draw into.
     */
    void drawGalaxy(sf::RenderWindow &window);
private:
    std::string _galaxy_name;
    std::vector<Planet> _planets;

    /**
     *  Will generate n planets with a seed.
     *  TODO Need to be optimized (like no overlapping, etc.) but rn it's fine.
     *
     * @param max_amount    The amount of planets that should be generated.
     * @param seed  The seed of the galaxy.
     */
    void generatePlanets(int max_amount, int seed);
};

#endif //GALAXY_H
