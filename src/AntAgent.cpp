//
//  AntAgent.cpp
//  firstSketch
//
//  Created by Luuk Schipperheyn on 12/03/15.
//
//

#include "AntAgent.h"


void AntAgent::init(int id, float x, float y, World * _world){
    xPos = x;
    yPos = y;
    direction = ofRandom(2*PI);
    size = 5;
    r = 240;
    g = 150;
    b = 150;
    world = _world;
}

void AntAgent::updatePosition(){
}

void AntAgent::draw(){
}

void AntAgent::setWorldBlock(WorldBlock *_worldBlock){
    size = 6;
}


