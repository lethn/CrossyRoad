#ifndef _ROAD_H_
#define _ROAD_H_

#include "Library.h"
#include "LANE.h"

class ROAD
{
    private: 
        vector<LANE> lanes;
        
    public:
        ROAD() = default;
        ~ROAD() = default;
};

#endif