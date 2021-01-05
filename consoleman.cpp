#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
//#include <curses.h>
#include <ncurses.h>
//#include <string.h>
#include "MainMenu.h"

#define MAX_WIDTH 100;
#define MAX_HEIGHT 100;
#define MIN_WIDTH 10;
#define MIN_HEIGHT 10;

using namespace std;

WINDOW *terminalWindow;
int height;
int width;

void init();

int main (int argc, char **argv)
{
    // Check for terminal size, make sure its the correct size

    // Show logo and menu
    init();

    MainMenu mm(terminalWindow, height, width);
    mm.start();
    // Take menu input


    return 0;  // make sure your main returns int
}

/***
* Setting up the window stuff, yuh hear?
*/
void init()
{
    /***
    * Here we are grabbing the terminals height and width
    */
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    height = w.ws_row;
    width = w.ws_col;

    initscr();
    clear();
    noecho();
    cbreak();	/* Line buffering disabled. pass on everything */

    terminalWindow = newwin(height, width, 0, 0);
    keypad(terminalWindow, TRUE);

}
