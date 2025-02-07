//
// Created by o.le on 01.02.25.
//

#include "Application.h"
#include "Game.h"
#include "GameSettings.h"
#include "scenes/GameScene.h"
#include "scenes/SpaceScene.h"

#include <SFML/Window/Event.hpp>

int Application::run()
{
    /*
     *  sf::Style::Titlebar is needed to make the window floating on my system.
     */
    sf::RenderWindow window(sf::VideoMode(Settings::WINDOW_WIDTH, Settings::WINDOW_HEIGHT),
                            "SFMLGame",
                            sf::Style::Titlebar);
    window.setFramerateLimit(60);

    sf::View default_space_camera(sf::FloatRect(0, 0, Settings::WINDOW_WIDTH, Settings::WINDOW_HEIGHT));
    window.setView(default_space_camera);

    Renderer renderer;
    Game game(renderer);
    SpaceScene space_scene(default_space_camera);
    game.setScene(&space_scene);

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
