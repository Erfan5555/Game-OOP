# include <iostream>
# include <string>
# include "power.cpp"
# include "person.cpp"

# include <stdlib.h>
# include <fstream>
using namespace std;

// updates the stats and prints them out in a user friendly way.
void update_stats(people *p, church *c, wealth *w, Army *a){ // function to give out all
// the stats. it updates the stats and printes them out.
    int value;
    value= p->set_overall_value();
    // value= value/10;
    cout<<"people:"<<value;
    // for (int i=0; i<value;i++){
    //     cout<<"-";
    // }
    cout<<endl;

    value= c->set_overall_value();
    // value= value/10;
    cout<<"church:"<<value;
    // for (int i=0; i<value;i++){
    //     cout<<"-";
    // }
    cout<<endl;

    value= w->set_overall_value();
    // value= value/10;
    cout<<"wealth:"<<value;
    // for (int i=0; i<value;i++){
    //     cout<<"-";
    // }
    cout<<endl;

      value= a->set_overall_value();
    // value= value/10;
    cout<<"Army  :"<<value;
    // for (int i=0; i<value;i++){
    //     cout<<"-";
    // }
    cout<<endl;
 }

void save_game(people *p, church *c, wealth *w, Army *a){

    // gets the varaibles that make the overall value for each power.
   
    int value_emp = p->Employment;
    
    int value_food_people= p->Food_avaliable;
    int value_ent= p->Entertainmnet;
    int popularity = p->King_Popularity;

    int value_pope_wealth= c->wealth_of_pop;
    int value_num_church = c->number_of_churches;
  
    int value_of_wealth = w-> wealth_of_king;

    int value_num_troops= a->numb_of_troops;
    int value_equipment= a->quality_of_weapons;
    int value_food_army = a->food_avaliblity;
  

    // writes the values to a file called moarch- this saves the game
    ofstream outputFile;
   outputFile.open("monarch.txt");
   outputFile<< value_emp<<endl;
   outputFile<<value_food_people<<endl;
    outputFile<<value_ent<<endl;
   outputFile<<popularity<<endl;
   outputFile<<value_pope_wealth<<endl;
   outputFile<<value_num_church<<endl;
    outputFile<<value_of_wealth<<endl;
   outputFile<<value_num_troops<<endl;
   outputFile<<value_equipment<<endl;
    outputFile<<value_food_army <<endl;
  
}
 
// loads the game data.
void load_game(people *p, church *c, wealth *w, Army *a){

      // reads the values from a file called moarch- this saves the game
    ifstream inputFile;
    inputFile.open("monarch.txt");
    // NOTE TO SELF Another way to apprach is to use the set_varibles of differnet powers
    int  num1,num2,num3,num4,num5,num6,num7,num8,num9,num10; // num1,2,3,4 are overall values for each of the powers
    inputFile>>num1>>num2>>num3>>num4>>num5>>num6>>num7>>num8>>num9>>num10;
    // p=  new people(num1/3,num1/3,num1/3); 

        cout<<num1<<endl;
        cout<<num2<<endl;
        cout<<num3<<endl;
        cout<<num4<<endl;
        cout<<num5<<endl;
        cout<<num6<<endl;
        cout<<num7<<endl;
        cout<<num8<<endl;
        cout<<num9<<endl;
        cout<<num10<<endl;
  

    // c=new church (num2/2,num2/2);
    //  w=new wealth (num3);
    //  a=new Army (num4/3,num4/3,num4/3) ;
    // we divide the overall values between the variables
    // of the people to get to the same overall value when the game was intially saved. 
    int value;

     p->set_king_popularity(num1);
     p->change_employment(num2);
     p->change_entertainment(num3);
     p->change_food_avaliable(num4);

     c->change_number_of_churches(num5);
     c->change_wealth_of_pop(num6);

     w-> set_weatlh(num7);

     a->change_available_food(num8);
     a->change_num_of_troops(num9);
     a->change_quality_of_weapons(num10);

     update_stats(p,c,w,a);

}
    
 

void check_point_input(int *array, int number_of_check_points){
ofstream outputFile;
   outputFile.open("monarch checkpoint.txt"); // appends to the existing array
//    for (int i=0; i<number_of_check_points+1;i++){
//      outputFile<<array[i];
//    }
    outputFile<<number_of_check_points;
  

}

void check_point_load(int *array ){
    int number_of_integers;
        int number= 0;
        
  ifstream inputFile;

    inputFile.open("monarch checkpoint.txt");    
    int n;
    // while(inputFile >> n){
    //     number_of_integers=number_of_integers+1;
    // }
    // cout<<number_of_integers;
  
    inputFile >> n;

    for (int i=0; i<n;i++){
        array[i]=1;
        cout<<array[i];

    }
}


