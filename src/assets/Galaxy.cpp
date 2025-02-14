//
// Created by o.le on 02.02.25.
//

#include "assets/Galaxy.h"

#include <iostream>
#include <ostream>

#include "assets/Planet.h"
#include "utils/RandomUtils.h"

#include "random"

Galaxy *Galaxy::createGalaxy()
{
    // this is ugly but it works
    static int galaxy_count = 1;
    unsigned int random_seed = RandomUtils::randomSeed();
    std::cout << random_seed << std::endl;
    RandomUtils::setSeed(random_seed);
    int planet_amount = RandomUtils::randomInt(1, 10);
    return new Galaxy("Galaxy" + ++galaxy_count, planet_amount);
}

Galaxy::Galaxy(const std::string &galaxy_name)
    : Galaxy(galaxy_name, RandomUtils::randomInt(1, 10))
{
}

Galaxy::Galaxy(const std::string &galaxy_name, int planet_amount)
    : _galaxy_name(galaxy_name)
{
    _planets.reserve(planet_amount);
    generatePlanets(planet_amount);
}

Galaxy &Galaxy::operator=(Galaxy *galaxy)
{
    _galaxy_name = galaxy->_galaxy_name;
    _planets = galaxy->_planets;

    return *this;
}


std::vector<Planet> &Galaxy::getGalaxyPlanets()
{
    return _planets;
}

const std::string &Galaxy::getGalaxyName()
{
    return _galaxy_name;
}

void Galaxy::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (auto &planet: _planets)
    {
        target.draw(planet); // this will probably make alot of weird things...
    }
}

void Galaxy::generatePlanets(int max_size)
{
    for (int i = 0; i < max_size; i++)
    {
        Planet newPlanet("Planet " + i, sf::Vector2f(100, 100), RandomUtils::randomPlanetType());
        float pos_x = RandomUtils::randomFloat(0, 500);
        float pos_y = RandomUtils::randomFloat(0, 500);
        newPlanet.setPos(sf::Vector2f(pos_x, pos_y));
        _planets.push_back(newPlanet);
    }
}
