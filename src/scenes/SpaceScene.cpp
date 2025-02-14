//
// Created by o.le on 03.02.25.
//

#include "scenes/SpaceScene.h"
#include "ui/GalaxyJumpUI.h"
#include "GameSettings.h"

#include <iostream>
#include <memory>

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>


/**
 * This flag will be true if player press button for landing.
 */
constexpr int IS_LANDING_PRESSED = 0;
constexpr int GALAXY_MAP_PRESSED = 1;
constexpr int PLANET_IN_RANGE = 2;

/*
 *  This is a hell of a constructor...
 */
SpaceScene::SpaceScene()
    : _player_ship(sf::Vector2f(100, 200))
{
    _galaxy = Galaxy::createGalaxy();
    _galaxy_jump_ui = new GalaxyJumpUI(*_galaxy);

    _camera = new sf::View(sf::FloatRect(0.f, 0.f, Settings::WINDOW_WIDTH, Settings::WINDOW_HEIGHT));

    _player_ship.setPos(sf::Vector2f((Settings::WINDOW_WIDTH - 100) / 2, (Settings::WINDOW_HEIGHT - 200) / 2));
    if (!_font.loadFromFile(RESOURCES_PATH "font/OpenSans-Medium.ttf"))
    {
        throw std::runtime_error("Font could not be loaded");
    }
    _text.setString("Press E to land");
    _text.setFont(_font);
    _text.setCharacterSize(20);
    _text.setFillColor(sf::Color::Blue);

    _state_machine.setState(IS_LANDING_PRESSED);
    _state_machine.setState(PLANET_IN_RANGE);
}

void SpaceScene::singleEventHandling(sf::Event &event)
{
    if (!_galaxy_jump_ui->isVisible())
    {
        if (event.type == sf::Event::KeyPressed
            && event.key.code == sf::Keyboard::E)
        {
            /*
             * TODO instead of check if a planet is in range I should just calculate
             * the range of the planet when the key was even pressed
             */
            if (_state_machine.getState(PLANET_IN_RANGE))
                std::cout << "Starting landing sequence.." << std::endl;
        }
    }
    mapHandling(event);
}

void SpaceScene::mapHandling(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed
        && event.key.code == sf::Keyboard::Q)
    {
        if (_galaxy_jump_ui->isVisible())
        {
            _galaxy_jump_ui->hide();
        }
        else
        {
            _galaxy_jump_ui->setCenter(_player_ship.getPos());
            _galaxy_jump_ui->show();
        }
    }
    if (event.type == sf::Event::KeyPressed
        && event.key.code == sf::Keyboard::Enter)
    {
        _galaxy_jump_ui->clickButton();
    }
}

void SpaceScene::complexEventHandling(sf::Event &event)
{
    if (!_galaxy_jump_ui->isVisible())
        _player_ship.controlMoving();
}

void SpaceScene::play()
{
    // make sure the camera is centered to the ship
    _camera->setCenter(_player_ship.getPos());

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
    for (auto &planet: _galaxy->getGalaxyPlanets())
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
            _state_machine.setState(PLANET_IN_RANGE, true);
            _text.setPosition(nearest_planet->getPos().x, nearest_planet->getPos().y - 100);
        }
    }
    else
    {
        _state_machine.setState(PLANET_IN_RANGE, false);
    }
    // end of planet landing calculation stuff
}

/*
 *  This method is still not very good. This method will always be called when
 *  drawing something to the screen but this method should just load the stuff
 *  into the renderer. But some object will always be on the same address in memory
 *  (e.g. the ship, the text (just there position etc. will change, but it's
 *  still the same object)). So I need actually two? methods to load something into
 *  the renderer. One for "static" objects like the ship and one for dynamically
 *  created objects like the different planets.
 */
void SpaceScene::setupStaticRenderer(Renderer &renderer)
{
    renderer.addAsset(_galaxy);
    renderer.addAsset(&_player_ship);
    renderer.addAsset(&_text);
    renderer.addAsset(_galaxy_jump_ui);
}

void SpaceScene::setupDynamicRenderer(Renderer &renderer)
{
    /*
     *  Instead of removing and adding the text I should just toggle a
     *  should render bool flag in my custom datastructure to determine if the
     *  text should be drawn or not. Would also be more efficient than removing
     *  and adding the asset everytime the ship is near a planet.
     */
    if (_state_machine.getState(PLANET_IN_RANGE))
    {
        renderer.activateRenderFor(&_text);
    }
    else
    {
        // remove text from render pipeline but it's still in render buffer
        renderer.deactivateRenderFor(&_text);
    }
}

sf::View &SpaceScene::getCamera() const
{
    return *_camera;
}
