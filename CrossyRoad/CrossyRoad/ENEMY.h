#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Library.h"

class ENEMY
{
    protected:
        char **shape;
        int x, y;
        bool outOfMap;

    public:
        ENEMY();
        ENEMY(int x, int y);
        ~ENEMY();
        void setShape(char **shape);
                
    friend class LANE;
};


#endif