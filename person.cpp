# include <iostream>
# include <string>


using namespace std;

// abstract class of person, person will not have any objects in the game.
// show_face() and speak() are virtual functions. i.e implemented in the dervied classes.
 class person{
protected:
 string name;
string job;
bool live_or_dead; // true means its living 
//visulasiation here please

public:

person(string name,string job): name(name), job( job){live_or_dead=true;} // constructor, intilisaiton 
person(): person(" ", " "){live_or_dead=true;} // constructor


virtual void show_face(string face)= 0; // abstract class, these are implemented in each dervied class
virtual void speak(string text)=0;

};



class advisor : virtual public person{
   
public:
int power;

advisor(string name, string job, int power): person(name,job),power(power){live_or_dead=true;}

advisor(): advisor(" ", " ", 0){live_or_dead=true;};

void dead_advisor (){
    live_or_dead= false; 
}


void speak(string text){
    cout<<name<<" : "<<text<<endl;
}

void show_face(string face){ // visulisastation here
    cout<<face <<endl;
}
};

class king :  public advisor{
    private: // dont know why the power is not inheretd from advisor
        int number_of_years_in_power;
//     protected :
//  int power;

public:

king(string name_input, string job_input, int power_input, int years){
    name =name_input;
    job= job_input;
    power=power_input;
    number_of_years_in_power=years;
    live_or_dead=true;
}

// person(name,job),
// number_of_years_in_power(years), advisor(power){live_or_dead=true;}

king (): king(" "," ",100, 0){}


void set_years_in_power(int years){

    number_of_years_in_power=years;
}



void speak(string text){
    cout<<text<<endl;
}


void dead_king (){
    live_or_dead=false;
}

void kill_advisor(){
    advisor::dead_advisor();
}
};


class spirit: public king, virtual public person{
    
  protected :
    int power;


public:

spirit(string name, string job, int power, int years): person(name,job),
power(power){live_or_dead=true;}
spirit (): spirit(" "," ",100, 0){}

void kill_king (){
    king::dead_king();
}

void cast_spell(int value){
    // people::change_food_avaliable(-40);
    
}

void speak(string text){
    cout<<text<<endl;
}
void show_face(){ // visulisastation here
    cout<<"imagine you are seeing a face right now"<<endl;
}
};