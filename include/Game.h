//
// Created by o.le on 02.02.25.
//

#ifndef GAME_H
#define GAME_H

#include "Renderer.h"

#include <SFML/Graphics/RenderWindow.hpp>

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

    void setScene(GameScene *scene);

    /**
     * Will handle SFML events. Mostly key inputs.
     *
     * @param event The event to handle.
     */
    void handleEvent(sf::Event &event);

    /**
     * This method will be called to update the state of the current game scene.
     * Will be called every frame.
     */
    void update();

    /**
     *  This method will be called to render the current game scene.
     *  Will be called every frame.
     *
     * @param window    The window that is rendered to.
     */
    void render(sf::RenderWindow &window);
private:
    GameScene *_current_scene;
    Renderer _renderer;
};

#endif //GAME_H
