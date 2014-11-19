//
//  BirdAgent.cpp
//  firstSketch
//
//  Created by Luuk Schipperheyn on 19/11/14.
//
//

#include "BirdAgent.h"

BirdAgent::BirdAgent(){}

void BirdAgent::init(int id, float x, float y){
    xPos = x;
    yPos = y;
    direction = 0;
    size = 1.1;
    r = 240;
    g = 150;
    b = 150;
}

void BirdAgent::updatePosition(){
    closestAgent = NULL;
    direction += ofRandom(0.06);
    direction = fmod((direction + ofRandom(0.1) - 0.05), (PI));
    xPos = fmod(xPos + sin(direction) * 1,ofGetWindowWidth());
    yPos = fmod(yPos + cos(direction) * 1,ofGetWindowHeight());
    size += (ofRandom(0.1) - 0.05);
    adjustToBounds(&size, 1, 2.5);
    r += (ofRandom(10) - 5);
    adjustToBounds(&r, 220, 255);
    //    g += (ofRandom(10) - 5);
    //    adjustToBounds(g, 60, 170);
    b += (ofRandom(10) - 5);
    adjustToBounds(&b, 60, 255);
}

void BirdAgent::interact(Agent * otherAgent){
    float distance = ofDist(xPos, yPos, otherAgent->getXPos(), otherAgent->getYPos());
    if (closestAgent != NULL) {
        float oldDistance = ofDist(xPos, yPos, closestAgent->getXPos(), closestAgent->getYPos());
        if(distance < oldDistance){
            closestAgent = otherAgent;
        }
    }else{
        closestAgent = otherAgent;
    }
    
}

void BirdAgent::draw(){
    ofSetColor(r, b, b, 25);
    //ofLine(xPos, yPos, closestAgent->getXPos(), closestAgent->getYPos());
    ofCircle(xPos, yPos, size);
}

void BirdAgent::interactWithClosestAgent(){
    float closestX = closestAgent->getXPos();
    float closestY = closestAgent->getYPos();
    float dist = ofDist(xPos, yPos, closestX, closestY);
    if(dist > 3){
        if(closestX < xPos){
            xPos-=2;
        }else{
            xPos+=2;
        }
        if(closestY < yPos){
            yPos-=2;
        }else{
            yPos+=2;
        }
    }else{
        if(closestX < xPos){
            xPos+=0.5;
        }else{
            xPos-=0.5;
        }
        if(closestY < yPos){
            yPos+=0.5;
        }else{
            yPos-=0.5;
        }
    }
}


