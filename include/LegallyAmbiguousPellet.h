#ifndef LEGALLYAMBIGUOUSPELLET_H
#define LEGALLYAMBIGUOUSPELLET_H

#include "GameObject.h"

class LegallyAmbiguousPellet : public GameObject
{
    public:
    LegallyAmbiguousPellet(){}
        LegallyAmbiguousPellet(int y, int x,WINDOW *window):GameObject('*', y, x,window){}
        virtual ~LegallyAmbiguousPellet();
    protected:
    private:
};

#endif // LEGALLYAMBIGUOUSPELLET_H
