//
// Created by o.le on 01.02.25.
//

#include "assets/PlayerShip.h"
#include "assets/Planet.h"

#include <cmath>

PlayerShip::PlayerShip(const sf::Vector2f &size)
{
    _ship_rec.setSize(size);
    _ship_rec.setOrigin(_ship_rec.getSize().x / 2, _ship_rec.getSize().y / 2);
}

const sf::Vector2f &PlayerShip::getPos() const
{
    return _ship_rec.getPosition();
}

void PlayerShip::setPos(const sf::Vector2f &pos)
{
    _ship_rec.setPosition(pos);
}

void PlayerShip::move(const float x_dir, const float y_dir)
{
    sf::Vector2f moving_vec(x_dir, y_dir);
    float length = std::sqrt(moving_vec.x * moving_vec.x + moving_vec.y * moving_vec.y);
    moving_vec /= length;

    _ship_rec.move(moving_vec * 10.f);
    /*
     *  The next line is a bit complex, so I will explain what it's doing:
     *  To rotate an object we need to determine what the targeted angle will be.
     *  To calculate the targeted angle we will use the atan2 that will calculate
     *  the angle between y and x of moving_vec. Because the result of std::atan2
     *  is in radians, 180.f / M_PI will convert it into degree.
     *  90.f because I want the upper edge as the front of the spaceship otherwise
     *  it would be the right edge.
     */
    float targetAngle = std::atan2(moving_vec.y, moving_vec.x) * 180.0f / M_PI + 90.f;
    float currentAngle = _ship_rec.getRotation();

    /*
     *  This will just make sure the ship is always moving the "shortest" way.
     *  Just to prevent weird spinning behaviour.
     */
    if (std::abs(targetAngle - currentAngle) > 180)
    {
        if (targetAngle > currentAngle)
            currentAngle += 360;
        else
            targetAngle += 360;
    }

    // just calculates the angle that must be rotated.
    constexpr float rotationSpeed = 5.f;    //
    float newAngle = currentAngle + (targetAngle - currentAngle) * (rotationSpeed / 100.0f);
    _ship_rec.setRotation(newAngle);
}


void PlayerShip::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(_ship_rec);
}

float calculateDistanceShipToPlanet(const PlayerShip &player, const Planet &target_planet)
{
    sf::Vector2f center_pos_player(player.getPos().x / 2, player.getPos().y / 2);
    sf::Vector2f center_pos_target_planet(target_planet.getPos().x / 2, target_planet.getPos().y / 2);

    float distance_x = center_pos_player.x - center_pos_target_planet.x;
    float distance_y = center_pos_player.y - center_pos_target_planet.y;

    float real_distance = std::sqrt(distance_x * distance_x + distance_y * distance_y);

    return real_distance;
}
