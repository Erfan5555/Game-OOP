//
//  Button.hpp
//  Project
//
//  Created by Oliver Askew on 23/9/2022.
//  Copyright © 2022 Oliver Askew. All rights reserved.
//

#ifndef Button_hpp
#define Button_hpp
#include "SFML/Graphics.hpp"
#include <stdio.h>
class Button{
private:
    sf::RectangleShape button;
    sf::Text text;
    sf::Font font;
    
public:
    Button();
    Button(std::string text);
    ~Button();
    void hoverSize();
    void normalSize();
    void setPosition(sf::Vector2f pos);
    void drawTo(sf::RenderWindow &window);
    bool mouseOver(sf::RenderWindow &window);
    
};
#endif /* Button_hpp */
