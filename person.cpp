#include <iostream>
#include <string>
using namespace std;
// Contains the abstract class of person, and class of advisor then king which is inhernted from advisor and spirit which is inherted
// from king.



// abstract class of person, person will not have any objects in the game.
//  speak() is virtual functions. i.e implemented in the derived classes.

class person { //base class to be built upon
    protected:
        string name; // name
        string job; // purpose
        bool live_or_dead; // true means living
    public:
        person(string name,string job): name(name), job( job){live_or_dead=true;} // constructor, initialisation
        person(): person(" ", " "){live_or_dead=true;} // constructor
        virtual void show_face(string face) = 0; // abstract class, these are implemented in each dervied class
        virtual void speak(string text) = 0;
};

class advisor : virtual public person { // advisor class
    public:
        int power;
        advisor(string name, string job, int power): person(name,job),power(power){live_or_dead=true;} // constructor, initialisation
        advisor(): advisor(" ", " ", 0){live_or_dead=true;}; // constructor, initialisation 
        void dead_advisor (){ // kill function
            live_or_dead= false; 
        }
        void speak(string text){ // speak function
            cout<<name<<" : "<<text<<endl;
        }
        void show_face(string face){ // visual representation
            cout<<face<<endl;
        }
};

class king : public advisor { // king class
    private:
        int years_alive; // round count
    public:
        king(string name_i, string job_i, int power_i, int years){// constructor
            name = name_i;
            job = job_i;
            power = power_i;
            years_alive = years;
            live_or_dead = true;
        }
        king (): king(" "," ",100, 0){ // initialisation
        }
        void set_years_in_power(int years){ // update round count
            years_alive=years;
        }
        void speak(string text){ // speak function
            cout<<text<<endl;
        }
        void dead_king (){ // end game function
            live_or_dead=false;
        }
        void kill_advisor(){ // kill advisor
            advisor::dead_advisor();
        }
};

class spirit : public king, virtual public person{ // highest level class
    protected :
        int power;
    public:
        spirit(string name, string job, int power, int years): person(name,job),
        power(power){live_or_dead=true;}  // constructor
        spirit (): spirit(" "," ",100, 0){} // initialisation
        void kill_king (){ // remove king
            king::dead_king();
        }
        void cast_spell(int value){
            // people::change_food_avaliable(-40);
            
        }
        void speak(string text){ // speak function
            cout<<text<<endl;
        }
        void show_face(){ // visualisation of spirit
            cout<<"imagine you are seeing a face right now"<<endl;
        }
};
