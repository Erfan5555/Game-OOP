#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
// abstract class since the method rebel and kill king is not implemented.
// No object of this class is intendeded to be instantiated.

class show_all_variables { // intended for programmers only 
    public:
        virtual void show_vars()=0;
};

class power : public show_all_variables{ // base class for each power
    public:
        int king_popularity;
        int *Overall_value = new int(2);
        bool game_switch; // This ends the king's life
        power (int popularity, int satsifactionValue){ // intialised the constructor of power
            game_switch = true;
            king_popularity = popularity;
            *Overall_value = satsifactionValue;
        }
        power(): power(100,100){game_switch=true;} // intliases the constructor if no values are inputed
        virtual void Rebel ()=0;
        virtual int set_overall_value()=0; //Overall value is the number seen 
        //on the bottom of each sign of a power. it is calculated from different variables
        // in each power. 
        // set_overall_value will be put in after each time a card has been drawen and the user
        // makes a decsion
        void show_overall_var(){ // present total score
            cout<<"overall value is: "<<*Overall_value<<endl;
        }
        void set_king_popularity(int new_value){ // changes popularity
            king_popularity=new_value;
        }
        void kill_king(){ // ends the game
            game_switch=false;
            cout<<"game ended"<<endl;
        }
};

class people : public power{ // creates people class
    public:
        int employment; // defines variables apart of people
        int entertainment;
        int food;
        people(int employment_new_Value, int entertainment_new_Value, 
        int food_new_Value): power(50,50), employment(employment_new_Value),entertainment(entertainment_new_Value)
        ,food(food_new_Value){} // intialising the constructor
        people(): people(25,25,25){}
        void Rebel ( ){ // special event
            employment = employment-70;
            king_popularity = king_popularity-70;
        }
        int set_overall_value(){ // changes value and checks for game end
            int value= employment + entertainment + food + king_popularity;
            *Overall_value = value;
            if (value < 0){
                value = 0;
                game_switch = false; // ends the king's life and start a new game
            }
            if (value > 100){
                value = 100;
                game_switch = false; // ends the king's life and start a new game
            }
            return value;
        }
        void change_up(){ // increase each value randomly
            srand((unsigned) time(NULL));
            this->employment = employment + (1+(rand()%15));
            this->entertainment = entertainment + (1+(rand()%15));
            this->food = food + (1+(rand()%15));
        }
        void change_Down(){ // decrease each value randomly
            srand((unsigned) time(NULL));
            this->employment = employment - (1+(rand()%15));
            this->entertainment = entertainment - (1+(rand()%15));
            this->food = food - (1+(rand()%15));
        }
        void change_employment (int employment ){ // change value
            this->employment = employment;
        }
        void change_entertainment (int entertainment ){ // change value
            this-> entertainment = entertainment;
        }
        void change_food (int food){ // change value
            this-> food = food;
        }
        void show_vars(){ // display variables
            cout<<"Employment is: "<<employment<<endl;
            cout<<"Available food is: "<<food<<endl;
            cout<<"Entertainment value is: "<<entertainment<<endl;
            cout<<"Overall value is: "<<Overall_value<<endl;
        }
};

class church : public power { // creates church class
    public:
        int num_church; // defines variables apart of church
        int pop_wealth;
        // initialises the church constructors 
        church (int number, int wealth) : power(50,50),num_church(number), pop_wealth(wealth){}
        church () : church(100,100){}
        void change_up(){ // increase variables by random amount
            srand((unsigned) time(NULL));
            this->num_church = num_church + (1+(rand()%20));
            this->pop_wealth = pop_wealth + (1+(rand()%20));
        }
        void change_Down(){ // decrease variables by random amount
            srand((unsigned) time(NULL));
            this->num_church = num_church - (1+(rand()%20));
            this->pop_wealth = pop_wealth - (1+(rand()%20));
        }
        void change_num_church (int new_num){ // change value
            this->num_church = new_num;
        }
        void Rebel ( ){ // special event
            this-> num_church = (num_church-50);
        }
        void change_pop_wealth(int new_wealth){ // change value
            pop_wealth = new_wealth;
        }
        int set_overall_value(){ // changes value and checks for game end
            int value = num_church+pop_wealth;
            *Overall_value = value;
            if (value < 0){
                value = 0;
                game_switch = false;
            }
            if (value > 100){
                value = 100;
                game_switch = true;
            }
            return value;
        }
        int show_overall_value(){ // display total value
            cout<<"the overall value is:"<< *Overall_value <<endl;
            return *Overall_value;
        }
        void show_vars(){ // display each individual value
            cout<<"The number of churches is: "<<num_church<<endl;
            cout<<"The wealth of the pop is: "<<pop_wealth<<endl;
            cout<<"Overall value is: "<<*Overall_value<<endl;
        }
};

