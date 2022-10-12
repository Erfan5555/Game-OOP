# include <iostream>
# include <string>
# include "power.cpp"
# include "person.cpp"
using namespace std;


int main (){

    cout<<"-----------------------------------"<<endl;
                   
    cout <<"  ________________ \n"
            "___  ____/__    |\n"
            "__  __/  __  /| |\n"
            "_  /___  _  ___ |\n"
            "/_____/  /_/  |_| "<<endl;
                            

// menu
cout<<"menue"<<endl;
cout<<"a: play new game"<<endl;
cout<< "b: load game"<<endl;
cout<<"c: exit"<<endl;
cout<<"To select the options type a,b or c "<<endl;
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
     cin>>option;
    
}
}


    people A(25,25,25);
    A.set_overall_value();

    church B(7,20);
    wealth w (25);
    Army n (30,30,10);

    B.set_overall_value();
   cout<<"the overal value of church:  "<< B.show_overall_value()<<endl;
   A.show_overall_var();
   w.set_overall_value();
   w.show_overall_var();
   n.set_overall_value();
   n.show_overall_value();

    advisor mat ("mat","people's speaker",15);
     mat.show_face(":>");
    mat.speak("Hi i am the first person to be alive in this MAD UNIVERSE!");
     advisor queen ("Mary","Queen",50);
     



   
}
