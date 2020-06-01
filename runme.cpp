//FRESHMAN_PROJECT_CS100
//WHO WANTS TO BE A MILLIONAIRE?
//Copyright @ 2017 Hira Jamshed and Harum Naseem. All rights reserved.

#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
using namespace std;

//This function prints out the instructions when required
void instructions(string name, const string money[], const int SIZE);

/*
    This function is called whenever the input is of a number type and makes sure the user types a number and not a character/string
    Arguments: it takes a boolean variable which is a reference parameter and uses it as a check (whether the user has entered a number or not)
*/
void input_check (bool& correct);

/* 
    This function prints out the pyramid that shows the status of the user in the game, increasing in level after every correct question.. much like
    climbing a ladder
    Arguments: ques_count keeps track of what question the user is on, array money level consists of the amounts corresponding to each question and size
    defines the size of the array
*/
void status_pyramid(int ques_count, const string money_level[], const int size);


/* 
    This function deals with the person quitting or continuing with the game
    Arguemnts: ques_count keeps track of what question the user was on inorder to print out the money that the user gets
 */
int quit(int ques_count);

/*
    This function deals with the lifelines.
    Arguments: ques_count keeps track of the question user is on. The strings are the choices that are displayed in the question. The array ans_array
    contains the answers to every question (corresponding to the ques_count) and SIZE defines the size of the array. The array money_level consists of
    the money corresponding to each question (connected by ques_count) and size defines the size of this array. The boolean variables ll1, ll2 and ll3
    keep track of whether the corresponding lifline has been used. Version keeps count of what version the user is currently on for the second lifeline
    function.
 */
int lifelines(int& ques_count, string A, string B, string C, string D, const string ans_array[][2], const int SIZE, const int money_level[], const int size, bool& ll1, bool& ll2, bool& ll3, int version);

/*
    This function checks whether the answer is correct or not and displays output accordingly.
    Arguments: choice stores the answer of the user, ques_count keeps track of what the user is on, the array money_level consists of
    the money corresponding to each question (connected by ques_count) and size defines the size of this array and the array ans_array
    contains the answers to every question (corresponding to the ques_count) and SIZE defines the size of the array.
 */
int corr_or_incorr(string choice, int& ques_count, const string money_level[], const int size, const string ans_array[][2], const int SIZE);

/*
    deals with the answer
    Arguments: ques_count keeps track of the question user is on, array money_level consists of the money corresponding to each question (connected by
    ques_count) and size defines the size of this array, strings are the choices that are displayed in the question and boolean variables ll1, ll2 and
    ll3 keep track of whether the corresponding lifeline has been used.The array ans_array contains the answers to every question (corresponding to the
    ques_count) and SIZE defines the size of the array. Version keeps count of te version the user is on.
    Note: The function itself doesn't make use of any of the arguments itself.... instead it passes
    them to the functions called in it (lifelines and corr_or_incorr)
*/
int choice_check (int& ques_count, const string money_level[], const int size, string A, string B, string C, string D, bool& ll1, bool& ll2, bool& ll3, string ans_array[][2], const int SIZE, int version);


