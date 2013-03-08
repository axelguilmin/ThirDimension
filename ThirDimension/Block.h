//
//  Block.h
//  ThirDimension
//
//  Created by Axel Guilmin on 25/02/13.
//  Copyright (c) 2013 Axel Guilmin. All rights reserved.
//
//  Represent a polygon with 3..N face + relief
//  For example, a triangle will have 5 faces
//

#ifndef __ThirDimension__Block__
#define __ThirDimension__Block__

#include "Types.h"

class Block
{
private:
    // Vertices used to draw this block
    Vertex *vertices;
    unsigned char verticesCount;
    // The Color of the block
    Color color;
    // Constructors
    Block() {};
    Block(unsigned char size, Color color);
    ~Block();
public:
    // Create a block and return it
    static Block *create(Color color, double depth, Vertex p1, Vertex p2, Vertex p3);
    static Block *create(Color color, double depth, Vertex p1, Vertex p2, Vertex p3, Vertex p4);
    // Actually draw it
    void draw();
    // Change the position of all vertices
    void moveBy(Vertex by);
}; 


#endif /* defined(__ThirDimension__Block__) */
