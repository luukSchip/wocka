//
//  AttractorAgent.cpp
//  firstSketch
//
//  Created by Luuk Schipperheyn on 19/11/14.
//
//

#include "AttractorAgent.h"

void AttractorAgent::updatePosition(){
    xPos = ofGetMouseX();
    yPos = ofGetMouseY();
}

void AttractorAgent::draw(){
    ofSetColor(0, 255, 0);
    ofCircle(xPos, yPos, 10);
}