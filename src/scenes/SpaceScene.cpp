//
// Created by o.le on 03.02.25.
//

#include "scenes/SpaceScene.h"

#include <iostream>
#include <memory>

#include <SFML/Window/Keyboard.hpp>

constexpr int WINDOW_WIDTH = 1500;
constexpr int WINDOW_HEIGHT = 900;

/*
 *  This is a hell of a constructor...
 */
SpaceScene::SpaceScene(sf::View &init_camera)
    : _player_ship(sf::Vector2f(100, 200)),
      _galaxy("Galaxy 1"),
      _is_landing_pressed(false), _planet_in_range(false), _camera(init_camera)
{
    _player_ship.setPos(sf::Vector2f((WINDOW_WIDTH - 100) / 2, (WINDOW_HEIGHT - 200) / 2));
    if (!_font.loadFromFile(RESOURCES_PATH "font/OpenSans-Medium.ttf"))
    {
        throw std::runtime_error("Font could not be loaded");
    }
    _text.setString("Press E to land");
    _text.setFont(_font);
    _text.setCharacterSize(20);
    _text.setFillColor(sf::Color::Blue);
}

void SpaceScene::eventHandling(sf::Event &event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        _player_ship.move(-1, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        _player_ship.move(1, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        _player_ship.move(0, -1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        _player_ship.move(0, 1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        _galaxy = Galaxy::createGalaxy();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        if (!_is_landing_pressed)
        {
            std::cout << "Starting landing sequence.." << std::endl;
            _is_landing_pressed = true;
        }
    }
    else
    {
        _is_landing_pressed = false;
    }
}

void SpaceScene::play()
{
    _camera.setCenter(_player_ship.getPos());

    /**
     *  In this big if statement is a very rudimental landing system for
     *  planets. This need definetly to be updated.
     *
     *  This doesn't work anymore when working with multiple planets per
     *  galaxy.
     *
     *  I could finaly let it work correctly. To interact with a planet the\
     *  ship must be in a range from 0 to 100 units away from the targeting
     *  planet.
     *  TODO I need a find abstraction for this one.
     */
    std::unique_ptr<Planet> nearest_planet = nullptr; // TODO I could put this into the PlayerShip class
    nearest_planet.reset(); // make sure the unique_pointer hold nothing.
    float nearest_planet_distance = 100.f;
    for (auto &planet: _galaxy.getGalaxyPlanets())
    {
        float distance = calculateDistanceShipToPlanet(_player_ship, planet);
        if (distance < nearest_planet_distance)
        {
            nearest_planet = std::make_unique<Planet>(planet);
            nearest_planet_distance = distance;
        }
    }

    if (nearest_planet)
    {
        if (calculateDistanceShipToPlanet(_player_ship, *nearest_planet) <= 500.f)
        {
            _planet_in_range = true;
            _text.setPosition(nearest_planet->getPos().x, nearest_planet->getPos().y - 100);
        }
    }
    else
    {
        _planet_in_range = false;
    }
    // end of planet landing calculation stuff
}

void SpaceScene::setupRenderer(Renderer &renderer)
{
    renderer.addAsset(&_galaxy);
    renderer.addAsset(&_player_ship);
    if (_planet_in_range)
    {
        renderer.addAsset(&_text);
    }
    else
    {
        // remove text from render pipeline
        renderer.removeAsset(&_text);
    }
}

sf::View &SpaceScene::getCamera() const
{
    return _camera;
}
