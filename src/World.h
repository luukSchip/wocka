//
//  World.h
//  firstSketch
//
//  Created by Luuk Schipperheyn on 07/12/14.
//
//

#ifndef __firstSketch__World__
#define __firstSketch__World__

#include "WorldBlock.h"
#include "Agent.h"

//class Agent;
class World {
    static const int NUM_COLUMNS = 50;
    
public:
    World(float _width, float _height);
    void draw();
    void updateAgent(Agent * _agent);
    void updateWorldBlocks();
    int score = 0;
    
private:
    float width, height, blockSize;
    int numBlocks, numRows;
    void initBlocks();
    vector<WorldBlock*> worldBlocks;
};



#endif /* defined(__firstSketch__World__) */
