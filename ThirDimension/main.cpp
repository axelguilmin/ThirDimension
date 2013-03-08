//
//  main.c
//  ThirDimension
//
//  Created by Axel Guilmin on 25/02/13.
//  Copyright (c) 2013 Axel Guilmin All rights reserved.
//

#include "Block.h"
#include "Types.h"
#include "Scene.h"

#define EXIT_SUCESS 0
#define EXIT_FAILURE 1

#define FPS 1000 / 60

#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_RIGHT 67
#define KEY_LEFT 68
#define KEY_ESC 27

#include <GLUT/GLUT.h>

void reshape(int width,int height)
{
    // Set our viewport to the size of our window
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    // Switch to the projection matrix so that we can manipulate how our scene is viewed
    glMatrixMode(GL_PROJECTION);
    // Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)
    glLoadIdentity();
    // Set the Field of view angle (in degrees), the aspect ratio of our window, and the new and far planes
    gluPerspective(0, (GLfloat)width / (GLfloat)height, 1.0, 100.0);
    // Switch back to the model view matrix, so that we can start drawing shapes correctly
    glMatrixMode(GL_MODELVIEW);
}
//!\ Experimenation zone 
Block *animatedBlock;
void gayAnim(int fps)
{
    static Vertex delta = Vertex(0,0,0);
    static bool neg = true;
    
    // Min and Max delta
    if(delta.x < -0.1 || delta.x > 0.1)
        neg = !neg;
 
    // Move the block and remember how much we moved
    animatedBlock->moveBy(Vertex(neg ? -0.001 : 0.001,0,0));
    delta += Vertex(neg ? -0.001 : 0.001,0,0);
    
    // Repeat
    glutTimerFunc(fps, gayAnim, fps);
}
//!\ Experimenation zone
void display()
{
    gScene->generateEPSIBlocks();
    // Start animations
    // TODO: Animation manager
    animatedBlock = gScene->getLastBlock();
    glutTimerFunc(0, gayAnim, FPS);
}
void idle(int fps)
{
    // Clear frame buffer and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glFlush();
    
    // Rotate
    //glRotated(-0.1, 0, 0.5, 0.0);
    
    // Testing
    //glutSolidTeapot(0.5);
    
    // Draw all items
    gScene->draw();
    
    // Make sure changes appear onscreen
    glutSwapBuffers();
    
    // Repeat
    glutTimerFunc(fps, idle, fps);
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {            
        case KEY_ESC:
            //exit(EXIT_SUCESS);
            break;
            
        case KEY_LEFT:
        case 'q':
            glRotated(5, 0.0, 1.0, 0.0);
            break;
            
        case KEY_RIGHT:
        case 'd':
            glRotated(-5, 0.0, 1.0, 0.0);
            break;
            
        case KEY_UP:
        case 'z':
            glRotated(5, 1.0, 0.0, 0.0);
            break;
            
        case KEY_DOWN:
        case 's':
            glRotated(-5, 1.0, 0.0, 0.0);
            break;
    }
}
void mouse(int button, int state, int x, int y)
{
    // Do nothing
}
void motion(int x, int y)
{
    // Do nothing
}
int main(int argc, char** argv)
{    
    // GLUT Window Initialization:
    gScene->init(argc, argv);
    gScene->turnOnLight();
    
    // Register callbacks:
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutTimerFunc(0, idle, FPS); //glutIdleFunc(idle);
    
    // Turn the flow of control over to GLUT
    glutMainLoop();
    
    // Get the initial time, for use by animation
//#ifdef _WIN32
//    last_idle_time = GetTickCount();
//#else
//    gettimeofday (&last_idle_time, NULL);
//#endif
   
    return EXIT_SUCESS;
}
