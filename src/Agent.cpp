//
//  agent.cpp
//  firstSketch
//
//  Created by Luuk Schipperheyn on 18/11/14.
//
//

#include "Agent.h"

Agent::Agent(){}

void Agent::init(int id, float x, float y){
    xPos = x;
    yPos = y;
    direction = 0;
    size = 1.1;
    r = 240;
    g = 150;
    b = 150;
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


