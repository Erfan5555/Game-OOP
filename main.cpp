# include <iostream>
# include <string>
# include "power.cpp"
# include "person.cpp"
# include <stdlib.h>
using namespace std;

void update_stats(power *p, church *c, wealth *w, Army *a){ // function to give out all
// the stats. it updates the stats and printes them out.
    cout<<"People:"<<p->set_overall_value()<<endl;
    cout<<"church:"<<c->set_overall_value()<<endl;
    cout<<"wealth:"<<w->set_overall_value()<<endl;
    cout<<"Army:"<<a->set_overall_value()<<endl;
}

// terminates the game if any of the valus are zero.
void check_end_game(power *p, church *c, wealth *w, Army *a){
    int value_of_people= p->set_overall_value();
    int value_of_church= c->set_overall_value();
    int value_of_wealth = w-> set_overall_value();
    int value_of_army= a->set_overall_value();
    
   
    if (value_of_army==0 || value_of_people==0 ||  value_of_wealth==0|| value_of_church==0){
        exit(0);
         

    }
}


int main (){

    cout<<"-----------------------------------"<<endl;
                   
    cout <<"  ________________ \n"
            "___  ____/__    |\n"
            "__  __/  __  /| |\n"
            "_  /___  _  ___ |\n"
            "/_____/  /_/  |_| "<<endl;
                            

// menu
cout<<"menue"<<endl;
cout<<"1: play new game"<<endl;
cout<< "2: load game"<<endl;
cout<<"3: exit"<<endl;
cout<<"To select the options type 1,2 or 3 "<<endl;
int option;

  cin>>option ;
int while_stopper=1;

// while loop for menue, implments the user decsion. If user inputs the wrong integer or doesnt
// it informs them
while (while_stopper==1){
   
if (option==1){
    cout<<"new game created"<<endl;
    while_stopper=0;
}
else if (option==2){
    cout<<"UNDER CONSTRUCTION "<<endl;
     while_stopper=0;
}
else if (option==3 ){
 cout<<"game exited dont come back to this program ever again !"<<endl;
     while_stopper=0;
    return 0;
}else{
    cout<<"ENTER AN INTEGER THAT IS WITHIN THE RANGE ENTER AGAIN!"<<endl;
    cin.clear();
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
     cin>>option;
    
}
}
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;

cout<<"welcome  to the game"<<endl;

char *answer= new char(3);

people* p = new people(25,25,25);

church *c= new church(7,27);
wealth *w = new wealth(25);
Army *a = new Army (30,30,10);

   
    

    

    advisor mat ("mat","people's speaker",15);
     mat.show_face(":>");


     advisor queen ("Mary","Queen",50);

     advisor general ("james","general", 50);
     advisor banker ("Sir francis", "banker",15 );
     advisor doctor ("Dr Oz", "Doctor",0);

     banker.speak("should we build more churches?");

    cin>>answer;
// sceario 1
    while_stopper=1;
    while (while_stopper==1) // waits until the correct input has been made
        if (*answer=='y' ){ // if answer is yes it will cause ceratin changes 
            c->change_number_of_churches(9);
            c->change_wealth_of_pop(25);
            update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
            
            while_stopper=0;
            
            

        }else if (*answer=='n'){ //if answer is no, it will cause ceratin changes 
            c->set_king_popularity(13);
             update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
            while_stopper=0;
        }else{
            cout<<"TYPE EITHER Y FOR YES OR N FOR NO";
            cin.clear(); // clears the string errors in buffer
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears the numbers in
          // buffer
            cin>>answer;
        }




     queen.speak("It is your birthday ! lets throw a massive party !");

    cin>>answer;
// sceario 1
    while_stopper=1;
    while (while_stopper==1) // waits until the correct input has been made
        if (*answer=='y' ){ // if answer is yes it will cause ceratin changes 
            p->change_entertainment(39);
            w->set_weatlh(11);
            update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
            
            while_stopper=0;
            
            

        }else if (*answer=='n'){ //if answer is no, it will cause ceratin changes 
            c->set_king_popularity(23);
             update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
            while_stopper=0;
        }else{
            cout<<"TYPE EITHER Y FOR YES OR N FOR NO";
            cin.clear(); // clears the string errors in buffer
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears the numbers in
          // buffer
            cin>>answer;
        }

    
       doctor.speak("SIR ! there is a widespread of a suspcious disease, we should investiagte");

    cin>>answer;
// sceario 1
    while_stopper=1;
    while (while_stopper==1) // waits until the correct input has been made
        if (*answer=='y' ){ // if answer is yes it will cause ceratin changes 
            p->change_employment(45);
            w->set_weatlh(3);
            update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
            
            while_stopper=0;
            
            

        }else if (*answer=='n'){ //if answer is no, it will cause ceratin changes 
            p->change_employment(22);
            p->change_food_avaliable(1);

             update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
            while_stopper=0;
        }else{
            cout<<"TYPE EITHER Y FOR YES OR N FOR NO";
            cin.clear(); // clears the string errors in buffer
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears the numbers in
          // buffer
            cin>>answer;
        }

    

}
     
