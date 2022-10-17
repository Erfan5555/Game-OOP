# include <iostream>
# include <string>

using namespace std;

// abstract class since the method rebel and kill king is not implemented.
// No object of this class is intendeded to be instantiated.

class show_all_variables { // intended for programmers only 
// avaiable in all of the classes
    public:
    virtual void show_vars()=0;
    
};


class power:public show_all_variables{

public:
int King_Popularity;
int *Overall_value=new int(2);
bool game_switch; // This ends the king's life

power (int popularity, int satsifactionValue)
{
    game_switch=true;
    King_Popularity=popularity;
    *Overall_value=satsifactionValue;
    
    } // intlisaed the constructor of 
//power

power(): power(100,100){game_switch=true;} // intliases the constructor if no values are inputed

virtual void Rebel ()=0;

virtual int set_overall_value()=0; //Overall value is the number seen 
//on the bottom of each sign of a power. it is calculated from different variables
// in each power. 
// set_overall_value will be put in after each time a card has been drawen and the user
// makes a decsion

void show_overall_var(){
  
    cout<<"overall value is: "<<*Overall_value<<endl;
}

void set_king_popularity(int new_value){
    King_Popularity=new_value;
}

void kill_king(){ // INSERT THE GAME END FUNCTION
    game_switch=false;
    cout<<"game ended"<<endl;
}




};


class people :public power{



public :
int Employment;
int Entertainmnet;
int Food_avaliable;

people(int Employment_new_Value, int Entertainmnet_new_Value, 
int Food_avaliable_new_Value): power(50,50), Employment(Employment_new_Value),Entertainmnet(Entertainmnet_new_Value)
,Food_avaliable(Food_avaliable_new_Value){} // intilisasing the constructor

people(): people(25,25,25){}

void Rebel ( ){ // polymorphism here
    Employment=Employment-70;
    King_Popularity= King_Popularity-70;

}

int set_overall_value(){ // 
   int value= Employment+ Entertainmnet+Food_avaliable+King_Popularity;
    *Overall_value= value;
    if (value<0){
        value=0;
        game_switch=false; // ends the king's life and start a new game.
    }
    if (value>100){
        value =100;
        game_switch=false; // ends the king's life and start a new game.
    }
    
    return value;
}

void change_employment (int Employment ){
this->Employment = Employment;
}

void change_entertainment (int Entertainment ){
   this-> Entertainmnet= Entertainment;
}

void change_food_avaliable (int Food_avaliable){
    this-> Food_avaliable = Food_avaliable;
}





void show_vars(){
    cout<<"employment is:"<<Employment<<endl;
    cout<<"avaiable food is:"<<Food_avaliable<<endl;
    cout<<"Entertainment value is:"<<Entertainmnet<<endl;
    cout<<"overall value is: "<<Overall_value<<endl;
}


};

class church : public power {

public :
int number_of_churches;
int wealth_of_pop;
// intlisases the church constructors 
church (int number, int wealth): power(50,50),number_of_churches(number), wealth_of_pop(wealth){}

church (): church(100,100){}

void change_number_of_churches (int new_number){
this->number_of_churches= new_number;
}

void Rebel ( ){ // polymorphism here
    
    this-> number_of_churches = (number_of_churches-50);
    
}

void change_wealth_of_pop(int new_wealth){
    wealth_of_pop=new_wealth;

}

    int set_overall_value(){ // 

    int value= number_of_churches+wealth_of_pop;
    *Overall_value= value;

    if (value<0){
        value=0;
        game_switch=false;
    }
    if (value>100){
        value =100;
        game_switch=true;
    }
    return value;
}
 int show_overall_value(){
        cout<<"the overall value is:"<< *Overall_value <<endl;
        return *Overall_value;
    }

    void show_vars(){
    cout<<"church number value is:"<<number_of_churches<<endl;
    cout<<"wealth of the pop is:"<<wealth_of_pop<<endl;
   
    cout<<"overall value is: "<<*Overall_value<<endl;
}

  

};



class Army: public power {
    
    public:

    int numb_of_troops;
    int quality_of_weapons;
    int food_avaliblity;

    Army(int numb_of_troops, int quality_of_weapons,int food_avaiable):power(25,50), numb_of_troops(numb_of_troops),
    quality_of_weapons(quality_of_weapons),food_avaliblity(food_avaiable){}

    Army (): Army(25,25,25){};

    void Rebel(){
        numb_of_troops=numb_of_troops-50;
    }

   int set_overall_value(){
        int value=numb_of_troops+quality_of_weapons+food_avaliblity;
       *Overall_value= value;

        if (value<0){
        value=0;
        game_switch=false;
    }
    if (value>100){
        value =100;
        game_switch=true;
    }
    return value;
    }

    void change_num_of_troops(int new_number){
        numb_of_troops=new_number;
    }

    void change_quality_of_weapons(int new_quality){
        quality_of_weapons=new_quality;
    }

    void change_available_food(int new_value){
        food_avaliblity=new_value;
    }

    int show_overall_value(){
        cout<<"the overall value is:"<< *Overall_value <<endl;
               return *Overall_value;
    }
    void show_vars(){
    cout<<"number of troops is:"<<numb_of_troops<<endl;
    cout<<" Quality of weapons is:"<<quality_of_weapons<<endl;
     cout<<" Avaiable food is:"<<food_avaliblity<<endl;
    
    cout<<"overall value is: "<<*Overall_value<<endl;
} 
};

class wealth:public power{

   
    public:
     int wealth_of_king;

    wealth(int wealth): power(50,50), wealth_of_king(wealth){}; // intilisaing the values
    wealth(): wealth(50){}; // defult constructor with no input values
    
    void set_weatlh(int new_wealth){
        wealth_of_king=new_wealth;
    }

     void Rebel(){
        wealth_of_king=wealth_of_king-10;
    }
    int set_overall_value(){
        
          int value=wealth_of_king;
       *Overall_value= value;

        if (value<0){
        value=0;
        game_switch=false;
    }
    if (value>100){
        value =100;
        game_switch=true;
    }
    return value;

    }

  void show_vars(){
    cout<<"wealth of the king is:"<<wealth_of_king<<endl;
    
    
    cout<<"overall value is: "<<*Overall_value<<endl;
}
    
};
