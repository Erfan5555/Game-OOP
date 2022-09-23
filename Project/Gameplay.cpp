//
//  Gameplay.cpp
//  Project
//
//  Created by Oliver Askew on 19/9/2022.
//  Copyright © 2022 Oliver Askew. All rights reserved.
//

#include "Gameplay.hpp"
//
//  Game.cpp
//  Project
//
//  Created by Oliver Askew on 19/9/2022.
//  Copyright © 2022 Oliver Askew. All rights reserved.
//

#include "Game.hpp"
#include <string>
using namespace std;


Kingdom::Kingdom(){
  this->  window = new sf::RenderWindow(sf::VideoMode(1920,1080), "welcome to the game");
    if (!font.loadFromFile("Fonts/Roboto-Medium.ttf")){
        //handle error
    }
    
}

        
void Kingdom::run(){
    
    
    
        
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);

        while (this->window->isOpen())
        {
            sf::Event event;
            while (this->window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    this->window->close();
            }

            this->window->clear();
           this->window->draw(shape);
            this->window->display();
        }

     
    }



Kingdom::~Kingdom(){
    delete this->window;
    
}




