//
//  Button.cpp
//  Project
//
//  Created by Oliver Askew on 23/9/2022.
//  Copyright © 2022 Oliver Askew. All rights reserved.
//

#include "Button.hpp"
Button::Button(){
    
}

Button::Button(std::string t){
    if (!font.loadFromFile("Fonts/Roboto-Medium.ttf")){
        //handle error
    }
    text.setFont(font);
    text.setCharacterSize(30);
    text.setString(t);
    text.setFillColor(sf::Color::White);
    
    button.setFillColor(sf::Color::Green);
    button.setSize(sf::Vector2f(300,300));
}

void Button::hoverSize(){
    button.setSize(sf::Vector2f(350,350));
}
void Button::normalSize(){
    button.setSize(sf::Vector2f(300,300));
}

void Button::setPosition(sf::Vector2f pos){
    button.setPosition(pos);
    
    float xPos = (pos.x + button.getGlobalBounds().width/2)-(text.getGlobalBounds().width/2);
    float yPos = (pos.y + button.getGlobalBounds().height/2)-(text.getGlobalBounds().height/2);
    
    text.setPosition(xPos, yPos);
    
}

void Button::drawTo(sf::RenderWindow &window){
    window.draw(button);
    window.draw(text);

}


bool Button::mouseOver(sf::RenderWindow &window){
    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;
    
    float btnPosX = button.getPosition().x;
    float btnPosY = button.getPosition().y;
    
    float btnxPosWidth = button.getPosition().x + button.getGlobalBounds().width;
    float btnyPosHeight = button.getPosition().y + button.getGlobalBounds().height;
    
    if (mouseX<btnxPosWidth && mouseX>btnPosX && mouseY<btnyPosHeight && mouseY >btnPosY) {
        return true;
    }
    return false;
}

Button::~Button(){
    
}
