//
//  King.hpp
//  Project
//
//  Created by Oliver Askew on 25/9/2022.
//  Copyright © 2022 Oliver Askew. All rights reserved.
//

#ifndef King_hpp
#define King_hpp
#include "Advisor.hpp"
#include <stdio.h>
class King: public Advisor{

    int CurVal;
    int ArmVal;
    int PeoVal;
    int WelVal;
public:
    King(std::string kingName);
    ~King();
    void killAdvisor();
    
};
#endif /* King_hpp */
