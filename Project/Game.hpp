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
class Game{
private:
    sf::RenderWindow* window;
    sf::Event event;
    
public:
    Game();
    void run();
    virtual ~Game();
    
    
    void update();
    void render();
};

#include <stdio.h>


