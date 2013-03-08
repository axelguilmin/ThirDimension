//
//  Scene.cpp
//  ThirDimension
//
//  Created by Axel Guilmin on 25/02/13.
//  Copyright (c) 2013 Axel Guilmin. All rights reserved.
//

#include "Scene.h"
#include <stdlib.h>
#include "Types.h"

Scene::Scene()
{
    //this->width = 0;
    //this->height = 0;
    // TODO: Optimized Pool with malloc
    this->blocks = std::vector<Block*>();
}
void Scene::init(int argc, char** argv)
{
    // GLUT Window Initialization:
    glutInit(&argc, argv);
    
    glutInitWindowPosition(50, 50);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("ThirDimension");
    
    glLoadIdentity();
    
    // Enable Depth test
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    
    // TODO: anti-aliasing
    //glEnable(GL_POINT_SMOOTH);
    //glEnable(GL_LINE_SMOOTH);
    //glEnable(GL_POLYGON_SMOOTH);
    //glHint(GL_POLYGON_SMOOTH, GL_NICEST);
    
    // Enable Blending
    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
Scene::~Scene()
{
    this->blocks.clear();
}
Scene *Scene::instance = 0x00;
Scene *Scene::sharedInstance()
{
    if(!instance)
        instance = new Scene();

    return instance;
}
void Scene::turnOnLight()
{
    // TODO: !!!
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    GLfloat light_ambient[] = {1.0f, 1.0f, 1.0f, 0.0f}; // Color, Intensity
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 0.0f}; // Color, Intensity
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0}; //
    GLfloat light_position[] = {-1.0f, -1.0f, -1.0f, 1.0f}; // Position, 1.0
    //glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    //glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    //glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    //glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}
void Scene::generateEPSIBlocks()
{
    // TODO: Define it on Types
    Color RED    = {0.875f, 0.008f, 0.212f, 0.000f};
    Color GREEN  = {0.322f, 0.682f, 0.114f, 0.000f};
    Color BLUE   = {0.000f, 0.547f, 0.804f, 0.000f};
    Color ORANGE = {0.941f, 0.502f, 0.055f, 0.000f};
    Color YELLOW = {1.000f, 0.894f, 0.000f, 0.000f};
    Color INDIGO = {0.619f, 0.200f, 0.545f, 0.000f};
    Color SOGAY  = {0.384f, 0.134f, 0.400f, 0.000f};
    
    this->blocks.push_back( Block::create(RED, 0.4f, Vertex(-0.50f, 0.50f), Vertex(0.0f ,0.50f), Vertex(-0.50f, 0.0f)));
    this->blocks.push_back( Block::create(YELLOW, 0.4f,
                                          Vertex(0.00f, 0.50f),
                                          Vertex(0.50f, 0.50f),
                                          Vertex(-0.25f, 0.25f),
                                          Vertex(0.25f, 0.25f)));
    this->blocks.push_back( Block::create(ORANGE, 0.4f, Vertex(-0.25f, 0.25f), Vertex(0.25f, 0.25f), Vertex(0.0f, 0.0f)));
    this->blocks.push_back( Block::create(INDIGO, 0.4f,
                                          Vertex(-0.50f,0.00f),
                                          Vertex(-0.25f, -0.25f),
                                          Vertex(-0.25f, 0.25f),
                                          Vertex(0.0f, 0.0f))); 
    this->blocks.push_back( Block::create(GREEN, 0.4f, Vertex(0.50f,-0.50f), Vertex(0.50f,0.50f), Vertex(-0.0f,0.0f)));
    this->blocks.push_back( Block::create(BLUE, 0.4f, Vertex(-0.50f, -0.50f), Vertex(0.50f, -0.50f), Vertex(0.0f,0.0f)));
    
    this->blocks.push_back( Block::create(SOGAY, 0.4f, Vertex(-0.60f, -0.50f), Vertex(-0.60f, 0.00f), Vertex(-0.35f, -0.25f)));
}
void Scene::draw()
{
    // Iterate and draw each block
    static std::vector<Block*>::iterator it;
    for(it = this->blocks.begin(); it != this->blocks.end(); it++)
    {
        (*it)->draw();
    }
}
Block *Scene::getLastBlock()
{
    return this->blocks.back();
}