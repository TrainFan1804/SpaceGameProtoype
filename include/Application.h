#ifndef APPLICATION_H
#define APPLICATION_H

/**
 *  This is the application class. The application class contains a Game object.
 *  The application class does NOT contain any game logic itself but will call
 *  the those modules that will execute special game logic (rendering, input handling, etc.).
 */
class Application
{
public:
    int run();
};

#endif // APPLICATION_H
