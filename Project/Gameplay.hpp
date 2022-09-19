/*
 THIS IS THE HPP FILE FOR THE ACTUAL GAME CODE.
 
 */
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
class Kingdom{
private:
    sf::RenderWindow* window;
    sf::Event event;
    
public:
    Kingdom();
    void PlayGame();
    virtual ~Kingdom();
    
    

};

#include <stdio.h>


/* Gameplay_hpp */
