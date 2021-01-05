#ifndef MAINMENU_H
#define MAINMENU_H

#include "GameWindow.h"
#include "SinglePlayerGame.h"
#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class MainMenu : public GameWindow
{

public:
    MainMenu(WINDOW *terminalWindow, const int height, const int width):GameWindow(terminalWindow, height, width)
    {
        choicesSize = sizeof(menuChoices) / sizeof(char *);
    }
    virtual ~MainMenu();

    void printMenu();
    void start();
protected:
private:
    char * menuChoices[5]=
    {
        "Single Player",
        "Multi Player",
        "Watch Demo",
        "Credits",
        "Exit",
    };

    int choicesSize;

    int highlightedChoice=1;
    int selectedChoice=-1; // This is set when ENTER is hit

    int menuWindowHeight;
    int menuWindowWidth;
    WINDOW *menuWindow; // To place our menu choices

    void initMenuWindow();

    void printLogo();
    void loadLogo();

    char * logoFile = "logo.txt";
    char * logo;

    void startSinglePlayerGame();
};

#endif // MAINMENU_H
