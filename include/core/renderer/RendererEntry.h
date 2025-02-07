//
// Created by o.le on 07.02.25.
//

#ifndef RENDERERENTRY_H
#define RENDERERENTRY_H

#include <SFML/Graphics/Drawable.hpp>

struct RendererEntry
{
    const sf::Drawable *_asset;
    bool _is_rendering;

    RendererEntry(sf::Drawable *asset, bool is_rendering = true);

    bool operator==(const RendererEntry &other) const;
    bool operator==(const sf::Drawable *drawable) const;
};

#endif //RENDERERENTRY_H
