//
// Created by o.le on 07.02.25.
//

#ifndef UIBUTTON_H
#define UIBUTTON_H

#include <functional>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

/**
 *  This is a custom class that represent a Button on different UI elements such
 *  as menus.
 */
class UIButton : public sf::Drawable {
public:
    UIButton(const std::string &label_text, sf::Font &label_font, std::function<void()> callback);

    void setSize(float width, float height);
    void setPos(const sf::Vector2f &pos);
    sf::FloatRect getGlobalBounds() const;
    void handleEvent();
private:
    sf::RectangleShape _rect;
    sf::Text _text;
    std::function<void()> _on_click;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif //UIBUTTON_H
