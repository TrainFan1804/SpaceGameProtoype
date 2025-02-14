//
// Created by o.le on 02.02.25.
//

#include "Game.h"

#include <scenes/SpaceScene.h>

/*
 *  These pointers are very ...
 */
Game::Game(sf::RenderWindow &window)
    : _window(&window)
{
    _current_scene = new SpaceScene();
    _window->setView(_current_scene->getCamera());
    // TODO only setup the renderer once and all dynamically loaded assets
    // handle in another method.
    _current_scene->setupStaticRenderer(_renderer);
}

Game::~Game()
{
    delete _current_scene;
    delete _window;
}

bool Game::isOpen() const
{
    return _window->isOpen();
}

void Game::setScene(GameScene *scene)
{
    _current_scene = scene;
}

// TODO this need to be refactored at all cost...
void Game::handleEvent()
{
    sf::Event event;
    while (_window->pollEvent(event))
    {
        // TODO Add events for resize, etc.
        if (event.type == sf::Event::Closed)
            _window->close();
    }
    _current_scene->eventHandling(event);
}

void Game::update()
{
    _current_scene->play();
}

void Game::render()
{
    _current_scene->setupDynamicRenderer(_renderer);
    _renderer.render(*_window);
    _window->setView(_current_scene->getCamera());
}
