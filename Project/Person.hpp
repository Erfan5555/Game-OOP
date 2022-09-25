//
//  Person.hpp
//  Project
//
//  Created by Oliver Askew on 25/9/2022.
//  Copyright © 2022 Oliver Askew. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp
#include <string>
#include <stdio.h>
#include <SFML/Graphics.hpp>
class Person{
protected:
    std::string name;
    std::string job;
    sf::RectangleShape face;
public:
    Person();
    ~Person();
    void Showface(sf:: RenderWindow &window);
};

#endif /* Person_hpp */
