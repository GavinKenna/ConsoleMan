#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "IGameInterface.h"
#include <iostream>
#include "GameWindow.h"
#include <GameWindow.h>
#include <unistd.h>
#include <list>
#include <stdlib.h>
#include <vector>


class GameObject : IGameInterface
{
    public:
        GameObject();
        GameObject(char symbol,int y, int x, WINDOW *window);
        virtual ~GameObject();

        char getSymbol();
        void setSymbol(char symbol);

        int getPosX();
        int getPosY();
        void setPosX(int x);
        void setPosY(int y);
        WINDOW *getWindow();
        void setWindow(WINDOW * window);

        virtual void update(){}
        void draw();
    protected:
        char symbol; // What's this fantastic game object shown as? Perhaps an question mark? Or an exclamation mark!
        int posX;
        int posY;
        WINDOW *window; // What to draw to
    private:

};

#endif // GAMEOBJECT_H
