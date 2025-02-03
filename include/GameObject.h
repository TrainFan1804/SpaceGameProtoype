//
// Created by o.le on 03.02.25.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics/RenderWindow.hpp>

class GameObject
{
public:
    virtual void draw(sf::RenderWindow &window) const = 0;
};

#endif //GAMEOBJECT_H
