//
//  Block.cpp
//  ThirDimension
//
//  Created by Axel Guilmin on 25/02/13.
//  Copyright (c) 2013 Axel Guilmin. All rights reserved.
//

#include "Block.h"
#include "stdlib.h"

Block::Block(unsigned char verticesCount, Color color)
{
    this->vertices = (Vertex*) malloc(verticesCount * sizeof(Vertex));
    this->verticesCount = verticesCount;
    
    this->color[0] = color[0];
    this->color[1] = color[1];
    this->color[2] = color[2];
    this->color[3] = color[3];
}
Block::~Block()
{
    delete [] this->vertices;
}
// TODO: factorize create() methods
Block *Block::create(Color color, double depth, Vertex p1, Vertex p2, Vertex p3)
{
    Block *pRet = new Block(10, color);
    
    pRet->vertices[0] = p1;
    pRet->vertices[1] = p2;
    pRet->vertices[2] = p3;
    pRet->vertices[3] = p3; pRet->vertices[3].z -= depth;
    pRet->vertices[4] = p1;
    pRet->vertices[5] = p1; pRet->vertices[5].z -= depth;
    pRet->vertices[6] = p2;
    pRet->vertices[7] = p2; pRet->vertices[7].z -= depth;
    pRet->vertices[8] = p3; pRet->vertices[8].z -= depth;
    pRet->vertices[9] = p1; pRet->vertices[9].z -= depth;
    
    return pRet;

}
Block *Block::create(Color color, double depth, Vertex p1, Vertex p2, Vertex p3, Vertex p4)
{
    Block *pRet = new Block(14, color);
    
    pRet->vertices[0] = p1;
    pRet->vertices[1] = p2;
    pRet->vertices[2] = p3;
    pRet->vertices[3] = p4;
    pRet->vertices[4] = p4;  pRet->vertices[4].z -= depth;
    pRet->vertices[5] = p2;
    pRet->vertices[6] = p2;  pRet->vertices[6].z -= depth;
    pRet->vertices[7] = p1;
    pRet->vertices[8] = p1;  pRet->vertices[8].z -= depth;
    pRet->vertices[9] = p3;
    pRet->vertices[10] = p3; pRet->vertices[10].z -= depth;
    pRet->vertices[11] = p4; pRet->vertices[11].z -= depth;
    pRet->vertices[12] = p1; pRet->vertices[12].z -= depth;
    pRet->vertices[13] = p2; pRet->vertices[13].z -= depth;
    
    return pRet;
}
void Block::draw()
{
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, this->color);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(Vertex), this->vertices);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, this->verticesCount);
    glDisableClientState(GL_VERTEX_ARRAY);
}
void Block::moveBy(Vertex by)
{
    for(int i = 0; i < this->verticesCount; ++i)
    {
        this->vertices[i] += by;
    }
}
