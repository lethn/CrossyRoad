#ifndef _DOG_H_
#define _DOG_H_

#include "ENEMY.h"

class DOG : public ENEMY{
public:
    DOG();
    DOG(int x, int y, bool type);
};

#endif