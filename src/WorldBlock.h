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
    WorldBlock(float x, float y, float size, float food);
    void draw();
    void setFill(Boolean _fill);
    void removeAgent(Agent* _agent);
    void interactWithAgent(Agent* _agent);
    void addAgent(Agent* _agent);
    void update();
    int numAgents = 0;
    float food;
    bool home = false;
    int foodScent = 0;
    int homeScent = 0;
    
private:
    float x,y,size;
    Boolean fill = false;
    list<Agent*> agents;
};

#endif /* defined(__firstSketch__WorldBlock__) */
