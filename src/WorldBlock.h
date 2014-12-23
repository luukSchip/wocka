//
//  WorldBlock.h
//  firstSketch
//
//  Created by Luuk Schipperheyn on 07/12/14.
//
//

#ifndef __firstSketch__WorldBlock__
#define __firstSketch__WorldBlock__

#include <stdio.h>
#include "ofMain.h"

class Agent;
class WorldBlock{
public:
    WorldBlock(float x, float y, float size);
    void draw();
    void setFill(Boolean _fill);
    void removeAgent(Agent* _agent);
    void addAgent(Agent* _agent);
    int numAgents = 0;
    
private:
    float x,y,size;
    Boolean fill = false;
    //unordered_set<Agent*> agents;
};

#endif /* defined(__firstSketch__WorldBlock__) */
