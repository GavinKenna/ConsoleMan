#ifndef LEGALLYAMBIGUOUSPOWERPELLET_H
#define LEGALLYAMBIGUOUSPOWERPELLET_H

#include "GameObject.h"

class LegallyAmbiguousPowerPellet : public GameObject
{
    public:
    LegallyAmbiguousPowerPellet(){}
        LegallyAmbiguousPowerPellet(int y, int x, WINDOW *window):GameObject('O', y, x, window){}
        virtual ~LegallyAmbiguousPowerPellet();
    protected:
    private:
};

#endif // LEGALLYAMBIGUOUSPOWERPELLET_H
