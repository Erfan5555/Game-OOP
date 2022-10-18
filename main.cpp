#include <iostream>
#include <string>
#include "power.cpp"
#include "person.cpp"
#include <stdlib.h>
#include <fstream>
#include <limits>
using namespace std;


int main (){
    int *check= new int [70]; // used to track the progression of the game and check point
    people* p = new people(25,25,25); // creating a people pointer to an object of the people
    church *c= new church(7,27);// creating a church  pointer to an object of the church
    wealth *w = new wealth(25); // creating a wealth pointer to an object of the wealth
    Army *a = new Army (30,30,10);// creating a Army pointer to an object of the Army
    stats file; // imports file and stats functions
    cout<<"-----------------------------------"<<endl;
    cout <<"  ________________ \n"
            "___  ____/__    |\n"
            "__  __/  __  /| |\n"
            "_  /___  _  ___ |\n"
            "/_____/  /_/  |_| "<<endl;
// menu
    cout<<"menu"<<endl;
    cout<<"a: play new game"<<endl;
    cout<< "b: load game"<<endl;
    cout<<"c: exit"<<endl;
    cout<<"To select the options type a,b or c "<<endl;
    char option[2];
    cin>>option ;
    int while_stopper=1;
// while loop for menu, implements the user decision. If user inputs the wrong integer or doesnt
// it informs them
    while (while_stopper==1){ 
        if (*option=='a' && option[1]==0){ // new game
            cout<<"New game created"<<endl;
            for (int i=0;i<70;i++){ // intiliases the array of checkpoints
                check[i]=0;
            }
            while_stopper=0;
        }
        else if (*option=='b'&& option[1]==0){ // load game
            cout<<"Game loaded"<<endl;
            file.load_game(p,c,w,a);
            file.update_stats(p,c,w,a);
            file.check_point_load(check);
            while_stopper=0;
        }
        else if (*option=='c'&& option[1]==0 ){ // exit game
        cout<<"Game exited dont come back to this program ever again !"<<endl;
            while_stopper=0;
            return 0;
        }
        else{ // incorrect input
            cout<<"Enter a, b or c !"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin>>option;
        }
    }
    for(int i=0;i<11;i++){
        cout<<endl;
    }
    cout<<"Welcome  to Monarch"<<endl;
    cout<<"type 'y' or 'n' for yes or no"<<endl;
    int check_point;// is used to recoginse the placment of the game progression.
    char *answer= new char(3);
    advisor mat ("mat","people's speaker",15);
    mat.show_face(":>");
    advisor queen ("Mary","Queen",50);
    advisor general ("James","General", 50);
    advisor banker ("Sir Francis", "Banker",15 );
    advisor doctor ("Dr Oz", "Doctor",0);
    advisor pope ("Pope Benedict", "Pope", 50);
// scenario 1
    check_point=-1;
    check_point = check_point+1; // used to recoginse the game progression 
    while_stopper=1;
    if (check[check_point]!=1){
        banker.speak("Should we build more churches?");       
        file.save_game(p,c,w,a);
        cin>>answer;
    } 
    while (while_stopper==1 && check[check_point]!=1 ) // waits until the correct input has been made
    if(*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes 
        c->change_up();
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if(*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
        c->set_king_popularity(13);
        c->change_Down();
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if(*answer=='e'&& answer [1]==0){ // exits the game
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
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
    file.save_game(p,c,w,a);
// scenario 2
    while_stopper=1;
    check_point= check_point+1; // used to recoginse the game progression 
    if (check[check_point]!=1){
        queen.speak("It is your birthday ! lets throw a massive party !");
        file.save_game(p,c,w,a);
        cin>>answer;
    }
    while (while_stopper==1 && check[check_point]!=1) // waits until the correct input has been made
    if (*answer=='y' && answer[1]==0 ){ // if answer is yes it will cause ceratin changes 
        p->change_up();
        w->change_Down();
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }  
    else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
        c->set_king_popularity(17);
        w->change_up();
        p->change_Down();
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }   
    else if(*answer=='e'&& answer [1]==0){ // exits teh game
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
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
    file.check_point_input(check,check_point);
    check_point= check_point+1; // used to recoginse the game progression 
// scenario 3
    while_stopper=1;
    if (check[check_point]!=1){ // checks if the user was at this point when they left the game
        doctor.speak("Your Majesty ! there is a widespread of a suspcious disease, we should investiagte");   
        file.save_game(p,c,w,a);
        cin>>answer;
    }
    while (while_stopper==1 && check[check_point]!=1) // waits until the correct input has been made
    if (*answer=='y' && answer[1]==0 ){ // if answer is yes it will cause ceratin changes 
        p->change_up(); 
        w->change_Down();
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
        p->change_Down();
        p->set_king_popularity(25);
        file.check_point_input(check,check_point); 
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        while_stopper=0;
    }
    else if(*answer=='e'&& answer [1]==0){ // exits teh game
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
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
    file.save_game(p,c,w,a);
    file.check_point_input(check,check_point);
// scenario 4
    while_stopper=1;
    check_point= check_point+1; // used to recoginse the game progression 
    if (check[check_point]!=1){ // checks if the user was at this point when they left the game
        general.speak("Your Majesty ! the suspcious disease is still present, we should investiagte");
        file.save_game(p,c,w,a);
        cin>>answer;
    }
    while (while_stopper==1 && check[check_point]!=1) // waits until the correct input has been made
    if (*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes 
        p->change_up(); 
        w->change_Down();
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
        p->change_Down();
        a->change_Down();
        p->set_king_popularity(2); 
        file.check_point_input(check,check_point); 
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        while_stopper=0;
    }
    else if(*answer=='e'&& answer [1]==0){ // exits teh game
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
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
    file.save_game(p,c,w,a);
    file.check_point_input(check,check_point);
// scenario 5
    check_point=-1;
    check_point= check_point+1; // used to recoginse the game progression 
    while_stopper=1;
    if (check[check_point]!=1){
        banker.speak("Should we sell the Holy Sword?");  
        cout<<check_point;
        file.save_game(p,c,w,a);
        cin>>answer;
    }
    while (while_stopper==1 && check[check_point]!=1 ) // waits until the correct input has been made
    if (*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes 
        c->change_Down();
        c->set_king_popularity(10);
        w->change_up();
        a->change_up();
        p->change_up();
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
        c->set_king_popularity(15);
        c->change_up();
        p->change_Down();
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if(*answer=='e'&& answer [1]==0){ // exits teh game
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
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
    file.save_game(p,c,w,a);
// scenario 6
    check_point=-1;
    check_point= check_point+1; // used to recoginse the game progression 
    while_stopper=1;
    if (check[check_point]!=1){
        mat.speak("Rumors say that a demon is learking can the Army investigate?");
        file.save_game(p,c,w,a);
        cin>>answer;
    }
    while (while_stopper==1 && check[check_point]!=1 ) // waits until the correct input has been made
    if (*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes 
        p->set_king_popularity(50);
        a->change_up();
        w->change_Down();
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
        p->set_king_popularity(10);
        p->change_Down();
        w->change_up();
        c->set_king_popularity(10);
        c->change_up();
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if(*answer=='e'&& answer [1]==0){ // exits teh game
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
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
    file.save_game(p,c,w,a);
// scenario 7
    check_point=-1;
    check_point= check_point+1; // used to recoginse the game progression 
    while_stopper=1;
    if (check[check_point]!=1){
        queen.speak("A man looked at me weird off with his head?");
        file.save_game(p,c,w,a);
        cin>>answer;
    }
    while (while_stopper==1 && check[check_point]!=1 ) // waits until the correct input has been made
    if (*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes 
        p->Rebel();
        a->set_king_popularity(5);
        a->change_Down();
        c->set_king_popularity(10);
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
        p->set_king_popularity(20);
        p->change_up();
        w->set_king_popularity(30);
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if(*answer=='e'&& answer [1]==0){ // exits teh game
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
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
    file.save_game(p,c,w,a);
// scenario 8
    check_point=-1;
    check_point= check_point+1; // used to recoginse the game progression 
    while_stopper=1;
    if (check[check_point]!=1){
        general.speak("Your Majesty the Myra Kingdom has declared war are we taking up arms?");
        file.save_game(p,c,w,a);
        cin>>answer;
    }
    while (while_stopper==1 && check[check_point]!=1 ) // waits until the correct input has been made
    if (*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes 
        w->change_Down();
        a->change_Down();
        c->change_pop_wealth(20);
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
        a->change_num_of_troops(0);
        a->change_available_food(0);
        a->change_weapon_quality(0);
        p->change_employment(0);
        p->change_food(0);
        p->change_entertainment(0);
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;}
    else if(*answer=='e'&& answer [1]==0){ // exits teh game
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
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
    file.save_game(p,c,w,a);
// scenario 9
    check_point=-1;
    check_point= check_point+1; // used to recoginse the game progression 
    while_stopper=1;
    if (check[check_point]!=1){
        doctor.speak("Sorry your Majesty your great grandmother died should we hold the funeral now?");
        file.save_game(p,c,w,a);
        cin>>answer;
    }
    while (while_stopper==1 && check[check_point]!=1 ) // waits until the correct input has been made
    if (*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes
        w->set_weatlh(5);
        p->change_Down();
        p->set_king_popularity(20);
        a->change_Down();
        c->change_up();
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
        w->change_up();
        a->change_up();
        c->set_king_popularity(10);
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if(*answer=='e'&& answer [1]==0){ // exits teh game
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
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
    file.save_game(p,c,w,a);
// scenario 10
    check_point=-1;
    check_point= check_point+1; // used to recoginse the game progression 
    while_stopper=1;
    if (check[check_point]!=1){
        general.speak("Where running out of provisions! Please provide funding?");  
        file.save_game(p,c,w,a);
        cin>>answer;
    }
    while (while_stopper==1 && check[check_point]!=1 ) // waits until the correct input has been made
    if (*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes 
        a->change_up();
        a->change_up();
        w->change_Down();
        w->set_king_popularity(5);
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
        a->Rebel();
        w->change_up();
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if(*answer=='e'&& answer [1]==0){ // exits teh game
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
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
    file.save_game(p,c,w,a);
// scenario 11
    check_point=-1;
    check_point= check_point+1; // used to recoginse the game progression 
    while_stopper=1;
    if (check[check_point]!=1){
        mat.speak("We won the war shall we hold a parade?");     
        file.save_game(p,c,w,a);
        cin>>answer;
    }
    while (while_stopper==1 && check[check_point]!=1 ) // waits until the correct input has been made
    if (*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes 
        w->change_Down();
        p->change_up();
        a->set_king_popularity(15);
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
        a->change_Down();
        p->change_Down();
        w->change_up();
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if(*answer=='e'&& answer [1]==0){ // exits teh game
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
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
    file.save_game(p,c,w,a);
// scenario 12
    check_point=-1;
    check_point= check_point+1; // used to recoginse the game progression 
    while_stopper=1;
    if (check[check_point]!=1){
        pope.speak("There are a lot of sick patients can we get an investment for treatment?");
        file.save_game(p,c,w,a);
        cin>>answer;
    }
    while (while_stopper==1 && check[check_point]!=1 ) // waits until the correct input has been made
    if (*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes 
        c->change_up();
        c->set_king_popularity(15);
        p->change_up();
        w->change_Down();
        w->set_king_popularity(5);
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
        c->change_Down();
        p->change_Down();
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if(*answer=='e'&& answer [1]==0){ // exits teh game
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
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
    file.save_game(p,c,w,a);
// scenario 13
    check_point=-1;
    check_point= check_point+1; // used to recoginse the game progression 
    while_stopper=1;
    if (check[check_point]!=1){
        mat.speak("Your Majesty the farms are being raided and people are starving can we send the army?");
        file.save_game(p,c,w,a);
        cin>>answer;
    }
    while (while_stopper==1 && check[check_point]!=1 ) // waits until the correct input has been made
    if (*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes 
        p->change_up();
        w->change_Down();
        a->change_Down();
        w->set_king_popularity(5);
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
        p->Rebel();
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if(*answer=='e'&& answer [1]==0){ // exits teh game
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
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
    file.save_game(p,c,w,a);
// scenario 14
    check_point=-1;
    check_point= check_point+1; // used to recoginse the game progression 
    while_stopper=1;
    if (check[check_point]!=1){
        general.speak("Your Majesty, for their excellent service can the soldiers get a salary raise?");
        file.save_game(p,c,w,a);
        cin>>answer;
    }
    while (while_stopper==1 && check[check_point]!=1 ) // waits until the correct input has been made
    if (*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes 
        w->change_Down();
        a->change_up();
        w->set_king_popularity(5);
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes
        a->change_Down();
        p->change_Down();  
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if(*answer=='e'&& answer [1]==0){ // exits teh game
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
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
    file.save_game(p,c,w,a);
// scenario 15
    check_point=-1;
    check_point= check_point+1; // used to recoginse the game progression 
    while_stopper=1;
    if (check[check_point]!=1){
        doctor.speak("An infection spreading black spots has hit the kingdom we need more resorces?");
        file.save_game(p,c,w,a);
        cin>>answer;
    }
    while (while_stopper==1 && check[check_point]!=1 ) // waits until the correct input has been made
    if (*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes 
        p->change_up();
        w->change_Down();
        c->change_up();
        w->set_king_popularity(5);
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
        p->change_Down();
        c->change_Down();
        w->change_up();
        a->change_Down();
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if(*answer=='e'&& answer [1]==0){ // exits teh game
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
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
    file.save_game(p,c,w,a);
// scenario 16
    check_point=-1;
    check_point= check_point+1; // used to recoginse the game progression 
    while_stopper=1;
    if (check[check_point]!=1){
        banker.speak("Your Majesty, to celebrate your sons birthday we need more funds. Should we increase tax?");
        file.save_game(p,c,w,a);
        cin>>answer;
    }
    while (while_stopper==1 && check[check_point]!=1 ) // waits until the correct input has been made
    if (*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes 
        p->change_Down();
        w->change_up();
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
        p->set_king_popularity(15);
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if(*answer=='e'&& answer [1]==0){ // exits teh game
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
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
    file.save_game(p,c,w,a);
// scenario 17
    check_point=-1;
    check_point= check_point+1; // used to recoginse the game progression 
    while_stopper=1;
    if (check[check_point]!=1){
        queen.speak("I want the Golden Sea Pearl send the army to get it.");
        file.save_game(p,c,w,a);
        cin>>answer;
    }
    while (while_stopper==1 && check[check_point]!=1 ) // waits until the correct input has been made
    if (*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes 
        w->change_Down();
        a->change_Down();
        w->set_king_popularity(5);
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
        w->change_up();
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if(*answer=='e'&& answer [1]==0){ // exits teh game
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
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
    file.save_game(p,c,w,a);
// scenario 18
    check_point=-1;
    check_point= check_point+1; // used to recoginse the game progression 
    while_stopper=1;
    if (check[check_point]!=1){
        pope.speak("Your Majesty we want to spread our teachings further, can we?");
        file.save_game(p,c,w,a);
        cin>>answer;
    }
    while (while_stopper==1 && check[check_point]!=1 ) // waits until the correct input has been made
    if (*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes 
        c->change_up();
        w->change_Down();
        p->set_king_popularity(10);
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
        c->change_Down();
        w->change_up();
        p->change_Down();
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if(*answer=='e'&& answer [1]==0){ // exits teh game
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
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
    file.save_game(p,c,w,a);
// scenario 19
    check_point=-1;
    check_point= check_point+1; // used to recoginse the game progression 
    while_stopper=1;
    if (check[check_point]!=1){
        mat.speak("Your Majesty the people need more schools?");
        file.save_game(p,c,w,a);
        cin>>answer;
    }
    while (while_stopper==1 && check[check_point]!=1 ) // waits until the correct input has been made
    if (*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes 
        p->change_up();
        w->change_Down();
        w->set_king_popularity(5);
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
        p->change_Down();
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if(*answer=='e'&& answer [1]==0){ // exits teh game
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
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
    file.save_game(p,c,w,a);
// scenario 20
    check_point=-1;
    check_point= check_point+1; // used to recoginse the game progression 
    while_stopper=1;
    if (check[check_point]!=1){
        general.speak("Your Majesty an accident occured the people need help?");
        file.save_game(p,c,w,a);
        cin>>answer;
    }
    while (while_stopper==1 && check[check_point]!=1 ) // waits until the correct input has been made
    if (*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes 
        p->change_up();
        a->change_Down();
        w->set_king_popularity(5);
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
        p->change_Down();
        a->set_king_popularity(5);
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if(*answer=='e'&& answer [1]==0){ // exits teh game
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
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
    file.save_game(p,c,w,a);
    cout<<endl;
    mat.show_face(":>");
    mat.speak("Congratulations on making it this far you are a worthy King, but here comes the hardest question");
    cout<<endl;
    cout<<endl;
// scenario 21
    check_point=-1;
    check_point= check_point+1; // used to recoginse the game progression 
    while_stopper=1;
    if (check[check_point]!=1){
        queen.speak("Who was that? Have you been cheating on me");
        file.save_game(p,c,w,a);
        cin>>answer;
    }
    while (while_stopper==1 && check[check_point]!=1 ) // waits until the correct input has been made
    if (*answer=='y' && answer[1]==0 ) { // if answer is yes it will cause ceratin changes 
        cout<<endl;
        queen.speak("I'll take everything then!");
        cout<<endl;
        p->change_Down();
        p->change_Down();
        a->change_Down();
        a->change_Down();
        w->change_Down();
        w->change_Down();
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if (*answer=='n' && answer [1]==0){ //if answer is no, it will cause ceratin changes 
        cout<<endl;
        queen.speak("Good, you better keep it that way");
        cout<<endl;
        w->change_up();       
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
        while_stopper=0;
    }
    else if(*answer=='e'&& answer [1]==0){ // exits teh game
        file.update_stats(p,c,w,a);
        file.check_end_game(p,c,w,a);
        file.check_point_input(check,check_point); 
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
    file.save_game(p,c,w,a);
    //IMPORTANT this section frees up memory do not add anything below please
    delete answer; // frees up the memory for answer
    delete p;// frees up the memory for people object
    delete c;// frees up the memory for church object
    delete a;// frees up the memory for army object
    delete [] check;// frees up the memory for check array
}