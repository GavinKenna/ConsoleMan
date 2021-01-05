#include "Wall.h"


Wall::~Wall()
{
    //dtor
}

void Wall::draw()
    {
        mvwprintw(window, getPosY(), getPosX(), "%c", getSymbol());
    }