int main()
{
    const int SIZE = 15;
    string money[SIZE] = {"1,000,000", "500,000", "250,000", "100,000", "50,000", "25,000", "15,000", "12,500", "10,000", "7,500", "5,000", "3,000", "2,000", "1,000", "500"};
    int count_check = 0;
    string name,A,B,C,D, ans, ians;
    bool ll1 = 1, ll2 = 1, ll3 = 1;
    int size_player = 10;
    int array_of_players[10]={1,2,3,4,5,6,7,8,9,10};
    int random_player;
    int version = 1;

    cout <<setw(100) << "WELCOME TO \"WHO WANTS TO BE A MILLIONAIRE!\""<<endl <<endl; //Intro

    srand(time(NULL));
    random_player= rand() % size_player;
    cout << "Randomizing the players........" <<endl
    << "Selecting the player......." <<endl <<endl
    << setw(70) << "PLAYER " << array_of_players[random_player] << " WILL BE PLAYING!" <<endl <<endl;

    cout << "Do you have what it takes?"<<endl
    << "We'll see..."<<endl<<endl<<endl
    << "Enter your name: ";
    getline(cin, name);
    cout <<endl <<endl;

    instructions(name, money, SIZE);

    cout <<endl <<endl <<" "<<setw(100)<<"*******************************************************"<<endl<<endl;

    while (version == 1 || version == 2 || version == 3)
    {
    switch (version)
    {
        case 1: //VERSION 1
        {
            string ans_array[SIZE][2] = {{"D", "d"},{"A", "a"}, {"A","a"}, {"B","b"}, {"C","c"}, {"A","a"}, {"C","c"}, {"B","b"}, {"C","c"}, {"D","d"}, {"D","d"}, {"D","d"}, {"A","a"}, {"D", "d"}, {"C","c"}};
            cout << "Here's your FIRST QUESTION: " <<endl;
            A = "On your collar"; B = "On your lapel"; C = "On your cuff "; D = "On your sleeve"; //FIRST QUESTION
            cout <<"Where do you proverbially wear your heart, if you show your true feelings?" <<endl
            <<"A. " << A <<endl << "B. " <<B <<endl << "C. " << C <<endl << "D. " << D <<endl <<endl
            <<"Remember! Enter L to access the lifelines..." <<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "ELbow room"; B = "Foot rest"; C = "Ear Hole"; D = "Knee Lounge"; //SECOND QUESTION
            cout<<endl << "QUESTION 2: "<<endl
            <<"Which of the following means adequate space for moving in?"<<endl
            <<"A. " << A <<endl << "B. " << B <<endl << "C. " << C <<endl << "D. " << D <<endl <<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "The Water-carrier"; B = "The Food-carrier"; C = "The Hod-carrier"; D = "The Bag-carrier"; //THIRD QUESTION
            cout<<endl << "QUESTION 3: " <<endl
            <<"What is the star sign Aquarius well-known for?"<<endl
            <<"A. "<<A<<endl<<"B. "<<B<<endl<<"C. "<<C<<endl<<"D. "<<D<<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3,ans_array, SIZE,version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Aristotle"; B = "Euclid"; C = "Pythagoras"; D = "Khwarizmi"; //FOURTH QUESTION
            cout<<endl << "QUESTION 4: " << endl
            << "Who is the father of geometry?"<<endl
            <<"A. " << A <<endl << "B. " << B <<endl << "C. " << C <<endl << "D. " << D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3,ans_array, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "0"; B = "40"; C = "-40"; D = "300"; //FIFTH QUESTION
            cout <<endl << "QUESTION 5: " << endl
            << "What is the same temperature in Celsius and farenheit?" <<endl
            << "A. " << A <<endl << "B. " << B <<endl << "C. " << C <<endl << "D. " << D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Frogmen"; B = "Newtmen"; C = "Toadmen"; D = "Tadpolemen"; //SIXTH QUESTION
            cout <<endl << "QUESTION 6: " << endl
            << "Which of these might be used in underwater naval operations?"<<endl
            << "A. " << A <<endl << "B. " << B <<endl << "C. " << C <<endl << "D. " << D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Easy Eric"; B = "Plain Peter"; C = "Simple Simon"; D = "No Frills Fred"; //SEVENTH QUESTION
            cout <<endl << "QUESTION 7: " << endl
            <<"In the nursery rhyme, who met a pieman?" <<endl
            << "A. " << A <<endl << "B. " << B <<endl << "C. " << C <<endl << "D. " << D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array, SIZE,version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Edward Woollyhat"; B = "Charles Macintosh"; C = "Robert Jumper"; D = "Frank Waistcoat"; //EIGTH QUESTION
            cout<<endl << "QUESTION 8: " << endl
            << "Which of the following is associated with the invention of the raincoat"<<endl
            << "A. " << A <<endl << "B. " << B <<endl << "C. " << C <<endl << "D. " << D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3,ans_array, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Shilling"; B = "Quid"; C = "Tanner"; D = "Florin"; //NINTH QUESTION
            cout<<endl << "QUESTION 9: " << endl
            << "What name is given to a person who turns animal skin into leather?"<<endl
            << "A. " << A <<endl << "B. " << B <<endl << "C. " << C <<endl << "D. " << D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "1000"; B = "100,000"; C = "1,000,000"; D = "10,000"; //TENTH QUESTION
            cout<<endl << "QUESTION 10:" <<endl
            <<"How many times does the heart beat in one day?"<<endl
            << "A. " << A <<endl << "B. " << B <<endl << "C. " << C <<endl << "D. " << D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Monaco"; B = "France"; C = "Italy"; D = "Madagascar"; //ELEVENTH QUESTION
            cout<<endl << "QUESTION 11: " << endl
            << "Which of these countries did not host a Formula 1 Grand Prix race in 2003?"<<endl
            << "A. " << A <<endl << "B. " << B <<endl << "C. " << C <<endl << "D. "<<D<<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Weight loss pills"; B = "Modeling programme"; C = "Dating service"; D = "Computer"; //TWELFTH QUESTION
            cout<<endl << "QUESTION 12: " << endl
            << "What was advertised in the worlds first mail?"<<endl
            << "A. " << A <<endl << "B. " << B <<endl << "C. " << C <<endl << "D. " << D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "1929"; B = "1922"; C = "1963"; D = "1977"; //THIRTEENTH QUESTION
            cout<<endl << "QUESTION 13: " <<endl
            <<"The first Oscar Awards ceremony was held on?"<<endl
            << "A. " << A <<endl << "B. " << B <<endl << "C. " << C <<endl << "D. " << D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array, SIZE,version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Jurassic"; B = "Palaeozoic"; C = "Triassic"; D = "Boracic"; //FOURTEENTH QUESTION
            cout<<endl << "QUESTION 14: " << endl
            << "Which of the following is not a geological period?"<<endl
            << "A. " << A <<endl << "B. " << B <<endl << "C. " << C <<endl << "D. " << D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Tasmanian Blue Gum";B = "Coast Redwood"; C = "Seguoia Gigantica"; D = "Western Redcedar"; //FIFTEENTH QUESTION
            cout<<endl << "QUESTION 15: " <<endl
            << "Which the largest tree in the world?"<<endl
            << "A. " << A <<endl << "B. " << B <<endl << "C. " << C <<endl << "D. " << D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array, SIZE, version))
            {
                cout <<setw(80) << "CONGRATULATIONS!!!!!!" <<endl <<setw(82) <<"YOU WON A MILLION DOLLARS!" <<endl
                <<setw(75) <<"WELL PLAYED!" <<endl;
                version++;
            }
            else {version++;break;}
        }
        case 2: //VERSION 2
        {
            string ans_array2[SIZE][2]={{"D","d"}, {"B","b"}, {"D","d"}, {"A","a"}, {"C","c"}, {"C","c"}, {"D","d"}, {"C","c"}, {"C","c"}, {"A", "a"}, {"D","d"}, {"B","b"}, {"A","a"}, {"B","b"}, {"D","d"}};
            count_check = 0; ll1 = 1; ll2 = 1; ll3 = 1; //initializing variables for everything to start all over again

            for (int i = random_player + 1 ; i < size_player; i++) //removing the previous player from the array
            {
                array_of_players[i - 1] = array_of_players[i];
            }
            size_player--;

            random_player= rand() % size_player;
            cout <<endl <<setw(100)<<"*******************************************************"<<endl
            <<endl<<"NEXT PLAYER'S TURN!" <<endl <<"Randomizing the players........" <<endl
            << "Selecting the player......." <<endl <<endl
            << setw(70) << "PLAYER " << array_of_players[random_player] << " WILL BE PLAYING!" <<endl <<endl;
            cout << "Enter your name: ";
            getline(cin, name);
            cout <<endl <<endl  <<"Do you want to see the instructions?" <<endl <<"Enter 'y' for yes or 'n' for no: ";
            getline(cin, ians);
            while(!(ians == "Y" || ians == "y" || ians == "N" || ians == "n"))
            {
                cout << "Enter a valid choice: ";
                getline(cin, ians);
            }
            if (ians == "Y" || ians == "y") {instructions(name, money, SIZE); cout <<endl;}
            else {cout <<endl << "Good luck " << name << "!" <<endl <<endl;}

            A = "Fly 2 Asia"; B = "Swim 2 Europe"; C = "Flee 2 America"; D = "Escape 2 Africa"; //FIRST QUESTION
            cout << "QUESTION 1: " <<endl << "What is the subtitle of the 2008 sequel to Madagascar?" <<endl
            <<"A. "<< A <<endl <<"B. " << B <<endl << "C. " << C <<endl << "D. "<< D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array2, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "India"; B = "Peru"; C = "Canada"; D = "Iceland"; //SECOND QUESTION
            cout << "QUESTION 2:" <<endl << "In the children’s book series, where is Paddington Bear originally from?" <<endl
            <<"A. "<< A <<endl <<"B. " << B <<endl << "C. " << C <<endl << "D. "<< D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array2, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Peter"; B = "John"; C = "Benedict"; D = "James"; //THIRD QUESTION
            cout << "QUESTION 3: " <<endl << "Who is the patron saint of spain?" <<endl
            <<"A. "<< A <<endl <<"B. " << B <<endl << "C. " << C <<endl << "D. "<< D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array2, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Moth"; B = "Roach"; C = "Fly"; D = "Japanese beetle"; //FOURTH QUESTION
            cout << "QUESTION 4:" <<endl << "Which insect shorted out an early supercomputer and inspired the term 'computer bug'?" <<endl
            <<"A. "<< A <<endl <<"B. " << B <<endl << "C. " << C <<endl << "D. "<< D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array2, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Aries"; B = "Capricorn"; C = "Aquarius"; D = "Taurus"; //FIFTH QUESTION
            cout << "QUESTION 5: " <<endl << "Which of these zodiac stars is not represented by an animal that grows horns?" <<endl
            <<"A. "<< A <<endl <<"B. " << B <<endl << "C. " << C <<endl << "D. "<< D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array2, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Albert Einstein"; B = "Niels Bohr"; C = "Isaac Newton"; D = "Enrico Fermi"; //SIXTH QUESTION
            cout << "QUESTION 6:" <<endl << "Which of the following men does not have a chemical element named after him?" <<endl
            <<"A. "<< A <<endl <<"B. " << B <<endl << "C. " << C <<endl << "D. "<< D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array2, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Northern Ireland"; B = "England"; C = "Wales"; D = "Scotland"; //SEVENTH QUESTION
            cout << "QUESTION 7: " <<endl << "Prime Minister Tony Blair was born in which country?" <<endl
            <<"A. "<< A <<endl <<"B. " << B <<endl << "C. " << C <<endl << "D. "<< D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array2, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Henry V"; B = "Richard I"; C = "Henry II"; D = "Henry I"; //EIGHTH QUESTION
            cout << "QUESTION 8:" <<endl << "Which king was married to Eleanor of Aquitaine?" <<endl
            <<"A. "<< A <<endl <<"B. " << B <<endl << "C. " << C <<endl << "D. "<< D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array2, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Harrapa"; B = "Taxila"; C = "Chaj"; D = "Gandhara"; //NINTH QUESTION
            cout << "QUESTION 9:" <<endl << "The area between rivers Jhelum and Chenab is called?" <<endl
            <<"A. "<< A <<endl <<"B. " << B <<endl << "C. " << C <<endl << "D. "<< D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array2, SIZE,version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Finding shapes in clouds"; B = "Sleeping with your eyes open";
            C = "Breaking glass with your voice"; D = "Swimming in freezing water";
            cout << "QUESTION 10" <<endl << "'Nephelococcygia' is the practice of doing what?" <<endl //TENTH QUESTION
            <<"A. "<< A <<endl <<"B. " << B <<endl << "C. " << C <<endl << "D. "<< D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array2, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Eleanor"; B = "Dartmouth"; C = "Beaver"; D = "William"; //ELEVENTH QUESTION
            cout << "QUESTION 11:" <<endl << "Which of these ships was not one of the three taken over by colonists during the Boston Tea Party?"
            <<endl <<"A. "<< A <<endl <<"B. " << B <<endl << "C. " << C <<endl << "D. "<< D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array2, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Equador"; B = "Nepal"; C = "Morocco"; D = "Russia"; //TWELVETH QUESTION
            cout << "QUESTION 12: " <<endl << "Sherpas and Gurkas are native to which country?" <<endl
            <<"A. "<< A <<endl <<"B. " << B <<endl << "C. " << C <<endl << "D. "<< D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array2, SIZE,version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Lesotho"; B = "Burkina Faso"; C = "Mongolia"; D = "Luxembourg"; //THIRTEEN QUESTION
            cout << "QUESTION 13:" <<endl << "Which of the following landlocked countries is entirely contained within another country?" <<endl
            <<"A. "<< A <<endl <<"B. " << B <<endl << "C. " << C <<endl << "D. "<< D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array2, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Helen Taft"; B = "Edith Wilson"; C = "Bess Truman"; D = "Mamie Eisenhower"; //FOURTEENTH QUESTION
            cout << "QUESTION 14:" <<endl << "Which First Lady was a ninth-generation descendant of Pocahontas?" <<endl
            <<"A. "<< A <<endl <<"B. " << B <<endl << "C. " << C <<endl << "D. "<< D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array2, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Declaring a war"; B = "Crowning a royal";C = "Taking the oath of office"; D = "Announcing the budget"; //FIFTEENTH QUESTION
            cout << "QUESTION 15: " <<endl
            << "Drinking alcohol in the British House of commons is strictly forbidden at all times, with the single exception of lawmaker doing what?"
            <<endl <<"A. "<< A <<endl <<"B. " << B <<endl << "C. " << C <<endl << "D. "<< D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array2, SIZE,version))
            {
                cout <<setw(80) << "CONGRATULATIONS!!!!!!" <<endl <<setw(82) <<"YOU WON A MILLION DOLLARS!" <<endl
                <<setw(75) <<"WELL PLAYED!" <<endl;
                version++;
            }
            else {version++;break;}
        }
        case 3: //VERSION 3
        {
            string ans_array3[SIZE][2] = {{"A", "a"}, {"A", "a"}, {"C","c"}, {"D","d"}, {"B","b"}, {"C","c"}, {"A","a"}, {"A","a"}, {"D","d"}, {"B","b"}, {"C","c"}, {"C","c"}, {"B","b"}, {"B", "b"}, {"B","b"}};
            count_check = 0; ll1 = 1; ll2 = 1; ll3 = 1; //initializing variables for everything to start all over again

            for (int i = random_player + 1 ; i < size_player; i++) //removing the player
            {
                array_of_players[i - 1] = array_of_players[i];
            }
            size_player--;

            random_player= rand() % size_player ;
            cout <<endl <<setw(100)<<"*******************************************************"<<endl
            <<endl<<"NEXT PLAYER'S TURN!" <<endl <<"Randomizing the players........" <<endl
            << "Selecting the player......." <<endl <<endl
            << setw(70) << "PLAYER " << array_of_players[random_player] << " WILL BE PLAYING!" <<endl <<endl;
            cout << "Enter your name: ";
            getline(cin, name);
            cout <<endl <<endl  <<"Do you want to see the instructions?" <<endl <<"Enter 'y' for yes or 'n' for no: ";
            getline(cin, ians);
            while(!(ians == "Y" || ians == "y" || ians == "N" || ians == "n"))
            {
                cout << "Enter a valid choice: ";
                getline(cin, ians);
            }
            if (ians == "Y" || ians == "y") {instructions(name, money, SIZE); cout <<endl;}
            else {cout <<endl << "Good luck " << name << "!" <<endl <<endl;}

            cout << "QUESTION 1: " <<endl;
            A = "Saudi Arabia"; B = "Iran"; C = "Russia "; D = "Canada"; //FIRST QUESTION
            cout <<"Which of the countries below has the world’s largest oil reserves?" <<endl
            <<"A. " << A <<endl << "B. " <<B <<endl << "C. " << C <<endl << "D. " << D <<endl <<endl
            <<"Remember! Enter L to access the lifelines..." <<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array3, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Microsoft"; B = "Google"; C = "Yahoo"; D = "AOL"; //SECOND QUESTION
            cout<<endl << "QUESTION 2: "<<endl
            <<"Which of the companies below bought Nokia Mobile business?"<<endl
            <<"A. " << A <<endl << "B. " << B <<endl << "C. " << C <<endl << "D. " << D <<endl <<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array3, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Brazil"; B = "Russia "; C = "Qatar "; D = "France "; //THIRD QUESTION
            cout<<endl << "QUESTION 3: " <<endl
            <<"The 2022 FIFA World Cup will be hosted by?"<<endl
            <<"A. "<<A<<endl<<"B. "<<B<<endl<<"C. "<<C<<endl<<"D. "<<D<<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array3, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Russia"; B = "France"; C = "United Kingdom"; D = "Poland"; //FOURTH QUESTION
            cout<<endl << "QUESTION 4: " << endl
            << "World War II began by German Invasion on?"<<endl
            <<"A. " << A <<endl << "B. " << B <<endl << "C. " << C <<endl << "D. " << D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array3, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Flitter"; B = "Flutter"; C = "Flapper"; D = "Fritter"; //FIFTH QUESTION
            cout <<endl << "QUESTION 5: " << endl
            << "Which one of the following words refer to a small bet?" <<endl
            << "A. " << A <<endl << "B. " << B <<endl << "C. " << C <<endl << "D. " << D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array3, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Friendship pipeline"; B = "Future pipeline"; C = "Peace pipeline"; D = "Unity pipeline"; //SIXTH QUESTION
            cout <<endl << "QUESTION 6: " << endl
            << "The Iran-Pakistan gas pipeline is also called?"<<endl
            << "A. " << A <<endl << "B. " << B <<endl << "C. " << C <<endl << "D. " << D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array3, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Australia"; B = "Sudan"; C = "Malaysia"; D = "France"; //SEVENTH QUESTION
            cout <<endl << "QUESTION 7: " << endl
            <<"Qantas is an airline of?" <<endl
            << "A. " << A <<endl << "B. " << B <<endl << "C. " << C <<endl << "D. " << D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array3, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Tim Berners-Lee"; B = "Bob Kahn"; C = "Steve Jobs"; D = "Bill Gates"; //EIGTH QUESTION
            cout<<endl << "QUESTION 8: " << endl
            << "The World Wide Web was invented by?"<<endl
            << "A. " << A <<endl << "B. " << B <<endl << "C. " << C <<endl << "D. " << D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array3, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Beijing"; B = "Buenos Aires"; C = "Shanghai"; D = "Tokyo"; //NINTH QUESTION
            cout<<endl << "QUESTION 9: " << endl
            << "The most populous city in the world is (as of 2017)?"<<endl
            << "A. " << A <<endl << "B. " << B <<endl << "C. " << C <<endl << "D. " << D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array3, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Japan"; B = "Norway "; C = "Netherlands "; D = "South Africa "; //TENTH QUESTION
            cout<<endl << "QUESTION 10:" <<endl
            <<"Which country is also called the “Land of the Midnight Sun?"<<endl
            << "A. " << A <<endl << "B. " << B <<endl << "C. " << C <<endl << "D. " << D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array3, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
           else {version++;break;}

            A = "Niger"; B = "Nigeria"; C = "Iceland"; D = "Latvia"; //ELEVENTH QUESTION
            cout<<endl << "QUESTION 11: " << endl
            << "Which from the following countries has no armed forces?"<<endl
            << "A. " << A <<endl << "B. " << B <<endl << "C. " << C <<endl << "D. "<<D<<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array3, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "America"; B = "Russia"; C = "Kazakhstan"; D = "India"; //TWELFTH QUESTION
            cout<<endl << "QUESTION 12: " << endl
            << "Worlds oldest operational space launch facility is located in?"<<endl
            << "A. " << A <<endl << "B. " << B <<endl << "C. " << C <<endl << "D. " << D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array3, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Neil Armstrong"; B = "Yuri Gagarin"; C = "Sengei Korolev"; D = "John Glenn"; //THIRTEENTH QUESTION
            cout<<endl << "QUESTION 13: " <<endl
            <<"The first human who traveled into space was?"<<endl
            << "A. " << A <<endl << "B. " << B <<endl << "C. " << C <<endl << "D. " << D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array3, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "Los Angeles"; B = "California"; C = "Tripoli"; D = "Doha"; //FOURTEENTH QUESTION
            cout<<endl << "QUESTION 14: " << endl
            << " The highest temperature was recorded in?"<<endl
            << "A. " << A <<endl << "B. " << B <<endl << "C. " << C <<endl << "D. " << D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array3, SIZE, version));
            else {version++;break;}

            if(quit(count_check)); //quitting check
            else {version++;break;}

            A = "97";B = "98"; C = "99"; D = "100"; //FIFTEENTH QUESTION
            cout<<endl << "QUESTION 15: " <<endl
            << "About what percent of Antarctica is covered by ice?"<<endl
            << "A. " << A <<endl << "B. " << B <<endl << "C. " << C <<endl << "D. " << D <<endl<<endl;
            if(choice_check(count_check, money, SIZE, A, B, C, D, ll1, ll2, ll3, ans_array3, SIZE, version))
            {
                cout <<setw(80) << "CONGRATULATIONS!!!!!!" <<endl <<setw(82) <<"YOU WON A MILLION DOLLARS!" <<endl
                <<setw(75) <<"WELL PLAYED!" <<endl;
                version++;
            }
            else {version++;break;}
        }
    }
    }
    return 0;
}

