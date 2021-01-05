#include "LegallyAmbiguousGhost.h"

LegallyAmbiguousGhost::~LegallyAmbiguousGhost()
{
    //dtor
}

void LegallyAmbiguousGhost::update(){
    this->posX++;
    if(posX>=50){
        posX = 0;
    }
}
