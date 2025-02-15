//
// Created by o.le on 02.02.25.
//

#ifndef GALAXY_H
#define GALAXY_H

#include <scenes/SpaceScene.h>

#include "Planet.h"

#include "vector"
#include "string"

#include <SFML/Graphics/RenderWindow.hpp>

/**
 *  This class represent a galaxy in the game. A galaxy contains several
 *  planets the player can interact with. RN this is mainly a wrapper class for
 *  multiple planet instances.
 */
class Galaxy : public sf::Drawable
{
public:
    /**
     * This static function will create a new RANDOM galaxy.
     *
     * @return  The created galaxy.
     */
    static Galaxy *createGalaxy();

    Galaxy(const std::string &galaxy_name);

    /**
     * This constructor will create a galaxy with the given amount of planets.
     * This constructor is not used rn but could come in handy when the game grows.
     *
     * @param galaxy_name   The name of the new galaxy.
     * @param planet_amount The amount of planets in the new galaxy.
     */
    Galaxy(const std::string &galaxy_name, int planet_amount);
    ~Galaxy() = default;
    Galaxy &operator=(Galaxy *galaxy);

    const std::string &getGalaxyName();
    std::vector<Planet> &getGalaxyPlanets();

private:
    std::string _galaxy_name;
    std::vector<Planet> _planets;

    /**
     *  Will generate n random generated planets.
     *
     * @param max_amount    The amount of planets that should be generated.
     */
    void generatePlanets(int max_amount);

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif //GALAXY_H
