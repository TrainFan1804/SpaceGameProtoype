//
// Created by o.le on 03.02.25.
//

#include "core/renderer/Renderer.h"

#include <iostream>

Renderer::Renderer()
    : _asset_count(0)
{

}

/*
 *  TODO There should be a add method where I can put an element at a custom
 *  TODO index. I want to change the priorities of the render pipeline.
 *  TODO This can be very dangerous and could lead to unexpected behavior.
 *
 *  Alternative: All objects from UI classes should be loaded with the highest
 *  priority so they rendered on top of the other stuff.
 *  Alternative 2: Instead of drawing everything in the map to the screen I could
 *  implement a custom datastructure that will hold information like render order,
 *  and more. Could also hold information if a asset should be drawn or not.
 *  Useful for assets that can't be altered anymore (e.g. sf::Text).
 *  See SpaceScene::render for a simple example.
 *
 *  I implemented a simpler version of alternative 2
 */
void Renderer::addAsset(sf::Drawable *asset)
{
    for (const auto &[prio, entry] : _assets)
    {
        if (entry == asset)
        {
            return;
        }
    }
    _assets.insert({_asset_count++, RendererEntry(asset)});
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

void Renderer::activateRenderFor(sf::Drawable *asset)
{
    for (auto &[prio, entry] : _assets)
    {
        if (entry == asset)
        {
            entry._is_rendering = true;
        }
    }
}

void Renderer::deactivateRenderFor(sf::Drawable *asset)
{
    for (auto &[prio, entry] : _assets)
    {
        if (entry == asset)
        {
            entry._is_rendering = false;
        }
    }
}

void Renderer::render(sf::RenderWindow &window)
{
    for (const auto &[prio, asset] : _assets)
    {
        if (asset._is_rendering)
            window.draw(*asset._asset);
    }
}
