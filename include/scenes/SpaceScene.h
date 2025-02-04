//
// Created by o.le on 03.02.25.
//

#ifndef SPACESCENE_H
#define SPACESCENE_H

#include "GameScene.h"
#include "assets/Galaxy.h"
#include "assets/PlayerShip.h"
#include "Renderer.h"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

/**
 * The SpaceScene could be called the "default" scene because that is the scene
 * the player will spend probably most of his time. The SpaceScene represent
 * the state of the game where the player can control his ship and explore
 * different systems.
 */
class SpaceScene : public GameScene
{
public:
    SpaceScene(sf::View &init_camera);
    void eventHandling(sf::Event &event) override;
    void play() override;
    void setupRenderer(Renderer &renderer) override;
    sf::View &getCamera() const override;
private:
    sf::View &_camera;
    PlayerShip _player_ship;
    Galaxy _galaxy;
    bool _is_landing_pressed;
    bool _planet_in_range;
    sf::Font _font;
    sf::Text _text;
};

#endif //SPACESCENE_H
