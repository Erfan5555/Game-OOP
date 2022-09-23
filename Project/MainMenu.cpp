//
//  MainMenu.cpp
//  Project
//
//  Created by Oliver Askew on 18/9/2022.
//  Copyright © 2022 Oliver Askew. All rights reserved.
//
#include <iostream>
#include "MainMenu.hpp"
Menu::Menu(float width, float height){
    if (!font.loadFromFile("Fonts/Roboto-Medium.ttf")){
        //handle error
    }
    text[0].setFont(font);
    text[0].setCharacterSize(70);
    text[0].setFillColor(sf::Color::Red);
    text[0].setString("Play");
    text[0].setPosition(sf::Vector2f(width/2.1, height/(MAX_NUMBER_OF_ITEMS+1)*1));
    text[1].setFont(font);
    text[1].setCharacterSize(70);
    text[1].setFillColor(sf::Color::White);
    text[1].setString("Exit");
    text[1].setPosition(sf::Vector2f(width/2.1, height/(MAX_NUMBER_OF_ITEMS+1)*2));
    
    selectedItemIndex = 0;
}
Menu::~Menu( ){}
void Menu::draw(sf::RenderWindow &window){
    for(int i =0; i< MAX_NUMBER_OF_ITEMS; i++){
        window.draw(text[i]);
    }
}
void Menu::MoveUp(){
    
    if (selectedItemIndex - 1 >= 0){
        
        text[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        text[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}
void Menu::MoveDown(){
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS){
        text[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        text[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}
