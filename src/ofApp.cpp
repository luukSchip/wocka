#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableSmoothing();
    ofSetFrameRate(30);
    ofBackground(255);
    
    world =  new World(ofGetWindowWidth(), ofGetWindowHeight());
    for (int i = 0; i < NUM_AGENTS; i++) {
        //float xPos = ofRandom(ofGetWindowWidth());
        //float yPos = ofRandom(ofGetWindowHeight());
        float xPos = ofGetWindowWidth()/2;
        float yPos = ofGetWindowHeight()/2;
        //float xPos = ofGetWindowWidth()/2 + ofRandom(100) - 50;
        //float yPos = ofGetWindowHeight()/2 + ofRandom(100) - 50;
        Agent agent;
        agent.init(i, xPos,yPos, world);
        agents[i] = agent;
    }
    //world->draw();
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < NUM_AGENTS; i++) {
        agents[i].updatePosition();
        agents[i].interactWithWorld();
    }
    world->updateWorldBlocks();
}

//--------------------------------------------------------------
void ofApp::draw(){
    world->draw();
    for (int i = 0; i < NUM_AGENTS; i++) {
        agents[i].draw();
    }
    
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
