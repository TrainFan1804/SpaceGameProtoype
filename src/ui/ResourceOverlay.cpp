//
// Created by o.le on 15.02.25.
//

#include "ui/ResourceOverlay.h"

#include <SFML/Graphics/Font.hpp>

ResourceOverlay::ResourceOverlay()
{
    _rec.setSize(sf::Vector2f(300, 100));
    _rec.setFillColor(sf::Color::Yellow);
    if (!_font.loadFromFile(RESOURCES_PATH "font/OpenSans-Medium.ttf"))
    {
        throw std::runtime_error("Font could not be loaded");
    }

    _metal_text.setString("Metal: 0");
    _metal_text.setFont(_font);
    _metal_text.setCharacterSize(20);
    _metal_text.setFillColor(sf::Color::Black);

    _water_text.setString("Water: 0");
    _water_text.setFont(_font);
    _water_text.setCharacterSize(20);
    _water_text.setFillColor(sf::Color::Black);
}

// TODO it's a bit buggy
void ResourceOverlay::setPos(const sf::Vector2f &pos)
{
    sf::Vector2f new_pos(pos.x - _rec.getSize().x,
        pos.y - _rec.getSize().y);
    _rec.setPosition(new_pos);
    _metal_text.setPosition(_rec.getPosition().x, _rec.getPosition().y);
    _water_text.setPosition(_rec.getPosition().x, _rec.getPosition().y + 50);
}

void ResourceOverlay::setData(const ResourceInventory *inv)
{
    _metal_text.setString("Metal: " + std::to_string(inv->metal_amount));
    _water_text.setString("Water: " + std::to_string(inv->water_amount));
}

void ResourceOverlay::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(_rec);
    target.draw(_metal_text);
    target.draw(_water_text);
}
