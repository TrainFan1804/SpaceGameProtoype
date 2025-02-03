//
// Created by o.le on 03.02.25.
//

#ifndef RENDERER_H
#define RENDERER_H

#include "GameScene.h"

#include <map>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Drawable.hpp>

class GameScene;

class Renderer {
public:
    Renderer();
    void addAsset(sf::Drawable *asset);
    void removeAsset(sf::Drawable *asset);
    void render(sf::RenderWindow &window, GameScene &render_scene);
private:
    int _asset_count;
    std::map<int, sf::Drawable*> _assets;
};

#endif //RENDERER_H