//function definition for instructions
void instructions(string name, const string money[], const int SIZE)
{
    string ans;
    cout <<setw(80) << "INSTRUCTIONS" <<endl <<endl
    << "-Firstly, there are 15 questions in this game. Each question corresponds to a monetary level, as shown below:"<<endl<<endl;
    int n = 15;
    for (int line = 0; line < n; line++) //for loop to display the pyramid
    {
        for (int spaces = 1; spaces <= n - line; spaces++)
            cout << " ";
        for (int stars = 1; stars <= line + 1; stars++)
            cout << "*";
        if (line == 5 || line == 10) cout << " ---> " << money[line] << "$ <---" <<endl;
        else cout << " ---> " << money[line] << "$" <<endl;
    }
    cout <<endl <<endl
    <<"-Secondly, there are two guaranteed levels ($5,000 and $25,000) as indicated above: an incorrect answer after either one of the levels guarantees that you leaving with that much amount of money. (An incorrect answer before the fifth question leaves you with nothing)" <<endl
    <<"NOTE: You always have a choice to leave." <<endl <<endl <<endl
    <<"-Finally, you have three lifelines to help you through the game (each one of these can be used only once):"<<endl
    <<" > 50:50 - Two of the wrong answers will be eliminated, leaving you with two options to choose from."<<endl
    <<" > Ask the audience - A poll would be generated, depicting what the audience suggests is the correct answer."<<endl
    <<"   NOTE: This may or may not show the correct answer."<<endl
    <<" > Cut the question  - The question will be replaced by an easier question."<<endl
    <<"   NOTE: This has a catch though... it can only be used till the 12th question."<<endl<<endl
    <<"As Maya Angelou says,\"Nothing can dim the light which shines from within\"...It's your time to shine!"<<endl<<endl
    <<"Good Luck "<< name <<"!" <<endl <<endl
    <<"Enter anything to begin: ";
    getline(cin, ans);
    cout <<endl <<endl;
}

