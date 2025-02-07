//
// Created by o.le on 07.02.25.
//

#include "ui/UIButton.h"

#include <iostream>

UIButton::UIButton(const std::string &label_text, sf::Font &label_font, std::function<void()> callback)
    : _on_click(callback)
{
    _rect.setFillColor(sf::Color::White);

    _text.setFont(label_font);
    _text.setCharacterSize(24);
    _text.setString(label_text);
    _text.setFillColor(sf::Color::Black);
}

void UIButton::setPos(const sf::Vector2f &pos)
{
    _rect.setPosition(pos.x + 100, pos.y + 100);    // TODO need to place in center of UI element
    _text.setPosition(_rect.getPosition());
}

void UIButton::setSize(float width, float height)
{
    _rect.setSize(sf::Vector2f(width, height));
}

void UIButton::handleEvent(const sf::Event &event, const sf::RenderWindow &window)
{
    std::cout << "Button pressed" << std::endl;
}

void UIButton::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(_rect);
    target.draw(_text);
}
