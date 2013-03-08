//
//  Scene.h
//  ThirDimension
//
//  Created by Axel Guilmin on 25/02/13.
//  Copyright (c) 2013 Axel Guilmin. All rights reserved.
//
//  Singleton to manage the OpenGL Scene
//

#ifndef __ThirDimension__Scene__
#define __ThirDimension__Scene__

#include <GLUT/GLUT.h>
#include "Block.h"
#include <vector>

class Scene
{
private:
    Scene();
    ~Scene();
    static Scene *instance;
    std::vector<Block*> blocks;
public:
    static Scene *sharedInstance();
    //float width;
    //float height;
    void turnOnLight();
    void init(int argc, char** argv);
    void generateEPSIBlocks();
    Block *getLastBlock();
    void draw();
};

#define gScene (Scene::sharedInstance())

#endif /* defined(__ThirDimension__Scene__) */
