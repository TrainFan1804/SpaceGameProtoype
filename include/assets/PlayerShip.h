//
// Created by o.le on 01.02.25.
//

#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

class Planet;

/**
 *  This class represent the players ship in the game.
 */
class PlayerShip : public sf::Drawable
{
public:
    PlayerShip(const sf::Vector2f &size);

    const sf::Vector2f &getPos() const;

    void setPos(const sf::Vector2f &pos);

    /**
     * Move the ship relatively from his current position in x-, y-direction.
     *
     * @param   x_dir Will always be 1, -1 or 0 because this method works with normalized vectors.
     * @param   y_dir Will always be 1, -1 or 0 because this method works with normalized vectors.
     */
    void move(const float x_dir, const float y_dir);
private:
    sf::RectangleShape _ship_rec;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

/**
 * This need to be optimized expecially when working with multiple planets in
 * the galaxy.
 *
 * @param player    The player ship that want to land.
 * @param target_planet The target planet that can be landed on.
 * @return  The real distance between the ship and a planet
 */
float calculateDistanceShipToPlanet(const PlayerShip &player, const Planet &target_planet);

#endif //PLAYERSHIP_H
