//
// Created by o.le on 02.02.25.
//

#ifndef GAME_H
#define GAME_H

#include "core/renderer/Renderer.h"

#include <SFML/Graphics/RenderWindow.hpp>

/**
 *  This is the game class. The game class contains everything that is related to
 *  the game itself. E.g. the input handling for the ship, collision detection
 *  with planets, rendering all the stuff in the current view.
 */
class Game
{
public:
    Game(sf::RenderWindow &window);

    ~Game();

    bool isOpen() const;

    void setScene(GameScene *scene);

    /**
     * Will handle SFML events. Mostly key inputs.
     */
    void handleEvent();

    /**
     * Will handle events that also need access to the window itself.
     * Mostly for UI elements.
     *
     * @param event The event to handle.
     * @param window    The window of the current game.
     */
    void handleWindowEvent(sf::Event &event, sf::RenderWindow &window);

    /**
     * This method will be called to update the state of the current game scene.
     * Will be called every frame.
     */
    void update();

    /**
     *  This method will be called to render the current game scene.
     *  Will be called every frame.
     */
    void render();
private:
    GameScene *_current_scene;
    Renderer _renderer;
    sf::RenderWindow *_window;
};

#endif //GAME_H
