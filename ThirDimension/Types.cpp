//
//  Types.cpp
//  ThirDimension
//
//  Created by Axel on 26/02/13.
//  Copyright (c) 2013 Axel. All rights reserved.
//

#include "Types.h"

Vertex Vertex::getNormal(Vertex a, Vertex b, Vertex c)
{
    Vertex normal;
    
    normal.x = a.y * b.z - a.z * b.y;
    normal.y = a.z * b.x - a.x * b.z;
    normal.z = a.x * b.y - a.y * b.x;
    
    return normal;
}


