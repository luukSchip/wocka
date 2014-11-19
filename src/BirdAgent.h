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
    BirdAgent();
    float direction;
    void init(int, float, float);
    void updatePosition();
    void interact(Agent *otherAgent);
    void draw();
    ofPoint closestAgentCoords;
    int id;
    void interactWithClosestAgent();
    Agent * closestAgent;
    float size;
};


#endif /* defined(__firstSketch__BirdAgent__) */

