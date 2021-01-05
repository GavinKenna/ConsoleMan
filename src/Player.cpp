#include "Player.h"


Player::~Player()
{
    //dtor
}


void Player::update()
{
    if(mouthOpen)
    {
        this->setSymbol(m_Direction);
    }
    else
    {
        if(m_Direction == 'v' || m_Direction == '^')
        {
            this->setSymbol('|');
        }
        else
        {
            this->setSymbol('-');
        }

    }

    updateScore();
    checkCollisionsWithPellets();
    //checkCollisionsWithPowerPellets();
    //checkCollisionsWithGhosts();
    //checkCollisionsWithWalls();

}
void Player::checkCollisionsWithPellets()
{
    for(int i = 0; i < this->gameObjects->size(); i++)
    {
        if(LegallyAmbiguousPellet *p = dynamic_cast<LegallyAmbiguousPellet*>(gameObjects->at(i)))
        {
            if(p->getPosX()==this->getPosX() && p->getPosY()==this->getPosY())
            {
                this->score+=5;
                this->gameObjects->erase(gameObjects->begin()+i);
            }
        }
    }
}



void Player::sendInput(int hitKey)
{
    switch(hitKey)
    {
    case KEY_UP:
        this->posY--;
        this->m_Direction = FacingUp;
        //this->setSymbol('v');
        break;
    case KEY_DOWN:
        this->posY++;
        this->m_Direction = FacingDown;
        //this->setSymbol('^');
        break;
    case KEY_LEFT:
        this->posX--;
        this->m_Direction = FacingLeft;
        //this->setSymbol('>');
        break;
    case KEY_RIGHT:
        this->posX++;
        this->m_Direction = FacingRight;
        //this->setSymbol('<');
        break;
    default:
        refresh();
        break;
    }
}

void Player::animate()
{
    while(1)
    {
        usleep(400000);
        mouthOpen = !mouthOpen;
    }
}

void Player::updateScore()
{
    char s[100];
    sprintf(s, "SCORE :: %d", score);
    mvwprintw(this->scoreWindow, 1, 5, "%s",s);
}
