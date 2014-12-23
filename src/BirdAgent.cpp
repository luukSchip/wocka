//
//  BirdAgent.cpp
//  firstSketch
//
//  Created by Luuk Schipperheyn on 19/11/14.
//
//

#include "BirdAgent.h"

void BirdAgent::init(int id, float x, float y, World * _world){
    xPos = x;
    yPos = y;
    direction = 1;
    size = 5;
    attraction = 10;
    r = 240;
    g = 150;
    b = 150;
    world = _world;
}

void BirdAgent::updatePosition(){
    closestAgent = NULL;
    direction = ofRandom(2*PI);
    //direction = fmod((direction + ofRandom(0.1) - 0.05), (PI));
    xPos = fmod(xPos + sin(direction) * 2,ofGetWindowWidth());
    yPos = fmod(yPos + cos(direction) * 2,ofGetWindowHeight());
    //size += (ofRandom(0.1) - 0.05);
    adjustToBounds(&size, 2, 7);
    r += (ofRandom(10) - 5);
    adjustToBounds(&r, 220, 255);
    //    g += (ofRandom(10) - 5);
    //    adjustToBounds(g, 60, 170);
    b += (ofRandom(10) - 5);
    adjustToBounds(&b, 60, 255);
}

void BirdAgent::interact(Agent * otherAgent){
    if( BirdAgent* otherBird = dynamic_cast<BirdAgent*>(otherAgent)){
        float distance = ofDist(xPos, yPos, otherBird->getXPos(), otherBird->getYPos());
        if (closestBird != NULL) {
            float oldDistance = ofDist(xPos, yPos, closestBird->getXPos(), closestBird->getYPos());
            if(distance < oldDistance){
                closestBird = otherBird;
            }
        }else{
            closestBird = otherBird;
        }
    }else{
        //cout << "is niet vogel" << "\n";
    }
    
    
}

void BirdAgent::draw(){
    ofSetColor(r, b, b, 50);
    //ofLine(xPos, yPos, closestAgent->getXPos(), closestAgent->getYPos());
    ofFill();
    //ofCircle(xPos, yPos, (attraction + 0.501) * 30);
    ofCircle(xPos, yPos, 2);
}

void BirdAgent::interactWithClosestAgent(){
//    float closestX = closestBird->getXPos();
//    float closestY = closestBird->getYPos();
//    float dist = ofDist(xPos, yPos, closestX, closestY);
//    if(dist > 3){
//        if(closestX < xPos){
//            xPos-= 2;
//        }else{
//            xPos+=2;
//        }
//        if(closestY < yPos){
//            yPos-=2;
//        }else{
//            yPos+=2;
//        }
//    }else{
//        if(closestX < xPos){
//            xPos+=0.5;
//        }else{
//            xPos-=0.5;
//        }
//        if(closestY < yPos){
//            yPos+=0.5;
//        }else{
//            yPos-=0.5;
//        }
    //    }
    //int xDir = (xPos - closestBird->getXPos()) > 0 ? -1 : 1;
    //int yDir = (yPos - closestBird->getYPos()) > 0 ? -1 : 1;
    float xDiff = (closestBird->getXPos() - xPos);
    float yDiff = (closestBird->getYPos() - yPos);
    float xIncrement = closestBird->attraction * xDiff;
    float yIncrement = closestBird->attraction * yDiff;
    xPos += xIncrement;
    yPos += yIncrement;
//    if(ofDist(xPos, yPos, closestBird->getXPos(), closestBird->getYPos()) > 5){
//        xPos += xIncrement;
//        yPos += yIncrement;
//    }else{
//        xPos -= xIncrement;
//        yPos -= yIncrement;
//    }
    attraction = 4 * ofDist(xPos,yPos,closestBird->xPos,closestBird->yPos) / ofDist(0, 0, ofGetWindowWidth(), ofGetWindowHeight()) - 0.05;
}


