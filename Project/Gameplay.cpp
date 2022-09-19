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
  this->  window = new sf::RenderWindow(sf::VideoMode(600,600), "welcome to the game");
    
}

        
void Kingdom::PlayGame(){
    
    
    Menu menu(window->getSize().x, window->getSize().y);
    while (window->isOpen()) {
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
                    
                            
                  
            }
        }
        window->clear();
    
        window->display();
    }


Kingdom::~Kingdom(){
    delete this->window;
}




