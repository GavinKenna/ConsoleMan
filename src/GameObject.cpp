#include "GameObject.h"

GameObject::GameObject()
{
    this->setSymbol('\0'); // Yeah. We shouldn't be creating a game object without setting the symbol. So this is what you get. You get nothing!
}

GameObject::GameObject(char symbol, int y, int x, WINDOW *window)
{
    this->setSymbol(symbol);
    this->setPosX(x);
    this->setPosY(y);
    this->setWindow(window);
}

GameObject::~GameObject()
{
    // std::cout<<"Bye bye"<<std::endl;
}

char GameObject::getSymbol()
{
    return this->symbol;
}

void GameObject::setSymbol(char symbol)
{
    this->symbol = symbol;
}

int GameObject::getPosX()
{
    return this->posX;
}

int GameObject::getPosY()
{
    return this->posY;
}

void GameObject::setPosX(int x)
{
    this->posX = x;
}

void GameObject::setPosY(int y)
{
    this->posY = y;
}

WINDOW* GameObject::getWindow()
{
    return this->window;
}

void GameObject::setWindow(WINDOW *window)
{
    this->window = window;
}


void GameObject::draw()
{
    mvwprintw(this->window, this->getPosY(), this->getPosX(), "%c", this->getSymbol());

}
