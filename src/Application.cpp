//
// Created by o.le on 01.02.25.
//

#include "Application.h"
#include "Game.h"
#include "scenes/GameScene.h"
#include "scenes/SpaceScene.h"

#include <SFML/Window/Event.hpp>

constexpr int WINDOW_WIDTH = 1500;
constexpr int WINDOW_HEIGHT = 900;

int Application::run()
{
    /*
     *  sf::Style::Titlebar is needed to make the window floating on my system.
     */
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                            "SFMLGame",
                            sf::Style::Titlebar);
    window.setFramerateLimit(60);

    sf::View default_space_camera(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
    window.setView(default_space_camera);

    Renderer renderer;
    Game game(renderer);
    SpaceScene space_scene(default_space_camera);
    game.set_scene(&space_scene);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        game.handleEvent(event);
        game.update();

        window.clear();
        game.render(window);
        window.display();
    }
    return 0;
}
