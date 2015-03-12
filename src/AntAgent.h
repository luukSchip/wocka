//
//  AntAgent.h
//  firstSketch
//
//  Created by Luuk Schipperheyn on 12/03/15.
//
//

#ifndef __firstSketch__AntAgent__
#define __firstSketch__AntAgent__

#include <iostream>
#include <algorithm>
#include "Agent.h"

class AntAgent : public Agent {

private:
    static const int GOAL_GATHER_FOOD = 0;
    static const int GOAL_GO_HOME = 1;
    
public:
    float direction;
    void init(int, float, float,World * _world);
    void updatePosition();
    void draw();
    void setWorldBlock(WorldBlock *_worldBlock);
};

#endif /* defined(__firstSketch__AntAgent__) */
