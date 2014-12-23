//
//  WorldBlock.cpp
//  firstSketch
//
//  Created by Luuk Schipperheyn on 07/12/14.
//
//

#include "WorldBlock.h"

WorldBlock::WorldBlock(float _x, float _y, float _size){
    x = _x;
    y = _y;
    size = _size;
}


void WorldBlock::draw(){
    if(fill){
        ofFill();
        ofSetColor(0);
        ofRect(x, y, size, size);
        ofSetColor(255,0,0);
        ofDrawBitmapString(ofToString(numAgents), x, y + 10, 0);
    }else{
        //ofNoFill();
    }
}

void WorldBlock::setFill(Boolean _fill){
    fill = _fill;
}

void WorldBlock::removeAgent(Agent* _agent){
    numAgents--;
    //agents.get_allocator()
}

void WorldBlock::addAgent(Agent* _agent){
    numAgents++;
    //agents.push_back(_agent);
}