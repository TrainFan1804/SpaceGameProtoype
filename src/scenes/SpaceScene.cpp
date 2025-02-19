//
// Created by o.le on 03.02.25.
//

#include "scenes/SpaceScene.h"
#include "ui/GalaxyJumpUI.h"
#include "GameSettings.h"
#include "utils/AssetUtils.h"

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "utils/RandomUtils.h"

/**
 * This flag will be true if player press button for landing.
 */
constexpr int IS_LANDING_PRESSED = 0;
constexpr int PLANET_IN_RANGE = 1;

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

    _resource_overlay = new ResourceOverlay();
    _resource_inventory.setOverlay(_resource_overlay);
}

void SpaceScene::singleEventHandling(sf::Event &event)
{
    if (!_galaxy_jump_ui->isVisible())
    {
        if (event.type == sf::Event::KeyPressed
            && event.key.code == sf::Keyboard::E)
        {
            _state_machine.setState(IS_LANDING_PRESSED, true);
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
    _resource_overlay->setPos(sf::Vector2f(_camera->getCenter().x + 600,
        _camera->getCenter().y - 300));

    auto nearest_planet = calcNearestPlanet();

    setPlanetLandingText(nearest_planet);

    // this is ugly but it works.
    // TODO maybe adding a timer before adding the resources to the inventory?
    if (nearest_planet && _state_machine.getState(PLANET_IN_RANGE))
    {
        if (_state_machine.getState(IS_LANDING_PRESSED))
        {
            // this should make the farming process relatively random.
            // Later the farming process should be constraint to the ships
            // upgraded farm module.
            res::ResourceType farm_mat = RandomUtils::randomResourceType();
            int farm_amount = RandomUtils::randomResourceAmount(0, 100);
            // get random resource from nearest planet
            int from_planet = nearest_planet
                ->harvestResource(farm_mat, farm_amount);
            // adding these resource to the players inventory
            _resource_inventory.addResource(farm_mat, from_planet);

            _state_machine.setState(IS_LANDING_PRESSED, false);
        }
    }
}

Planet *SpaceScene::calcNearestPlanet()
{
    /*
     *  In this big if statement is a very rudimental landing system for
     *  planets. This need definitely to be updated.
     *
     *  This doesn't work anymore when working with multiple planets per
     *  galaxy.
     *
     *  I could finally let it work correctly. To interact with a planet the
     *  ship must be in a range from 0 to 100 units away from the targeting
     *  planet.
     */
    Planet *nearest_planet = nullptr; // make sure the pointer holds nothing at begin
    float nearest_planet_distance = 100.f;
    for (auto &planet: _galaxy->getGalaxyPlanets())
    {
        float distance = ats::calcDistanceBetweenAssets(_player_ship, planet);
        if (distance < nearest_planet_distance)
        {
            nearest_planet = &planet;
            nearest_planet_distance = distance;
        }
    }
    return nearest_planet;
}

void SpaceScene::setPlanetLandingText(Planet *nearest_planet)
{
    if (nearest_planet)
    {
        if (ats::calcDistanceBetweenAssets(_player_ship, *nearest_planet) <= 500.f)
        {
            _state_machine.setState(PLANET_IN_RANGE, true);
            _text.setPosition(nearest_planet->getPos().x,
                nearest_planet->getPos().y - 100);
        }
    }
    else
    {
        _state_machine.setState(PLANET_IN_RANGE, false);
    }
    // end of planet landing calculation stuff
}

void SpaceScene::setupStaticRenderer(Renderer &renderer)
{
    renderer.addAsset(_galaxy);
    renderer.addAsset(&_player_ship);
    renderer.addAsset(&_text);
    renderer.addAsset(_galaxy_jump_ui);
    renderer.addAsset(_resource_overlay);
}

void SpaceScene::setupDynamicRenderer(Renderer &renderer)
{
    /*
     *  Instead of removing and adding the text I should just toggle a
     *  should render bool flag in my custom datastructure to determine if the
     *  text should be drawn or not. Would also be more efficient than removing
     *  and adding the asset everytime the ship is near a planet.
     */
    if (_state_machine.getState(PLANET_IN_RANGE)
        && !_galaxy_jump_ui->isVisible())
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