// terminates the game if any of the valus are zero.
void check_end_game(people *p, church *c, wealth *w, Army *a){
    int value_of_people= p->set_overall_value();
    int value_of_church= c->set_overall_value();
    int value_of_wealth = w-> set_overall_value();
    int value_of_army= a->set_overall_value();
    
   
    if (value_of_army==0 || value_of_people==0 ||  value_of_wealth==0|| value_of_church==0){
        exit(0);
         

    }
}


int main (){

    int *check= new int [70]; // used to track the progression of the game and check point

people* p = new people(25,25,25); // creating a people pointer to an object of the people

church *c= new church(7,27);// creating a church  pointer to an object of the church
wealth *w = new wealth(25); // creating a wealth pointer to an object of the wealth
Army *a = new Army (30,30,10);// creating a Army pointer to an object of the Army

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
char option[2];

  cin>>option ;
int while_stopper=1;

// while loop for menue, implments the user decsion. If user inputs the wrong integer or doesnt
// it informs them
while (while_stopper==1){
   
if (*option=='a' && option[1]==0){
    cout<<"new game created"<<endl;
    for (int i=0;i<70;i++){ // intiliases the array of checkpoints
        check[i]=0;
    }
    while_stopper=0;
}
else if (*option=='b'&& option[1]==0){
    cout<<"game loaded"<<endl;
    load_game(p,c,w,a);
    update_stats(p,c,w,a);
     check_point_load(check);
     while_stopper=0;
}
else if (*option=='c'&& option[1]==0 ){
 cout<<"game exited dont come back to this program ever again !"<<endl;
     while_stopper=0;
    return 0;
}else{
    cout<<"Enter a, b or c !"<<endl;
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
int check_point;// is used to recoginse the placment of the game progression.

char *answer= new char(3);

    advisor mat ("mat","people's speaker",15);
     mat.show_face(":>");


     advisor queen ("Mary","Queen",50);

     advisor general ("james","general", 50);
     advisor banker ("Sir francis", "banker",15 );
     advisor doctor ("Dr Oz", "Doctor",0);

   
   

// sceario 1
check_point=-1;
     check_point= check_point+1; // used to recoginse the game progression 
    while_stopper=1;
        if (check[check_point]!=1){
             banker.speak("should we build more churches?");
             
               cout<<check_point;
         save_game(p,c,w,a);
    cin>>answer;
    }
     
    while (while_stopper==1 && check[check_point]!=1 ) // waits until the correct input has been made
  
        if (*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes 
            c->change_up();
            update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
        check_point_input(check,check_point); 
            
            while_stopper=0;
            
            

        }else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
            c->set_king_popularity(13);
            c->change_Down();
             update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
            check_point_input(check,check_point); 
    
            while_stopper=0;}
        
        else if(*answer=='e'&& answer [1]==0){ // exits teh game
            update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
        check_point_input(check,check_point); 
            while_stopper=0;
            return 0;

        }
        else{
        cout<<"type either  y for yes or n for no \n";
            cin.clear(); // clears the string errors in buffer
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears the numbers in
          // buffer
            cin>>answer;
        }


    save_game(p,c,w,a);

    

 
   
// sceario 2

    while_stopper=1;
   check_point= check_point+1; // used to recoginse the game progression 

    if (check[check_point]!=1){
           queen.speak("It is your birthday ! lets throw a massive party !");
         
    save_game(p,c,w,a);
    cin>>answer;
    }
     
    while (while_stopper==1 && check[check_point]!=1) // waits until the correct input has been made
        if (*answer=='y' && answer[1]==0 ){ // if answer is yes it will cause ceratin changes 
            p->change_up();
            w->change_Down();
            update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
                check_point_input(check,check_point); 
            while_stopper=0;

    

        }  else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
            c->set_king_popularity(17);
            w->change_up();
            p->change_Down();
            c->change_up();
             update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
            check_point_input(check,check_point); 
    
            while_stopper=0;

        }   else if(*answer=='e'&& answer [1]==0){ // exits teh game
            update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
       check_point_input(check,check_point); 
            while_stopper=0;
            return 0;

        }
        else{
             cout<<"type either  y for yes or n for no\n";
            cin.clear(); // clears the string errors in buffer
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears the numbers in
          // buffer
            cin>>answer;
        }

        check_point_input(check,check_point);
    



         check_point= check_point+1; // used to recoginse the game progression 
// sceario 3

    while_stopper=1;

         if (check[check_point]!=1){ // checks if the user was at this point when they left the game
            doctor.speak("SIR ! there is a widespread of a suspcious disease, we should investiagte");
            
            save_game(p,c,w,a);
    cin>>answer;
    }
 

    while (while_stopper==1 && check[check_point]!=1) // waits until the correct input has been made
        if (*answer=='y' && answer[1]==0 ){ // if answer is yes it will cause ceratin changes 
            p->change_up(); 
            w->change_Down();
            update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
            check_point_input(check,check_point); 
            while_stopper=0;
           
           
            
            

        }else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
            p->change_Down();
            
            p->set_king_popularity(25);
            
        check_point_input(check,check_point); 
             update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
            while_stopper=0;
             
         }

       else if(*answer=='e'&& answer [1]==0){ // exits teh game
            update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
            check_point_input(check,check_point); 
            while_stopper=0;
            return 0;

        }
        else{
            cout<<"type either  y for yes or n for no\n";
            cin.clear(); // clears the string errors in buffer
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears the numbers in
          // buffer
            cin>>answer;
        }

            save_game(p,c,w,a);

    check_point_input(check,check_point);
    


   
