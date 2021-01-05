#ifndef LEGALLYAMBIGUOUSGHOST_H
#define LEGALLYAMBIGUOUSGHOST_H

#include "GameObject.h"

class LegallyAmbiguousGhost : public GameObject
{
    public:
    LegallyAmbiguousGhost(){}
        LegallyAmbiguousGhost(int y, int x,WINDOW *window,std::vector<GameObject*> *gameObjects):GameObject('@', y, x,window),gameObjects(gameObjects){}
        virtual ~LegallyAmbiguousGhost();

        void update();
    protected:
    private:
    std::vector<GameObject*> *gameObjects;
};

#endif // LEGALLYAMBIGUOUSGHOST_H
