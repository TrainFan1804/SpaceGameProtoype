//
// Created by o.le on 07.02.25.
//

#include "core/renderer/RendererEntry.h"

RendererEntry::RendererEntry(sf::Drawable *asset, bool is_rendering)
    : _asset(asset), _is_rendering(is_rendering)
{

}
bool RendererEntry::operator==(const RendererEntry &other) const
{
    return _asset == other._asset;
}

bool RendererEntry::operator==(const sf::Drawable *drawable) const
{
    return _asset == drawable;
}
