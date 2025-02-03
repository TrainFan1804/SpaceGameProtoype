//
// Created by o.le on 02.02.25.
//

#include "Galaxy.h"
#include "Planet.h"

#include <random>

Galaxy::Galaxy(const std::string &galaxy_name, int planet_amount)
    : _galaxy_name(galaxy_name)
{
    _planets.reserve(planet_amount);
    generatePlanets(planet_amount, 124); // TODO seed should be randomized
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
        target.draw(planet);    // this will probably make alot of weird things...
    }
}

void Galaxy::generatePlanets(int max_size, int seed)
{
    std::mt19937 rng(seed);
    std::uniform_real_distribution<float> posDist(0, 1500);
    for (int i = 0; i < max_size; i++)
    {
        Planet newPlanet("Planet " + std::to_string(i), sf::Vector2f(100, 100));
        newPlanet.setPos(sf::Vector2f(posDist(rng), posDist(rng)));
        _planets.push_back(newPlanet);
    }
}
