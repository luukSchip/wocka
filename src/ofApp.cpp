#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableSmoothing();
    ofSetFrameRate(30);
    ofBackground(0);
    
    for (int i = 0; i < NUM_AGENTS; i++) {
        //float xPos = ofRandom(ofGetWindowWidth());
        //float yPos = ofRandom(ofGetWindowHeight());
        float xPos = ofGetWindowWidth()/2;
        float yPos = ofGetWindowHeight()/2;
        //float xPos = ofGetWindowWidth()/2 + ofRandom(100) - 50;
        //float yPos = ofGetWindowHeight()/2 + ofRandom(100) - 50;
        BirdAgent birdAgent;
        birdAgent.init(i, xPos,yPos);
        birdAgents[i] = birdAgent;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < NUM_AGENTS; i++) {
        birdAgents[i].updatePosition();
        
        for (int j = 0; j < NUM_AGENTS; j++) {
            if(i!=j){
                birdAgents[i].interact(&birdAgents[j]);
            }
        }
        birdAgents[i].interactWithClosestAgent();
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < NUM_AGENTS; i++) {
        birdAgents[i].draw();
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
