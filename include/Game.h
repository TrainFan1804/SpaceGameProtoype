//
// Created by o.le on 02.02.25.
//

#ifndef GAME_H
#define GAME_H

#include <Galaxy.h>
#include <PlayerShip.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

/**
 *  This is the game class. The game class contains everything that is related to
 *  the game itself. E.g. the input handling for the ship, collision detection
 *  with planets, rendering all the stuff in the current view.
 */
class Game
{
public:
    Game(sf::View &init_view);
    void update();
    void render(sf::RenderWindow &window);
private:
    sf::View &_view;
    PlayerShip _player_ship;
    Galaxy _galaxy;
    bool _is_landing_pressed;
    bool _planet_in_range;
    sf::Font _font;
    sf::Text _text;
};

#endif //GAME_H
