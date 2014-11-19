//
//  AttractorAgent.h
//  firstSketch
//
//  Created by Luuk Schipperheyn on 19/11/14.
//
//

#ifndef __firstSketch__AttractorAgent__
#define __firstSketch__AttractorAgent__

#include <iostream>
#include "Agent.h"
class AttractorAgent : public Agent{
public:
    void updatePosition();
    void draw();
};

#endif /* defined(__firstSketch__AttractorAgent__) */
