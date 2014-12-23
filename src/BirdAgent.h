//
//  BirdAgent.h
//  firstSketch
//
//  Created by Luuk Schipperheyn on 19/11/14.
//
//

#ifndef __firstSketch__BirdAgent__
#define __firstSketch__BirdAgent__

#include <iostream>
#include <algorithm>
#include "Agent.h"

class BirdAgent : public Agent {
    
public:
    float direction;
    void init(int, float, float,World * _world);
    void updatePosition();
    void interact(Agent *otherAgent);
    void draw();
    ofPoint closestAgentCoords;
    int id;
    void interactWithClosestAgent();
    BirdAgent * closestBird;
    float size;
    float attraction;
};


#endif /* defined(__firstSketch__BirdAgent__) */

