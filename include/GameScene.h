//
// Created by o.le on 03.02.25.
//

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Renderer.h"

class Renderer;

/**
 *  A scene is an abstract concept of my game. A scene contains those object that
 *  should be represented the current scene.
 */
struct GameScene
{
    virtual ~GameScene() = default;

    /**
     * Play will start the loop of the scene. This method will contain stuff like
     * Input handling, events or other stuff.
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
