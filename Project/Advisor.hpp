//
//  Advisor.hpp
//  Project
//
//  Created by Oliver Askew on 25/9/2022.
//  Copyright © 2022 Oliver Askew. All rights reserved.
//

#ifndef Advisor_hpp
#define Advisor_hpp
#include "Person.hpp"
#include <stdio.h>
class Advisor: public Person
{
protected:
    std::string speach;
    
public:
    Advisor();
    ~Advisor();
    
};
#endif /* Advisor_hpp */
