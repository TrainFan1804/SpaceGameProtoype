//
// Created by o.le on 03.02.25.
//

#include "Renderer.h"

Renderer::Renderer()
    : _asset_count(0)
{

}

void Renderer::addAsset(sf::Drawable *asset)
{
    for (const auto &pair : _assets)
    {
        if (pair.second == asset)
        {
            return;
        }
    }
    _assets.insert({_asset_count++, asset});
}

void Renderer::removeAsset(sf::Drawable *asset)
{
    for (auto it = _assets.begin(); it != _assets.end(); ++it)
    {
        if (it->second == asset)
        {
            _assets.erase(it);
            _asset_count--;
            break;
        }
    }
}

void Renderer::render(sf::RenderWindow &window, GameScene &render_scene)
{
    for (auto &pair : _assets)
    {
        window.draw(*pair.second);
    }
    // The next line is actually pretty bad. TODO This can be fixed later.
    window.setView(render_scene.getCamera());
}
