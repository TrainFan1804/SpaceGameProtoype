//
// Created by o.le on 02.02.25.
//

#include "Game.h"

constexpr int WINDOW_WIDTH = 1500;
constexpr int WINDOW_HEIGHT = 900;

Game::Game(Renderer &renderer)
    : _current_scene(nullptr), _renderer(renderer)
{

}

Game::~Game()
{
    delete _current_scene;
}


void Game::set_scene(GameScene *scene)
{
    _current_scene = scene;
}

void Game::handleEvent(sf::Event &event)
{
    _current_scene->eventHandling(event);
}

void Game::update()
{
    _current_scene->play();
}

void Game::render(sf::RenderWindow &window)
{
    _current_scene->setupRenderer(_renderer);
    _renderer.render(window, *_current_scene);
}
