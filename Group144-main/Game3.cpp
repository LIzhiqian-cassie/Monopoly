//Author: LI Zhiqian
//Minigame 3 --- rock paper scissors,playing with the computer

#include <iostream>
#include <cstdlib>
#include <string>
#include "Game3.h"

using namespace std;

//define some cute emotions =w=
#define smile  "\xF0\x9F\x98\x81"
#define cryyy  "\xF0\x9F\x98\xA2"
#define tieee  "\xF0\x9F\x98\x9C"
#define s "\xE2\x9C\x8C"
#define r "\xE2\x9C\x8A"
#define p "\xE2\x9C\x8B"

//check who wins and return the rewards number 
int check(int a, int b){
  string input;
  if (((a == 1) && (b == 2)) || ((a == 3) && (b == 1)) || ((a == 2) && (b == 3))){
    cout << "The computer wins!!" << cryyy << cryyy << cryyy << endl;
    cout << "Press any key to continue: " <<endl;
    cin >> input;
    return 1000;
  }
  else if (a == b){
    cout << "Tie" << tieee << tieee << tieee << endl;
    cout << "Press any key to continue: " <<endl;
    cin >> input;
    return 0;
  }
  else
    cout << "You win!!" << smile << smile << smile << endl;
    cout << "Press any key to continue: " <<endl;
    cin >> input;
    return -1000;

}

int Game3(){
  cout << "WELCOME to play rock-paper-scissors ！！ You will obtain a prize of 2000 dollars if you win, LET'S BEGIN" << endl;
  cout << endl;
  cout << "-------------------------------------------------------------------------------" << endl;
  string begin;
  cout << "Press any key to start the game" << endl;
  cin >> begin;
  int comp,user;
  cout << "The computer has made a choice, and what's your choice ? " << endl;
  cout << "1 : rock " << r << endl;
  cout << "2 : scissors " << s << endl;
  cout << "3 : paper " << p << endl;
  srand(time(NULL));
  comp = rand() % 3 + 1 ;
  cin >> user;
  while (((user == 1) || (user == 2) || (user == 3)) == false){
    cout << "Please make a valid choice!" << endl;
    cin >> user;
  }
  cout << "You chose : " << user << endl;
  cout << "The computer chose : " << comp << endl << "So result : " ;
  return check(comp,user);
}
