
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "MainMenu.hpp"
#include <iostream>
// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
using namespace std;
int main( ){
    sf::RenderWindow window(sf::VideoMode(600,600), "Game Menu!");
    
    Menu menu(window.getSize().x, window.getSize().y);
    
    while (window.isOpen()) {
        sf::Event event;
        
        while (window.pollEvent(event)) {
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
                                    break;
                                case 1:
                                    window.close();
                                    break;
                            }
                    }
                    break;
                    
                case sf::Event::Closed:
                    window.close();
                    break;
                    
                default:
                    break;
            }
        }
        window.clear();
        menu.draw(window);
        window.display();
    }
}
