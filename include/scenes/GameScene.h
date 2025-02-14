//
// Created by o.le on 03.02.25.
//

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "core/renderer/Renderer.h"

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
     * Will handle different SFML events.
     *
     * You should implement all events in this method and NOT in GameScene::play().
     * When doing you need to keep in mind you can't render objects directly on the
     * screen. To do this you need to keep track of the render state yourself.
     *
     * @note When you want to handle stuff that expect to HOLD a button
     * you should use complexEventHandling(sf::Event)
     * @param event The event that should be handled.
     */
    virtual void singleEventHandling(sf::Event &event) = 0;

    /**
     * Will handle different SFML events. Mostly used for key input events.
     *
     * You should implement all events in this method and NOT in GameScene::play().
     * When doing you need to keep in mind you can't render objects directly on the
     * screen. To do this you need to keep track of the render state yourself.
     *
     * @param event The event that should be handled.
     */
    virtual void complexEventHandling(sf::Event &event) = 0;

    /**
     * Play will start the loop of the scene. Here should be put all logic that
     * is connected to any event itself.
     */
    virtual void play() = 0;

    /**
     *  Call this to set up the renderer for the scene. Use this ONLY for
     *  statically loaded assets (Those who only need to be loaded once e.g.
     *  vehicle, planets, etc.).
     *
     * @param renderer  The renderer that should render the scene.
     */
    virtual void setupStaticRenderer(Renderer &renderer) = 0;

    /**
     * Call this to set up the dynamic renderer. This is called everytime
     * Game::render() is called. You can use this to load assets dynamically
     * (e.g. menus, dynamically created assets like rockets). Can also be
     * used to only render what is only visible what is on the screen.
     *
     * @note Object that are loaded regular but not every frame (e.g. text
     * about other assets) you should load the asset once in
     * GameScene::setupStaticRenderer(Renderer) and only activate the loading
     * of the asset in this method manually instead of removing and adding it
     * the renderer every time it's loading it in the renderer.
     * @param renderer  The renderer that should render the scene.
     */
    virtual void setupDynamicRenderer(Renderer &renderer) = 0;

    /**
     *  Returns the camera of the scene.
     *
     * @return  The scene's camera.
     */
    virtual sf::View &getCamera() const = 0;
};

#endif //GAMESCENE_H
