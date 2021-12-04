#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Library.h"

class ENEMY
{
    protected:
        char **shape;
        int x, y;
        bool type; //Vehicle = 1, Animal = 0;

    public:
        ENEMY();
        ENEMY(int x, int y, bool type);
        ENEMY(const ENEMY &other);
        ~ENEMY();

        void renderShape();
        bool checkOutOfBounds();
        bool checkAtSpawn();
        
        virtual void sound() = 0;

    friend class LANE;
    friend class PLAYER;
    friend class GAME;
    friend class MAP;
};


#endif