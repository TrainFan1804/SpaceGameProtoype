//
// Created by o.le on 15.02.25.
//

/*
 * Wait! How can you do this? This isn't even dry!
 */

#include "utils/AssetUtils.h"

#include <cmath>

float ats::calcDistanceBetweenAssets(const PlayerShip &player, const Planet &target_planet)
{
    sf::Vector2f center_pos_player(player.getPos().x / 2,
        player.getPos().y / 2);
    sf::Vector2f center_pos_target_planet(target_planet.getPos().x / 2,
        target_planet.getPos().y / 2);

    float distance_x = center_pos_player.x - center_pos_target_planet.x;
    float distance_y = center_pos_player.y - center_pos_target_planet.y;

    float real_distance = std::sqrt(distance_x * distance_x + distance_y * distance_y);

    return real_distance;
}

float ats::calcDistanceBetweenAssets(const Planet &source, const Planet &target)
{
    sf::Vector2f center_pos_source(source.getPos().x / 2,
        source.getPos().y / 2);
    sf::Vector2f center_pos_target(target.getPos().x / 2,
        target.getPos().y / 2);

    float distance_x = center_pos_source.x - center_pos_target.x;
    float distance_y = center_pos_source.y - center_pos_target.y;

    float real_distance = std::sqrt(distance_x * distance_x + distance_y * distance_y);

    return real_distance;
}