//function definition of the input type check function
void input_check (bool& correct)
{
    if (cin.fail()) //input is of wrong type
    {
        cin.clear(); //clears the failed state of the input
        while(cin.get() != '\n') //reads everything till the next line key is entered
            correct = true; //makes sure the loop is run again to check again
        cout << "Please enter a valid value." <<endl;
    }
    else
    {
        cin.ignore(); //ignore whatever was entered and proceed
        correct = false; //the input is correct so no need to check again
    }
}

//function definition for the pyramid that shows status as the game progresses
void status_pyramid(int ques_count, const string money_level[], const int size)
{
    int limit = ques_count;
    for (int line = 0; line <= limit; line++, ques_count--)
    {
        for (int spaces = ques_count; spaces > 0; spaces--)
            cout << " ";
        for (int stars = 0; stars < size - ques_count; stars++)
            cout << "*";
        cout << " ---> " << money_level[size - ques_count - 1] << "$" <<endl;
    }
}

//function definition for thhe function that deals with the person quitting or continuing
int quit (int ques_count)
{
    string ans;
    int quit_amount[15] = {0, 500, 1000, 2000, 3000, 5000, 7500, 10000, 12500, 15000, 25000, 50000, 100000, 250000, 500000};
    cout << "Quit or Continue (enter Q to quit or C to continue with the game): ";
    getline (cin, ans);

    while (!(ans == "Q" || ans == "q" || ans == "C" || ans == "c")) //checking for invalid input
    {
        cout << "Enter a valid option: ";
        getline(cin, ans);
    }
    if (ans == "Q" || ans == "q")
    {
        cout <<endl << "Oh well, the amount that you will be leaving with: "
        << quit_amount[ques_count] << "$" <<endl
        << "Have a good day!" <<endl;
        return 0;
    }
    else // (ans == "C" || ans == "c")
    {
        cout <<endl << "Great spirit! Keep it up!\n";
        return 1;
    }
}