// sceario 4

    while_stopper=1;
   check_point= check_point+1; // used to recoginse the game progression 

   if (check[check_point]!=1){ // checks if the user was at this point when they left the game
               general.speak("SIR ! there is a widespread of a suspcious disease, we should investiagte");
      
            save_game(p,c,w,a);
    cin>>answer;
    }

    while (while_stopper==1 && check[check_point]!=1) // waits until the correct input has been made
        if (*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes 
            p->change_up(); 
            w->change_Down();
            update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
                check_point_input(check,check_point); 
            while_stopper=0;
           
            
            

        }else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
            p->change_Down();
            a->change_Down();
            p->set_king_popularity(2);
            
    check_point_input(check,check_point); 
             update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
            while_stopper=0;
      
        }

     else if(*answer=='e'&& answer [1]==0){ // exits teh game
            update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
        check_point_input(check,check_point); 
            while_stopper=0;
            return 0;

        }
        else{
            cout<<"type either  y for yes or n for no\n";
            cin.clear(); // clears the string errors in buffer
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears the numbers in
          // buffer
            cin>>answer;
        }
    save_game(p,c,w,a);
    check_point_input(check,check_point);
    
// sceario 5
check_point=-1;
     check_point= check_point+1; // used to recoginse the game progression 
    while_stopper=1;
        if (check[check_point]!=1){
             banker.speak("Should we sell the Holy Sword?");
             
               cout<<check_point;
         save_game(p,c,w,a);
    cin>>answer;
    }
     
    while (while_stopper==1 && check[check_point]!=1 ) // waits until the correct input has been made
  
        if (*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes 
            c->change_Down();
            c->set_king_popularity(10);
            w->change_up();
            a->change_up();
            p->change_up();
            update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
        check_point_input(check,check_point); 
            
            while_stopper=0;
            
            

        }else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
            c->set_king_popularity(15);
            c->change_up();
            p->change_Down();
             update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
            check_point_input(check,check_point); 
    
            while_stopper=0;}
        
        else if(*answer=='e'&& answer [1]==0){ // exits teh game
            update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
        check_point_input(check,check_point); 
            while_stopper=0;
            return 0;

        }
        else{
        cout<<"type either  y for yes or n for no \n";
            cin.clear(); // clears the string errors in buffer
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears the numbers in
          // buffer
            cin>>answer;
        }


    save_game(p,c,w,a);
    
    // sceario 6
check_point=-1;
     check_point= check_point+1; // used to recoginse the game progression 
    while_stopper=1;
        if (check[check_point]!=1){
             mat.speak("Rumors say that a demon is learking can the Army investigate?");
             
               cout<<check_point;
         save_game(p,c,w,a);
    cin>>answer;
    }
     
    while (while_stopper==1 && check[check_point]!=1 ) // waits until the correct input has been made
  
        if (*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes 
            p->set_king_popularity(50);
            a->change_up();
            w->change_Down();
            update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
        check_point_input(check,check_point); 
            
            while_stopper=0;
            
            

        }else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
            p->set_king_popularity(10);
            p->change_Down();
            w->change_up();
            c->set_king_popularity(10);
            c->change_up();
             update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
            check_point_input(check,check_point); 
    
            while_stopper=0;}
        
        else if(*answer=='e'&& answer [1]==0){ // exits teh game
            update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
        check_point_input(check,check_point); 
            while_stopper=0;
            return 0;

        }
        else{
        cout<<"type either  y for yes or n for no \n";
            cin.clear(); // clears the string errors in buffer
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears the numbers in
          // buffer
            cin>>answer;
        }


    save_game(p,c,w,a);

