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


Game::Game(){
  this->  window = new sf::RenderWindow(sf::VideoMode(600,600), "Game Menu!");
    
}

        
void Game::run(){
    
    Menu menu(window->getSize().x, window->getSize().y);
    while (window->isOpen()) {
        while (window->pollEvent(event)) {
            switch (event.type) {
                    
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                            
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;
                            
                            case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;
                        case sf::Keyboard::Return:
                            switch (menu.GetPressedItem()) {
                                case 0:
                                    cout<<"Play button prseed"<<endl;
                                    window->close();
                                    //THIS WILL PROBABLY HAVE THE SECOND WINODW CLOSING
                                    //THE MAIN MENU WITH THE GAME CODE HERE
                                    cout<<"Game playing"<<endl;
                                    break;
                                case 1:
                                    window->close();
                                    break;
                            }
                    }
                    break;
                    
                case sf::Event::Closed:
                    window->close();
                    break;
                    
                default:
                    break;
            }
        }
        window->clear();
        menu.draw(*window);
        window->display();
    }
}

Game::~Game(){
    delete this->window;
}

void Game::update(){
    
}
void Game::render(){
    
}


