//
// Created by o.le on 01.02.25.
//

#include <Game.h>
#include "GameSettings.h"
#include <scenes/SpaceScene.h>
#include "core/debug/Debug.h"

int main()
{
    deb::Logger::init();
    deb::Logger::getInstance().log("Start new game");
    /*
     *  sf::Style::Titlebar is needed to make the window floating on my system.
     */
    sf::RenderWindow window(sf::VideoMode(Settings::WINDOW_WIDTH, Settings::WINDOW_HEIGHT),
                            "SFMLGame",
                            sf::Style::Titlebar);
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    Game game(window);

    while (game.isOpen())
    {
        game.handleEvent();
        game.update();

        window.clear();
        game.render();
        window.display();
    }
    deb::Logger::getInstance().log("Closing game");
    deb::Logger::shutdown();
    return 0;
}
