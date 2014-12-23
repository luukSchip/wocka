#pragma once

#include "ofMain.h"
#include "BirdAgent.h"
#include "Agent.h"
#include "World.h"
#include "WorldBlock.h"

#define NUM_AGENTS 1000

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        BirdAgent birdAgents[NUM_AGENTS];
        World * world;
};
