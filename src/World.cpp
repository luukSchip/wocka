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
            worldBlocks.push_back(new WorldBlock(xPos,yPos,blockSize));
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
    worldBlocks[blockIndex]->setFill(true);
    _agent->setWorldBlock(worldBlocks[blockIndex]);
}