#ifndef IGAMEINTERFACE_H
#define IGAMEINTERFACE_H

/**
* Ok yeah, I couldn't think of a better name than IGameInterface.
* Also, yes, I know it's redudant calling it an InterfaceGameInterface,
* but this is my project so I can call it anything. I can call
* it RxfT^%&lkX.h if I so inclined. Or wait could I? With all of the symbols...You know what, never mind.
*/
class IGameInterface
{
    public:
        IGameInterface();
        virtual ~IGameInterface();

        virtual void update(){}
        virtual void draw(){}
    protected:
    private:
};

#endif // IGAMEINTERFACE_H
