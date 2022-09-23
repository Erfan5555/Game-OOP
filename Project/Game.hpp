//
//  Game.hpp
//  Project
//
//  Created by Oliver Askew on 19/9/2022.
//  Copyright © 2022 Oliver Askew. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "MainMenu.hpp"
#include <stdio.h>

class Game{
private:
    sf::RenderWindow* window;
    sf::Event event;
public:
    Game();
    ~Game();
    void run();
};
#endif /* Game_hpp */
