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
    direction = ofRandom(2*PI);
    size = 1.1;
    r = 255;
    g = 0;
    b = 0;
    world = _world;
    speed = 1;
    id = _id;
}

void Agent::updatePosition(){
    xPos += sin(direction) * speed;
    yPos += cos(direction) * speed;
    adjustToBounds(&xPos,0,ofGetWindowWidth());
    adjustToBounds(&yPos,0,ofGetWindowHeight());
    if(xPos == ofGetWindowWidth() || xPos == 0 || yPos == ofGetWindowHeight() || yPos == 0){
        direction += PI;
    }
}

void Agent::adjustToBounds(float *value, float min, float max){
    if(*value > max){
        *value = max;
    }else if(*value < min){
        *value = min;
    }
}

void Agent::interact(Agent * otherAgent){}

void Agent::draw(){
    ofSetColor(0, 0, 0, 255);
    ofFill();
    ofCircle(xPos, yPos, size * 2+ 1);
    ofSetColor(r, g, b, 255);
    ofFill();
    ofCircle(xPos, yPos, size * 2);
    
}

void Agent::interactWithClosestAgent(){}

void Agent::interactWithWorld(){
    world->updateAgent(this);
}

void Agent::setWorldBlock(WorldBlock* _worldBlock){
    
    if(previousWorldBlock != NULL){
        if(_worldBlock != previousWorldBlock){
            if(goal == GOAL_GATHER_FOOD){
                bool lessFood = _worldBlock->foodScent <= previousWorldBlock->foodScent;
                bool moreHome = _worldBlock->homeScent < previousWorldBlock->homeScent;
                if(lessFood){
                    //direction = ofRandom(2*PI);
                    direction += ofRandom(PI/2) - PI/4;
                }
            }else if(goal == GOAL_GO_HOME){
                if(_worldBlock->homeScent <= previousWorldBlock->homeScent){
                    //direction = ofRandom(2*PI);
                    direction += ofRandom(PI*1.5) - PI*0.75;
                }
                if(_worldBlock->home){
                    goal = GOAL_GATHER_FOOD;
                    size++;
                    food--;
                    r = 255;
                    g = 0;
                    b = 0;
                    foodMemory = 0;
                    world->score++;
                    speed = 1;
                }
            }
        }
    }
    
//    if(worldBlock != NULL){
//        worldBlock->removeAgent(this);
//    }
//    worldBlock = _worldBlock;
//    worldBlock->addAgent(this);
//    worldBlock->interactWithAgent(this);
    
    // do home stuff
    if(_worldBlock->home){
        homeMemory = 500;
    }
    //    if(worldBlock->homeScent < 5){
    //        if(--homeDist < 0){
    //            homeDist = 0;
    //        }
    //    }
//    if(worldBlock->homeScent > 0){
//        homeMemory++;
//    }
    if(--homeMemory > 0){
        _worldBlock->homeScent += 50;
    }
    
    //do food stuff
    if(--foodMemory > 0){
        _worldBlock->foodScent += 50;
        
    }
    if(_worldBlock->food > 0){
        if(goal != GOAL_GO_HOME){
            goal = GOAL_GO_HOME;
            --_worldBlock->food;
            food += 1;
            b = 255;
            r = 0;
            g = 0;
            speed = 3;
        }
        foodMemory = 1000;
    }
    previousWorldBlock = _worldBlock;
}


