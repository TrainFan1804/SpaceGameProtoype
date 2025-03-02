//
// Created by o.le on 02.02.25.
//

#include "assets/Galaxy.h"

#include "assets/Planet.h"
#include "utils/RandomUtils.h"

#include "random"
#include "core/debug/Debug.h"
#include "utils/AssetUtils.h"

Galaxy Galaxy::createGalaxy()
{
    // this is ugly but it works
    static int galaxy_count = 1;
    unsigned int random_seed = RandomUtils::randomSeed();
    RandomUtils::setSeed(random_seed);
    int planet_amount = RandomUtils::randomInt(1, 10);

    /*
     * The string I put into the constructor once looked like this:
     *          "Galaxy " + galaxy_count++
     * And this didn't work because "Galaxy is interpreted as char* and
     * galaxy_count was a fck OFFSET in memory!!!!
     * This cost so many hours to fix...
     */
    Galaxy new_galaxy("Galaxy " + std::to_string(galaxy_count++), planet_amount);

    deb::Logger::getInstance().log("Creating Galaxy: " + new_galaxy.to_string());
    return new_galaxy;
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

std::vector<Planet> &Galaxy::getGalaxyPlanets()
{
    return _planets;
}

const std::string &Galaxy::getGalaxyName()
{
    return _galaxy_name;
}

const std::string Galaxy::to_string() const
{
    return "[name=" + _galaxy_name
            + ", planetamount=" + std::to_string(_planets.size())
            + "]";
}

void Galaxy::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (auto &planet: _planets)
    {
        target.draw(planet); // this will probably make a lot of weird things...
    }
}

void Galaxy::generatePlanets(int max_size)
{
    for (int i = 0; i < max_size; i++)
    {
        Planet new_planet("Planet " + std::to_string(i + 1),
            sf::Vector2f(100, 100),
            RandomUtils::randomPlanetType());
        // this got ugly very fast
        bool is_valid = false;
        while (!is_valid)
        {
            float pos_x = RandomUtils::randomFloat(0, 1000);
            float pos_y = RandomUtils::randomFloat(0, 1000);
            new_planet.setPos(sf::Vector2f(pos_x, pos_y));
            is_valid = isValidPos(new_planet);
        }
        _planets.push_back(new_planet);
        deb::Logger::getInstance().log("Putting new planet in Galaxy: " + new_planet.to_string());
    }
}

bool Galaxy::isValidPos(Planet &new_planet) const
{
    for (auto planet : _planets)
    {
        if (ats::calcDistanceBetweenAssets(new_planet, planet) <= 100)
        {
            return false;
        }
    }
    return true;
}
