#ifndef WALL_H
#define WALL_H

#include "GameObject.h"

class Wall : public GameObject
{
public:
    Wall() {}
    Wall(int y, int x,WINDOW *window):GameObject('#', y, x,window) {}
    virtual ~Wall();
    void draw();
protected:
private:
};

#endif // WALL_H
