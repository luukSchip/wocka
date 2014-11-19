//
//  agent.h
//  firstSketch
//
//  Created by Luuk Schipperheyn on 18/11/14.
//
//

#ifndef __firstSketch__Agent__
#define __firstSketch__Agent__

#include <iostream>
#include <algorithm>    // std::max
#include "ofMain.h"

class Agent {
    static const int MAX_INTERACT_DIST = 50;
    static const int SPEED = 4;
    
public:
    float xPos, yPos;
    void adjustToBounds(float *value,float min,float max);
    Agent();
    float direction;
    void init(int, float, float);
    void updatePosition();
    float getXPos(){return xPos;};
    float getYPos(){return yPos;};
    void interact(Agent *otherAgent);
    void draw();
    ofPoint closestAgentCoords;
    int id;
    void interactWithClosestAgent();
    Agent * closestAgent;
    float size;
    float r,g,b;
};


#endif /* defined(__firstSketch__agent__) */
