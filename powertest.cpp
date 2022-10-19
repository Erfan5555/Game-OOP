#include <iostream>
#include <string>
#include "power.cpp"
#include "person.cpp"
#include <stdlib.h>
#include <fstream>
using namespace std;
int main(){
    cout<<"PEOPLE TEST"<<endl;
    people* p = new people(25,25,25);
    p->show_vars();
    cout<<"change down"<<endl;
    p->change_Down();
    p->show_vars();
    cout<<"change up"<<endl;
    p->change_up();
    p->show_vars();
    cout<<"set variables"<<endl;
    p->change_employment(30);
    p->show_vars();
    p->change_entertainment(30);
    p->show_vars();
    p->change_food(30);
    p->show_vars();
    
    cout<<"CHURCH TEST"<<endl;
    church* c = new church(25,25);
    c->show_vars();
    cout<<"change down"<<endl;
    c->change_Down();
    c->show_vars();
    cout<<"change up"<<endl;
    c->change_up();
    c->show_vars();
    cout<<"set variables"<<endl;
    c->change_num_church(30);
    c->show_vars();
    c->change_pop_wealth(30);
    c->show_vars();

    cout<<"ARMY TEST"<<endl;
    army* a = new army(25,25,25);
    a->show_vars();
    cout<<"change down"<<endl;
    a->change_Down();
    a->show_vars();
    cout<<"change up"<<endl;
    a->change_up();
    a->show_vars();
    cout<<"set variables"<<endl;
    a->change_num_of_troops(30);
    a->show_vars();
    a->change_weapon_quality(30);
    a->show_vars();
    a->change_available_food(30);
    a->show_vars();

    cout<<"WEALTH TEST"<<endl;
    wealth* w = new wealth(25);
    w->show_vars();
    cout<<"change down"<<endl;
    w->change_Down();
    w->show_vars();
    cout<<"change up"<<endl;
    w->change_up();
    w->show_vars();
    cout<<"set variables"<<endl;
    w->set_wealth(30);
    w->show_vars();

    // stats class check
    stats file;
    file.update_stats(p,c,w,a);
    file.save_game(p,c,w,a);
    p->~people();
    c->~church();
    w->~wealth();
    a->~army();
    cout<<"New classes"<<endl;
    people *p = new people(25,25,25);
    church *c= new church(7,27);
    wealth *w = new wealth(25);
    army *a = new army (30,30,10);
    file.load_game(p,c,w,a);
    file.update_stats(p,c,w,a);
}