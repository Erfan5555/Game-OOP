#include <iostream>
#include <string>
#include "power.cpp"
#include "person.cpp"
#include <stdlib.h>
#include <fstream>
using namespace std;
int main(){
    advisor jeff("Jeff","Plumber",50);
    jeff.show_face(":>");
    jeff.speak("Hello there!");
    jeff.dead_advisor();
    
    king player("The","King",250,10);
    player.set_years_in_power(20);
    cout<<"Years alive"<<player.years_alive<<endl;
    player.speak("Hello there?");
    
}