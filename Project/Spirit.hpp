//
//  Spirit.hpp
//  Project
//
//  Created by Oliver Askew on 25/9/2022.
//  Copyright © 2022 Oliver Askew. All rights reserved.
//

#ifndef Spirit_hpp
#define Spirit_hpp
#include "King.hpp"
#include <stdio.h>
class Spirit: public King{
    
    
public:
    Spirit();
    ~Spirit();
    void killKing();
    void castCurse();
};

#endif /* Spirit_hpp */
