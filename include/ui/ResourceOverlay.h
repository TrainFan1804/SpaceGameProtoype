//
// Created by o.le on 15.02.25.
//

#ifndef RESOURCEOVERLAY_H
#define RESOURCEOVERLAY_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "resources/ResourceInventory.h"

class ResourceInventory;

/**
 * This overlay will display a small "GUI" for the amount of resources in a
 * ResourceInventory.
 */
class ResourceOverlay : public sf::Drawable
{
public:
    ResourceOverlay();

    void setPos(const sf::Vector2f &pos);

    /**
     * This will set the data that is displayed on the screen.
     *
     * @param inv   The data from the inventory.
     * @note    Because this class was designed as an observer this method should
     * just be called from another ResourceInventory.
     * This isn't exactly what encapsulation stand for bit I don't really care.
     * Just RTFM.
     */
    void setData(const ResourceInventory *inv);
private:
    sf::RectangleShape _rec;
    sf::Text _metal_text;
    sf::Text _water_text;
    sf::Font _font;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif //RESOURCEOVERLAY_H