//function definition for the correct or incorrect answers function
int corr_or_incorr(string choice, int& ques_count, const string money_level[], const int size, string ans_array[][2], const int SIZE)
{
    int lost_amount[15] = {0, 0, 0, 0, 0, 5000, 5000, 5000, 5000, 5000, 25000, 25000, 25000, 25000, 25000};

    if (ans_array[ques_count][0] == choice) //check for the capital letter entry
    {
        cout <<endl << "Congratulations! You got the answer correct!" <<endl << "Your status in the game now: " <<endl <<endl;
        status_pyramid(ques_count, money_level, size);
        cout <<endl;
        ques_count++;
        return 1;
    }
    else if (ans_array[ques_count][1] == choice) //check for the small letter entry
    {
        cout <<endl << "Congratulations! You got the answer correct!" <<endl << "Your status in the game now: " <<endl <<endl;
        status_pyramid(ques_count, money_level, size);
        cout <<endl;
        ques_count++;
        return 1;
    }
    else //wrong answer
    {
        cout << "I regret to inform you that your answer is wrong." <<endl
        << "The correct anser is actually " << ans_array[ques_count][0] <<endl << "This, unfortunately, means that you have lost the game."
        <<endl
        << "Amount of money you leave the game with: " << lost_amount[ques_count] << "$" <<endl
        << "Better luck next time!" <<endl << "Have a nice day..... goodbye!" <<endl;
        return 0;
    }
}

