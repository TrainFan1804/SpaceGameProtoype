//
// Created by o.le on 03.02.25.
//

#ifndef SPACESCENE_H
#define SPACESCENE_H

#include "GameScene.h"
#include "core/renderer/Renderer.h"
#include "assets/Galaxy.h"
#include "assets/PlayerShip.h"
#include "ui/GalaxyJumpUI.h"

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>


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
    sf::View &_camera;  // I should remove the reference and create it in the scene directly
    PlayerShip _player_ship;
    Galaxy _galaxy;
    GalaxyJumpUI _galaxy_jump_ui;
    bool _is_landing_pressed;
    bool _galaxy_map_pressed;
    bool _map_is_visible;
    bool _planet_in_range;
    sf::Font _font;
    sf::Text _text;
};

#endif //SPACESCENE_H
