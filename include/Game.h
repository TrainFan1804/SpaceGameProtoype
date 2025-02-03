//
// Created by o.le on 02.02.25.
//

#ifndef GAME_H
#define GAME_H

#include "GameScene.h"

#include <SFML/Graphics/RenderWindow.hpp>

#include "Renderer.h"

/**
 *  This is the game class. The game class contains everything that is related to
 *  the game itself. E.g. the input handling for the ship, collision detection
 *  with planets, rendering all the stuff in the current view.
 */
class Game
{
public:
    Game(Renderer &renderer);
    ~Game();
    void set_scene(GameScene *scene);
    void update();
    void render(sf::RenderWindow &window);
private:
    GameScene *_current_scene;
    Renderer _renderer;
};

#endif //GAME_H
