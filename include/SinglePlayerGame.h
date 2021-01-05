#ifndef SINGLEPLAYERGAME_H
#define SINGLEPLAYERGAME_H

#include <GameWindow.h>
#include "Player.h"
#include "LegallyAmbiguousGhost.h"
#include "LegallyAmbiguousPellet.h"
#include "LegallyAmbiguousPowerPellet.h"
#include "Wall.h"
#include <unistd.h>
#include <list>
#include "GameObject.h"
#include <stdlib.h>
#include <vector>

class SinglePlayerGame : public GameWindow
{
public:
    SinglePlayerGame(WINDOW *terminalWindow, const int height, const int width):GameWindow(terminalWindow, height, width) {
        this->gameObjects = new std::vector<GameObject*>();
    }
    virtual ~SinglePlayerGame();

    void start();

protected:
private:
    WINDOW *gameWindow; //The action will be happening, the game box
    WINDOW *scoreWindow; //Scores and stuff will be kept here

    //Player *player;
    //LegallyAmbiguousGhost *ghosts[4];

    std::vector<GameObject*> *gameObjects;

    void initGameWindow();
    void initScoreWindow();

    void loadLevel();
    void handleInput();

    Player *playerObject;
};

#endif // SINGLEPLAYERGAME_H
