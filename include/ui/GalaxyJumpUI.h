//
// Created by o.le on 04.02.25.
//

#ifndef GALAXYMAP_H
#define GALAXYMAP_H

#include "UIButton.h"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

/**
 * This is the UI Element for the "jump between galaxies" menu.
 *
 * TODO It's probably nice to have UI interface. No, not a interface I should
 * TODO create UI Elements at runtime via different objects per UI.
 */
class GalaxyJumpUI : public sf::Drawable
{
public:
    GalaxyJumpUI();

    void hide();

    void show();

    bool isVisible() const;

    void setCenter(const sf::Vector2f &center);
private:
    bool _is_visible;
    sf::RectangleShape _menu_rec;
    sf::Font _font;
    sf::Text _text;
    UIButton _button;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif //GALAXYMAP_H
