//
// Created by o.le on 03.02.25.
//

#ifndef RENDERER_H
#define RENDERER_H

#include "RendererEntry.h"
#include "scenes/GameScene.h"

#include <map>

#include <SFML/Graphics/RenderWindow.hpp>

class GameScene;

/**
 * The Renderer is a class that will handle the drawing to the window directly.
 */
class Renderer
{
public:
    Renderer();

    void addAsset(sf::Drawable *asset);

    void removeAsset(sf::Drawable *asset);

    void activateRenderFor(sf::Drawable *asset);
    void deactivateRenderFor(sf::Drawable *asset);

    /**
     * Will render all internally saved assets to the given window.
     *
     * @param window    The window that is rendered to.
     */
    void render(sf::RenderWindow &window);
private:
    int _asset_count;
    std::map<int, RendererEntry> _assets;
};

#endif //RENDERER_H
