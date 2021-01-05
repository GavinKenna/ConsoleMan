#include "MainMenu.h"

using namespace std;

MainMenu::~MainMenu()
{
    delete this->menuWindow;
}

void MainMenu::start()
{
    int hitKey = 0; // What keyboard key was hit?

    initMenuWindow();
    loadLogo();

    //printMenu();

    while(selectedChoice==-1)
    {
        printMenu();
        hitKey = wgetch(menuWindow);
        switch(hitKey)
        {
        case KEY_UP:
            if(highlightedChoice == 1)
                highlightedChoice = choicesSize;
            else
                --highlightedChoice;
            break;
        case KEY_DOWN:
            if(highlightedChoice == choicesSize)
                highlightedChoice = 1;
            else
                ++highlightedChoice;
            break;
        case KEY_ENTER:
            selectedChoice = highlightedChoice;
            break;
        case 10:
            selectedChoice = highlightedChoice;
            break;
        default:
            refresh();
            break;
        }
        //printMenu();
    }

    //Now do something with the selected menu item
    switch(selectedChoice)
    {
    case 1:
        startSinglePlayerGame();
        break;
    }
}

void MainMenu::printMenu()
{
    wrefresh(terminalWindow);
    wclear(terminalWindow);
    wrefresh(menuWindow);
    wclear(menuWindow);
    int x, y, i;

    x = 2;
    y = 2;
    box(terminalWindow, 0, 0);
    box(menuWindow,0,0);

    printLogo();

    for(i = 0; i < choicesSize; ++i)
    {
        if(highlightedChoice == i + 1) /* High light the present choice */
        {
            wattron(menuWindow, A_REVERSE);
            mvwprintw(menuWindow, y, x, "%s", menuChoices[i]);
            wattroff(menuWindow, A_REVERSE);
        }
        else
            mvwprintw(menuWindow, y, x, "%s", menuChoices[i]);
        ++y;
    }
    wrefresh(terminalWindow);
    wrefresh(menuWindow);
}

/***
* You're going to see some silly maths down below. All this method does is set up the menu window,
* which is a child window of the main menu window.
*/
void MainMenu::initMenuWindow()
{
    int mwHeight = height/3;
    int mwWidth = width/3;
    int posY = height - height/3;
    int posX = (width - width/2) - mwWidth/2;
    menuWindow = newwin(mwHeight, mwWidth, posY, posX);
    keypad(menuWindow, TRUE);
}

void MainMenu::loadLogo()
{
    FILE *fp;
    long lSize;

    fp = fopen ( "logo.txt" , "rb" );

    fseek( fp , 0L , SEEK_END);
    lSize = ftell( fp );
    rewind( fp );

    /* allocate memory for entire content */
    logo = (char*)calloc( 1, lSize+1 );
    if( !logo ) fclose(fp),fputs("memory alloc fails",stderr),exit(1);

    /* copy the file into the logo */
    if( 1!=fread( logo , lSize, 1 , fp) )
        fclose(fp),free(logo),fputs("entire read fails",stderr),exit(1);

    /* do your work here, logo is a string contains the whole text */

    fclose(fp);
    //free(logo);
}

void MainMenu::printLogo()
{
    mvwprintw(terminalWindow, 0, 0, "%s", logo);
}

void MainMenu::startSinglePlayerGame()
{
    //this->menuWindow = 0;
    //keypad(menuWindow, FALSE);
    SinglePlayerGame spg(terminalWindow, height, width);
    spg.start();
}
