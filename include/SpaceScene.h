//
// Created by o.le on 03.02.25.
//

#ifndef SPACESCENE_H
#define SPACESCENE_H

#include "GameScene.h"
#include "Galaxy.h"
#include "PlayerShip.h"
#include "Renderer.h"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class SpaceScene : public GameScene
{
public:
    SpaceScene(sf::View &init_camera);
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
