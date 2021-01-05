#include "SinglePlayerGame.h"
using namespace std;

SinglePlayerGame::~SinglePlayerGame()
{
    for(int i = 0; i < this->gameObjects->size(); i++)
    {
        GameObject *t = gameObjects->at(i);
        delete t;
    }
}

void SinglePlayerGame::initGameWindow()
{
    int gameHeight =((height/6)*5); // 5/6, five sixths, looks good to me
    int gameWidth = width;
    int posY = 0;
    int posX = 0;
    this->gameWindow = newwin(gameHeight, gameWidth, posY, posX);
    keypad(gameWindow, TRUE);
}

void SinglePlayerGame::initScoreWindow()
{
    int scoreHeight =(height/6); //
    int scoreWidth = width;
    int posY = ((height/6)*5);
    int posX = 0;
    this->scoreWindow = newwin(scoreHeight, scoreWidth, posY, posX);
    //keypad(gameWindow, TRUE);
}

void SinglePlayerGame::loadLevel()
{
    char *levelChars;
    FILE *fp;
    long lSize;

    fp = fopen ( "src/world.txt" , "rb" );

    fseek( fp , 0L , SEEK_END);
    lSize = ftell( fp );
    rewind( fp );

    /* allocate memory for entire content */
    levelChars = (char*)calloc( 1, lSize+1 );
    if( !levelChars ) fclose(fp),fputs("memory alloc fails",stderr),exit(1);

    /* copy the file into the logo */
    if( 1!=fread( levelChars , lSize, 1 , fp) )
        fclose(fp),free(levelChars),fputs("entire read fails",stderr),exit(1);

    /* do your work here, logo is a string contains the whole text */

    fclose(fp);

    int xOffset = 5;
    int yOffset = 3;
    char temp = 't';

    Player playerTemp;
    Wall wallTemp;
    LegallyAmbiguousGhost ghostTemp;
    LegallyAmbiguousPellet pelletTemp;
    LegallyAmbiguousPowerPellet powerTemp;

    //gameObjects = new std::list<GameObject*>();

    for(int i = 0 ; i < lSize; i++)
    {
        temp = *levelChars;
        levelChars++;
        switch(temp)
        {
        case '\n':
            yOffset++;
            xOffset = 5;
            continue;
            break;
        case '<':
        {
            Player *player = new Player(yOffset, xOffset, gameWindow,scoreWindow, this->gameObjects);
            this->gameObjects->push_back(player);
            this->playerObject = player;
        }
        break;
        case '#' :
        {
            Wall *wall = new Wall(yOffset, xOffset, gameWindow);
            this->gameObjects->push_back(wall);
        }
        break;
        case '*':
        {
            LegallyAmbiguousPellet *pellet = new LegallyAmbiguousPellet(yOffset, xOffset,gameWindow);
            this->gameObjects->push_back(pellet);
        }
        break;
        case 'O':
        {
            LegallyAmbiguousPowerPellet *power = new LegallyAmbiguousPowerPellet(yOffset, xOffset,gameWindow);
            this->gameObjects->push_back(power);
        }
        break;
        case '@':
        {
            LegallyAmbiguousGhost *g = new LegallyAmbiguousGhost(yOffset, xOffset,gameWindow, this->gameObjects);
            this->gameObjects->push_back(g);
        }
        break;
        }

        xOffset++;

    }




}

void SinglePlayerGame::start()
{
    // Ok so here I'm gonna wanna create the two windws. The game
    // window and the score window.

    initGameWindow();
    initScoreWindow();

    wrefresh(terminalWindow);
    wclear(terminalWindow);
    wrefresh(terminalWindow);

    box(gameWindow,0,0);
    wrefresh(gameWindow);

    box(scoreWindow,0,0);
    wrefresh(scoreWindow);


    wrefresh(gameWindow);

    loadLevel();

    std::thread t1(&SinglePlayerGame::handleInput,this); // Thread to handle input for player
    std::thread animate(&Player::animate,this->playerObject);
    //t1.join();
    while(1)
    {
        usleep(10000);
        wclear(gameWindow);
        for(int i = 0 ; i < this->gameObjects->size(); i++)
        {
            GameObject *go = gameObjects->at(i);
            go->update();
            go->draw();
        }
        box(gameWindow,0,0);

        box(scoreWindow,0,0);
        wrefresh(scoreWindow);

        wrefresh(gameWindow);
        wrefresh(scoreWindow);
        //while(1) {}

    }
    /*
        int x = 10;
        int y = 5;
        wclear(terminalWindow);
        wrefresh(terminalWindow);
        int hitKey = 0;
        keypad(terminalWindow, TRUE);
        while(1)
        {
            box(terminalWindow, 0, 0);
            mvwprintw(terminalWindow, y, x, "%c", '@');
            hitKey = wgetch(terminalWindow);
            switch(hitKey)
            {
            case KEY_UP:
                y--;
                break;
            case KEY_DOWN:
                y++;
                break;
            case KEY_LEFT:
                x--;
                break;
            case KEY_RIGHT:
                x++;
                break;
            default:
                refresh();
                break;
            }


            mvwprintw(terminalWindow, x, y, "%c", '@');


            wrefresh(terminalWindow);
            wclear(terminalWindow);
            wrefresh(terminalWindow);
            //usleep(1);
        }*/
}
/**
* Threaded method to listen for input
*/
void SinglePlayerGame::handleInput()
{
    int hitKey = -1;
    while(1)
    {
        hitKey = wgetch(this->gameWindow);
        playerObject->sendInput(hitKey);
    }
}
