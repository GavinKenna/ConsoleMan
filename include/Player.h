#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "GameWindow.h"
#include <thread>
#include "LegallyAmbiguousPellet.h"
#include <string>

enum Direction : char
{
    FacingLeft = '>', FacingRight= '<', FacingDown= '^', FacingUp= 'v'
};

class Player : public GameObject
{
public:
    Player() {}
    Player(int y, int x, WINDOW *window,WINDOW *scoreWindow, std::vector<GameObject*> *gameObjects):GameObject('<', y, x, window),gameObjects(gameObjects),scoreWindow(scoreWindow)
    {
        this->score = 0;
    }
    virtual ~Player();
    void update();
    void sendInput(int input);
    void animate();
protected:
private:
    Direction m_Direction;
    std::vector<GameObject*> *gameObjects;
    //char m_startSymbol = '<'; // So he's facing right, mouth is open. See?
    char currentOpenMouth = '<'; // Open mouths
    bool mouthOpen = true; // For animation
    void checkCollisionsWithPellets();
    int score=0;
    WINDOW* scoreWindow;
    void updateScore();

};



#endif // PLAYER_H
