#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Library.h"

class Enemy
{
    protected:
        char **shape;
        int x, y;
        bool outMap;

    public:
        Enemy();
        Enemy(int x, int y);
        ~Enemy();
        void setShape(char **shape);
                

};


#endif