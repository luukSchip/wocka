//
//  WorldBlock.cpp
//  firstSketch
//
//  Created by Luuk Schipperheyn on 07/12/14.
//
//

#include "WorldBlock.h"

WorldBlock::WorldBlock(float _x, float _y, float _size, float _food){
    x = _x;
    y = _y;
    size = _size;
    food = _food;
}


void WorldBlock::draw(){
    if(true){
        ofFill();
        //int r = ofMap(agents.size(), 0, 20, 0, 255);
        int r = 0;
        if(!home){
            ofSetColor(foodScent,homeScent/10,food/2);
        }else{
            ofSetColor(0, 0, 0);
        }
        if(food > 0){
            //            ofDrawBitmapString(ofToString(homeScent/10000), x, y + 10, 0);
            ofSetColor(0, 0, 255);
        }
        ofRect(x, y, size, size);
        if(food > 0){
            ofSetColor(255, 255, 255);
            ofDrawBitmapString(ofToString(food), x, y + 10, 0);
        }
//        for(int i = 1; i < agents.size(); i++){
//            //Agent fromAgent = agents[i-1];
//            //Agent toAgent = agents[i];
//            agents.front();
//            //agents.
//        }
    }else{
        //ofNoFill();
    }
}

void WorldBlock::setFill(Boolean _fill){
    fill = _fill;
}

void WorldBlock::removeAgent(Agent* _agent){
    numAgents--;
    agents.remove(_agent);
}

void WorldBlock::addAgent(Agent* _agent){
    numAgents++;
    agents.push_back(_agent);
}

void WorldBlock::interactWithAgent(Agent* _agent){
//    food++;
//    if(food > 255){
//        food = 255;
//    }
    //homeScent = homeScent + _agent->homeDist;
}

void WorldBlock::update(){
//    if(numAgents < 10){
//        if(--food < 0){
//            food = 0;
//        }
    //    }
    if(--foodScent < 0){
        foodScent = 0;
    }
    if(--homeScent < 0){
        homeScent = 0;
    }
}







