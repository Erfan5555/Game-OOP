//
//  MainMenu.hpp
//  Project
//
//  Created by Oliver Askew on 18/9/2022.
//  Copyright © 2022 Oliver Askew. All rights reserved.
//
#include "SFML/Graphics.hpp"
#ifndef MainMenu_hpp
#define MainMenu_hpp
#define  MAX_NUMBER_OF_ITEMS 2
#include <stdio.h>
#include "Gameplay.hpp"
class Menu{
public:
    Menu(float width, float height);
    ~Menu();
    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem(){return selectedItemIndex;};
private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text text[MAX_NUMBER_OF_ITEMS];
         };
#endif /* MainMenu_hpp */
