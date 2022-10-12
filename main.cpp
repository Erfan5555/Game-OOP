# include <iostream>
# include <string>
# include "power.cpp"
# include "person.cpp"
using namespace std;


int main (){

    cout<<"-----------------------------------"<<endl;
                   
    cout <<"  ________________ 
___  ____/__    |
__  __/  __  /| |
_  /___  _  ___ |
/_____/  /_/  |_| "<<endl;
                
 

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
   

   
}