//function definition for the lifelines function
int lifelines(int& ques_count, string A, string B, string C, string D, string ans_array[15][2], const int SIZE, const string money_level[], const int size, bool& ll1, bool& ll2, bool& ll3, int version)
{
    int choice, value = 1;
    string ans;
    bool correct = 1;
    int count_check = ques_count;

    //displaying the lifeline options
    cout <<endl << "You have the following lifelines available: " <<endl;
    if (ll1) cout << "  1. 50:50" <<endl;
    if (ll2 && ques_count < 12) cout << "  2. Cut the question" <<endl;
    if (ll3) cout << "  3. Ask the audience" <<endl;
    while (correct)
    {
        cout << "Enter the index number of the lifeline you wish to choose: ";
        cin >> choice;
        input_check(correct);
    }

    while(ll1 || ll2 || ll3) //loop to ensure that the appropriate lifeline is chosen
    {
        if(choice == 1)
        {
            if(ll1)
            {
                cout <<endl << "You have choosen the 50:50 lifeline. This means that two incorrect options will be cut for you. So, in line with that, your new options are: " <<endl;
                //display of the one correct and one incorrect option in different ways (depending on the answer)
                if (ans_array[ques_count][0] == "A") cout << "A. " << A <<endl << "D." << D <<endl;
                else if (ans_array[ques_count][0] == "B") cout << "A." << A <<endl << "B." << B << endl;
                else if (ans_array[ques_count][0] == "C") cout << "B." << B <<endl << "C." << C <<endl;
                else cout << "B." << B <<endl << "D." << D <<endl;
                cout << "Enter your choice: ";
                getline(cin, ans);
                ll1 = 0;
                while (!(ans == "A" || ans == "a" || ans == "B" || ans == "b" || ans == "C" || ans == "c" || ans == "D" || ans == "d")) //checking for invalid input
                {
                    cout << "Enter a valid option: ";
                    getline(cin, ans);
                }
                value = corr_or_incorr(ans, ques_count, money_level, SIZE, ans_array, SIZE);
                break;
            }
            else //if lifeline is chosen once before
            {
                bool check = 1;
                cout<< "Sorry, that lifeline isn't available anymore." <<endl;
                while (check) //input type check
                {
                    cout << "Enter your choice: ";
                    cin >> choice;
                    input_check(check);
                }
                continue;
            }
        }
        if(choice==2)
        {
            int lost_amount[15] = {0, 0, 0, 0, 0, 5000, 5000, 5000, 5000, 5000, 25000, 25000, 25000, 25000, 25000};
            if(ll2 && ques_count < 12)
            {
                if(version==1) //cut-the-question for version 1
                {
                    cout <<endl << "Your other question according to the 'cut the question' lifeline is: " <<endl
                    << "In respect of religion what term was set for the president and prime minister in 1956 constitution?" <<endl
                    << "A. The president and prime minister may or may not be muslims" <<endl
                    << "B. The president and prime minister must be muslims" <<endl
                    << "C. The president must be a muslim but the prime minster may or may not be a muslim" <<endl
                    << "D. The president may or may not be a muslim but the prime minister must be a muslim" <<endl
                    << "Enter your choice: ";
                    getline(cin, ans);
                    ll2 = 0;
                }
                else if(version==2) //cut-the-question for version 1
                {
                    cout<<endl<<"Which of the four Indo-Pakistan wars did not involve any conflict in the disputed region of Kashmir?"<<endl;
                    cout<<"A. 1948"<<endl<<"B. 1965"<<endl<<"C. 1971"<<endl<<"D. 1999"<<endl;
                    getline(cin, ans);
                    ll2=0;
                }
                else //cut-the-question for version 3
                {
                    cout <<endl << "Your other question according to the 'cut the question' lifeline is: " <<endl
                    << "According to Forbes Magazine the most powerful man on the Earth is:" <<endl
                    << "A. Barack Obama" <<endl
                    << "B. Xi Jinping" <<endl
                    << "C. Vladimir Putin" <<endl
                    << "D. Abdullah bin Abdul Aziz al Saud" <<endl
                    << "Enter your choice: ";
                    getline(cin, ans);
                    ll2 = 0;
                }
                while (!(ans == "A" || ans == "a" || ans == "B" || ans == "b" || ans == "C" || ans == "c" || ans == "D" || ans == "d")) //checking for input
                {
                    cout << "Enter a valid option: ";
                    getline(cin, ans);
                }
                if (ans == "C" || ans == "c")
                {
                    cout <<endl << "Congratulations! You got the answer correct!" <<endl << "Your status in the game now: " <<endl << endl;
                    status_pyramid(ques_count, money_level, size);
                    cout <<endl;
                    ques_count++;
                    value = 1;
                }
                else //wrong answer
                {
                    cout <<endl << "I regret to inform you that your answer is wrong." <<endl
                    << "The correct answer actually is C" <<endl
                    << "This, unfortunately, means that you have lost the game."
                    <<endl << "Amount of money you leave the game with: " << lost_amount[ques_count] << "$" <<endl
                    << "Better luck next time!" <<endl << "Have a nice day..... goodbye!" <<endl;
                    value = 0;
                }
                break;
            }
            else //if lifeline has already been chosen once
            {
                bool check = 1;
                cout<< "Sorry, that lifeline isn't available anymore." <<endl;
                while (check)
                {
                    cout << "Enter your choice: ";
                    cin >> choice;
                    input_check(check);
                }
                continue;
            }
        }
        if(choice==3)
        {
            if(ll3)
            {
                int v1, v2, v3, v4;
                srand (time(NULL));
                //randomizing numbers to be output in the poll
                v1 = rand() % 5 + 25;
                v2 = rand() % 5 + 20;
                v3 = rand() % 5 + 25;
                v4 = 100 - (v3 + v2 + v1);

                cout <<endl << "So the poll generated after the collection of results is: " <<endl
                << "_____________________________" <<endl
                << "  choice      | percentage   " <<endl
                << "______________|______________" <<endl
                << " A            | " << v1 << "%" <<endl
                << " B            | " << v2 << "%" <<endl
                << " C            | " << v3 << "%" <<endl
                << " D            | " << v4 << "%" <<endl
                << "______________|______________" <<endl;

                cout << endl << "Enter your choice: ";
                getline(cin, ans);
                ll3 = 0;
                while (!(ans == "A" || ans == "a" || ans == "B" || ans == "b" || ans == "C" || ans == "c" || ans == "D" || ans == "d")) //checking for input
                {
                    cout << "Enter a valid option: ";
                    getline(cin, ans);
                }
                value = corr_or_incorr(ans, ques_count, money_level, SIZE, ans_array, SIZE);
                break;
            }
            else //the lifeline function has already been used
            {
                bool check = 1;
                cout<< "Sorry, that lifeline isn't available anymore." <<endl;
                while (check)
                {
                    cout << "Enter your choice: ";
                    cin >> choice;
                    input_check(check);
                }
                continue;
            }
        }
        else //index number isn't 1,2 or 3
        {
            bool check = 1;
            cout << "That option doesn't exists." <<endl;
            while (check)
            {
                cout << "Enter your choice: ";
                cin >> choice;
                input_check(check);
            }
            continue;
        }
    }
    if (value) return 1; //tells the main function that everything is in order
    else return 0; //the respective version of the game has to end
}

