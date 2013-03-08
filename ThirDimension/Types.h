//
//  Types.h
//  ThirDimension
//
//  Created by Axel Guilmin on 26/02/13.
//  Copyright (c) 2013 Axel Guilmin. All rights reserved.
//
//  Some common type used in the project
//

#ifndef ThirDimension_Types_h
#define ThirDimension_Types_h

#include <GLUT/GLUT.h>

typedef struct Vertex
{
    // Properties
    GLfloat x, y, z;
    
    // Constructors
    Vertex(GLfloat x, GLfloat y, GLfloat z) : x(x), y(y), z(z) {}
    Vertex(GLfloat x, GLfloat y) : x(x), y(y), z(0) {}
    Vertex() {}
    
    // Methods
    Vertex getNormal(Vertex a, Vertex b, Vertex c);
    
    // Operators
    inline bool operator==(const Vertex& rhs)
    {
        return this->x == rhs.x
        && this->y == rhs.y
        && this->z == rhs.z;
    }
    inline Vertex& operator+=(const Vertex& rhs)
    {
        this->x += rhs.x;
        this->y += rhs.y;
        this->z += rhs.z;
        return *this;
    }
} Vertex;
typedef struct Vertex Normal;

typedef GLfloat Color[4];

#endif
