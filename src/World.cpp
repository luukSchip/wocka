//
//  World.cpp
//  firstSketch
//
//  Created by Luuk Schipperheyn on 07/12/14.
//
//

#include "World.h"

World::World(float _width, float _height){
    width = _width;
    height = _height;
    initBlocks();
}

void World::initBlocks(){
    blockSize = width / NUM_COLUMNS;
    numRows = (int) height / blockSize;
    numBlocks = numRows * NUM_COLUMNS;
    worldBlocks.empty();
    for(int i = 0; i < numRows; i++){
        float yPos = i * blockSize;
        for(int j = 0; j < NUM_COLUMNS; j++){
            float xPos = j * blockSize;
            float food = 0;//ofRandom(155) + 100;
            worldBlocks.push_back(new WorldBlock(xPos,yPos,blockSize,food));
        }
    }
}

void World::draw(){
    for(int i = 0; i < numBlocks; i++){
        worldBlocks[i]->draw();
    }
}

void World::updateAgent(Agent * _agent){
    float agentX = _agent->xPos;
    float agentY = _agent->yPos;
    int xIndex = agentX / blockSize;
    int yIndex = agentY / blockSize;
    int blockIndex = xIndex + (yIndex * NUM_COLUMNS);
    if(blockIndex >= 0 && blockIndex < worldBlocks.size()){
        _agent->setWorldBlock(worldBlocks[blockIndex]);
    }
}

void World::updateWorldBlocks(){
    
    for(int i = 0; i < numBlocks; i++){
        worldBlocks[i]->update();
    }
}



