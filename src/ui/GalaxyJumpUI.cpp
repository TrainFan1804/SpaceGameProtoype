//
// Created by o.le on 04.02.25.
//

#include "ui/GalaxyJumpUI.h"

GalaxyJumpUI::GalaxyJumpUI()
    : _is_visible(false)
{
    _menu_rec.setSize(sf::Vector2f(500, 500));
    _menu_rec.setFillColor(sf::Color::Yellow);
    // TODO I should create a resource manager in the near future!
    if (!_font.loadFromFile(RESOURCES_PATH "font/OpenSans-Medium.ttf"))
    {
        throw std::runtime_error("Font could not be loaded");
    }
    _text.setString("Select a galaxy to jump");
    _text.setFont(_font);
    _text.setCharacterSize(20);
    _text.setFillColor(sf::Color::Black);
}

void GalaxyJumpUI::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    /*
     * This is a nice trick for custom drawable objects. So I don't need to
     * remove the UI from the render pipeline just to add it again later
     * (Keyword: Renderbuffer!).
     */
    if (!_is_visible) return;
    target.draw(_menu_rec);
    target.draw(_text);
}

void GalaxyJumpUI::hide()
{
    _is_visible = false;
}

void GalaxyJumpUI::show()
{
    _is_visible = true;
}

bool GalaxyJumpUI::isVisible() const
{
    return _is_visible;
}

void GalaxyJumpUI::setCenter(const sf::Vector2f &center)
{
    sf::Vector2f new_pos(center.x - _menu_rec.getSize().x / 2, center.y - _menu_rec.getSize().y / 2);
    _menu_rec.setPosition(new_pos);
    _text.setPosition(_menu_rec.getPosition());
}