class Army: public power { // creates army class
    public:
        int num_troops; // defines army variables
        int weapon_quality;
        int food_avaliblity;
        // initialises army constructors
        Army(int num_troops, int weapon_quality,int food_avaiable):power(25,50), num_troops(num_troops),
        weapon_quality(weapon_quality),food_avaliblity(food_avaiable){}
        Army (): Army(25,25,25){};
        void Rebel(){ // special event
            num_troops = num_troops-50;
        }
        int set_overall_value(){ // changes value and checks for game end
            int value = num_troops + weapon_quality + food_avaliblity;
            *Overall_value = value;
            if (value < 0){
                value = 0;
                game_switch = false;
            }
            if (value > 100){
                value = 100;
                game_switch = true;
            }
            return value;
        }
        void change_up(){ // increase variables by random amount
            srand((unsigned) time(NULL));
            this->num_troops = num_troops + (1+(rand()%15));
            this->weapon_quality = weapon_quality + (1+(rand()%15));
            this->food_avaliblity = food_avaliblity + (1+(rand()%15));
        }
        void change_Down(){ // decrease variables by random amount
            srand((unsigned) time(NULL));
            this->num_troops = num_troops - (1+(rand()%20));
            this->weapon_quality = weapon_quality - (1+(rand()%20));
            this->food_avaliblity = food_avaliblity - (1+(rand()%20));
        }
        void change_num_of_troops(int new_num){ // change value
            num_troops = new_num;
        }

        void change_weapon_quality(int new_quality){ // change value
            weapon_quality = new_quality;
        }
        void change_available_food(int new_food){ // change value
            food_avaliblity = new_food;
        }
        int show_overall_value(){ // display value
            cout<<"the overall value is:"<< *Overall_value <<endl;
                return *Overall_value;
        }
        void show_vars(){ // display variables
            cout<<"The number of troops is:"<<num_troops<<endl;
            cout<<"The quality of weapons is:"<<weapon_quality<<endl;
            cout<<"The available food is:"<<food_avaliblity<<endl;
            cout<<"Overall value is: "<<*Overall_value<<endl;
        } 
};

class wealth : public power{
    public:
        int king_wealth;
        wealth(int wealth): power(50,50), king_wealth(wealth){}; // initialising the values
        wealth(): wealth(50){}; // defult constructor with no input values
        void change_up(){ // increase variables by random amount
            srand((unsigned) time(NULL));
            this->king_wealth = king_wealth + (1+(rand()%20));
        }
        void change_Down(){ // decrease variables by random amount
            srand((unsigned) time(NULL));
            this->king_wealth = king_wealth - (1+(rand()%20));
        }
        void set_weatlh(int new_wealth){ // changes variable
            king_wealth=new_wealth;
        }
        void Rebel(){ // special event
            king_wealth=king_wealth-10;
        }
        int set_overall_value(){ // changes value and checks for game end
            int value = king_wealth;
            *Overall_value = value;
            if (value < 0){
                value = 0;
                game_switch = false;
            }
            if (value > 100){
                value = 100;
                game_switch = true;
            }
            return value;
        }
        void show_vars(){ // display variables
            cout<<"the wealth of the king is: "<<king_wealth<<endl;
            cout<<"Overall value is: "<<*Overall_value<<endl;
        }
};