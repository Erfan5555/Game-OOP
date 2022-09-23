//
//  Gameplay.hpp
//  Project
//
//  Created by Oliver Askew on 19/9/2022.
//  Copyright © 2022 Oliver Askew. All rights reserved.
//

//
//  Game.hpp
//  Project
//
//  Created by Oliver Askew on 19/9/2022.
//  Copyright © 2022 Oliver Askew. All rights reserved.
//
#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "MainMenu.hpp"
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
#include <memory>
#include "Button.hpp"
class Kingdom{
private:
    sf::RenderWindow* window;
    sf::Event event;
    sf::Font font;
    
public:
    Kingdom();
    void run();
    virtual ~Kingdom();
    
    

};

#include <stdio.h>


/* Gameplay_hpp */
