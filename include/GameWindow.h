#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <ncurses.h>

/***
* Simply does game window stuff. So like, holds the winsize and WINDOW. Damn, I need to
* rewrite this wording.
*/
class GameWindow
{
public:
    GameWindow(WINDOW *terminalWindow, const int height, const int width):terminalWindow(terminalWindow), height(height), width(width) {}
    virtual ~GameWindow();

    WINDOW *getTerminalWindow()
    {
        return this->terminalWindow;
    }
    int getHeight()
    {
        return this->height;
    }

    int getWidth()
    {
        return this->width;
    }

    // This method is the method that brings the game window alive and whatnot
    void start();
protected:
    WINDOW *terminalWindow;
    int height;
    int width;
private:

};

#endif // GAMEWINDOW_H
