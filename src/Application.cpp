#include "Application.h"
#include "Game.h"

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

    sf::View view(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
    window.setView(view);

    Game game(view);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        game.update();

        window.clear();
        game.render(window);
        window.display();
    }
    return 0;
}