//function definition for the function that deals with correct answers, incorrect answers and lifelines
int choice_check (int& ques_count, const string money_level[], const int size, string A, string B, string C, string D, bool& ll1, bool& ll2, bool& ll3,string ans_array[][2], const int SIZE, int version)
{
    string choice;
    bool check = 1;
    int value = 1;

    while (check) //to go over everything again incase the input entered is not valid
    {
        cout << "Enter your choice: ";
        getline (cin, choice);
        long length = choice.length();

        if (choice == "L" || choice == "l")
        {
            check = 0;
            if (ll1 == 0 && ll2 == 0 && ll3 == 0) //all lifelines used up
            {
                cout << "The lifelines option is no longer available...." <<endl;
                //checking for valid input
                while (choice == "L" || choice == "l" || length != 1 || !(choice == "A" || choice == "a" || choice == "B" || choice == "b" || choice == "C" || choice == "c" || choice == "D" || choice == "d"))
                {
                    cout << "Enter an accpetable choice: ";
                    getline(cin, choice);
                    length = choice.length();
                }
                value = corr_or_incorr(choice, ques_count, money_level, SIZE, ans_array, SIZE);
            }
            else value = lifelines(ques_count, A, B, C, D, ans_array, SIZE, money_level, SIZE, ll1, ll2, ll3,version);
        }
        else if (choice == "A" || choice == "a" || choice == "B" || choice == "b" || choice == "C" || choice == "c" || choice == "D" || choice == "d") //input entered is correct
        {
            check = 0;
            value = corr_or_incorr(choice, ques_count, money_level, SIZE, ans_array, SIZE);
        }
        else //wrong input
        {
            cout << "Enter a valid option!" <<endl;
            check = 1;
        }
    }
    if (value) return 1; //tells the main function that everything is in order
    else return 0; //the respective version of the game has to end
}
