//
//  agent.cpp
//  firstSketch
//
//  Created by Luuk Schipperheyn on 18/11/14.
//
//

#include "Agent.h"


Agent::Agent(){
}

void Agent::init(int _id, float x, float y,World * _world){
    xPos = x;
    yPos = y;
    direction = 0;
    size = 1.1;
    r = 240;
    g = 150;
    b = 150;
    world = _world;
    id = _id;
}

void Agent::updatePosition(){}

void Agent::adjustToBounds(float *value, float min, float max){
    if(*value > max){
        *value = max;
    }else if(*value < min){
        *value = min;
    }
}

void Agent::interact(Agent * otherAgent){}

void Agent::draw(){}

void Agent::interactWithClosestAgent(){}

void Agent::interactWithWorld(){
    world->updateAgent(this);
}

void Agent::setWorldBlock(WorldBlock* _worldBlock){
    if(worldBlock != NULL){
        worldBlock->removeAgent(this);
    }
    worldBlock = _worldBlock;
    worldBlock->addAgent(this);
    worldBlock->interactWithAgent(this);
    speed = ofMap(worldBlock->food, 0, 255, 1.0, 5.0);
}