// sceario 7
check_point=-1;
     check_point= check_point+1; // used to recoginse the game progression 
    while_stopper=1;
        if (check[check_point]!=1){
             queen.speak("A man looked at me weird off with his head?");
             
               cout<<check_point;
         save_game(p,c,w,a);
    cin>>answer;
    }
     
    while (while_stopper==1 && check[check_point]!=1 ) // waits until the correct input has been made
  
        if (*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes 
          p->Rebel();
          a->set_king_popularity(5);
          a->change_up();
          c->set_king_popularity(10);

            update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
        check_point_input(check,check_point); 
            
            while_stopper=0;
            
            

        }else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
        p->set_king_popularity(20);
        p->change_up();
        w->set_king_popularity(30);
             update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
            check_point_input(check,check_point); 
    
            while_stopper=0;}
        
        else if(*answer=='e'&& answer [1]==0){ // exits teh game
            update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
        check_point_input(check,check_point); 
            while_stopper=0;
            return 0;

        }
        else{
        cout<<"type either  y for yes or n for no \n";
            cin.clear(); // clears the string errors in buffer
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears the numbers in
          // buffer
            cin>>answer;
        }


    save_game(p,c,w,a);

    // sceario 8
check_point=-1;
     check_point= check_point+1; // used to recoginse the game progression 
    while_stopper=1;
        if (check[check_point]!=1){
             general.speak("Your Majesty the Myra Kingdom has declared war are we taking up arms?");
             
               cout<<check_point;
         save_game(p,c,w,a);
    cin>>answer;
    }
     
    while (while_stopper==1 && check[check_point]!=1 ) // waits until the correct input has been made
  
        if (*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes 
          w->change_Down();
          a->change_Down();
          c->change_wealth_of_pop(20);
            update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
        check_point_input(check,check_point); 
            
            while_stopper=0;
            
            

        }else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
           a->kill_king();
           p->kill_king();
             update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
            check_point_input(check,check_point); 
    
            while_stopper=0;}
        
        else if(*answer=='e'&& answer [1]==0){ // exits teh game
            update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
        check_point_input(check,check_point); 
            while_stopper=0;
            return 0;

        }
        else{
        cout<<"type either  y for yes or n for no \n";
            cin.clear(); // clears the string errors in buffer
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears the numbers in
          // buffer
            cin>>answer;
        }


    save_game(p,c,w,a);

    // sceario 9
check_point=-1;
     check_point= check_point+1; // used to recoginse the game progression 
    while_stopper=1;
        if (check[check_point]!=1){
             doctor.speak("Sorry your Majesty your great grandmother died should we hold the funeral now?");
             
               cout<<check_point;
         save_game(p,c,w,a);
    cin>>answer;
    }
     
    while (while_stopper==1 && check[check_point]!=1 ) // waits until the correct input has been made
  
        if (*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes
        if (w->wealth_of_king<20)
        {
            w->kill_king();
        }
         
           w->set_weatlh(5);
           p->change_Down();
           p->set_king_popularity(20);
           a->change_Down();
           c->change_up();
           
            update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
        check_point_input(check,check_point); 
            
            while_stopper=0;
            
            

        }else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
           w->change_up();
           a->change_up();
           c->set_king_popularity(10);

             update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
            check_point_input(check,check_point); 
    
            while_stopper=0;}
        
        else if(*answer=='e'&& answer [1]==0){ // exits teh game
            update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
        check_point_input(check,check_point); 
            while_stopper=0;
            return 0;

        }
        else{
        cout<<"type either  y for yes or n for no \n";
            cin.clear(); // clears the string errors in buffer
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears the numbers in
          // buffer
            cin>>answer;
        }


    save_game(p,c,w,a);

    // sceario 10
check_point=-1;
     check_point= check_point+1; // used to recoginse the game progression 
    while_stopper=1;
        if (check[check_point]!=1){
             general.speak("Where running out of provisions! Please provide funding?");
             
               cout<<check_point;
         save_game(p,c,w,a);
    cin>>answer;
    }
     
    while (while_stopper==1 && check[check_point]!=1 ) // waits until the correct input has been made
  
        if (*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes 
          a->change_up();
          a->change_up();
          
          w->change_Down();
          w->set_king_popularity(5);
            update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
        check_point_input(check,check_point); 
            
            while_stopper=0;
            
            

        }else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
       a->Rebel();
       w->change_up();
             update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
            check_point_input(check,check_point); 
    
            while_stopper=0;}
        
        else if(*answer=='e'&& answer [1]==0){ // exits teh game
            update_stats(p,c,w,a);
            check_end_game(p,c,w,a);
        check_point_input(check,check_point); 
            while_stopper=0;
            return 0;

        }
        else{
        cout<<"type either  y for yes or n for no \n";
            cin.clear(); // clears the string errors in buffer
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears the numbers in
          // buffer
            cin>>answer;
        }


    save_game(p,c,w,a);
}