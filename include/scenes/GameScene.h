//
// Created by o.le on 03.02.25.
//

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "../Renderer.h"

#include <SFML/Graphics/View.hpp>
#include <SFML/Window/Event.hpp>

class Renderer;

/**
 *  A scene is an abstract concept of my game. A scene contains those object that
 *  should be represented the current scene. Those objects will be called "assets".
 */
struct GameScene
{
    virtual ~GameScene() = default;

    /**
     * Will handle different SFML events. Mostly used for key input events.
     *
     * You should implement all events in this method and NOT in GameScene::play().
     * When doing you need to keep in mind you can't render objects directly on the
     * screen. To do this you need to keep track of the render state yourself.
     *
     * @param event The event that should be handled.
     */
    virtual void eventHandling(sf::Event &event) = 0;

    /**
     * Play will start the loop of the scene.
     */
    virtual void play() = 0;

    /**
     *  Call this to set up the renderer for the scene.
     *
     * @param renderer  The renderer that should render the scene.
     */
    virtual void setupRenderer(Renderer &renderer) = 0;

    /**
     *  Returns the camera of the scene.
     *
     * @return  The scene's camera.
     */
    virtual sf::View &getCamera() const = 0;
};

#endif //GAMESCENE_H
