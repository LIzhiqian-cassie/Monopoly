//Author: LI Zhiqian
//Minigame 2 --- tic tak toe, play with the computer
//Description:
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cctype>
#include <sstream>
#include "Game2.h"

using namespace std;

string ele = "123456789";
bool flag, vflag;
//---------print the board
void printboard(string a){
    for (int i = 0; i < 9; i++){
        if (i % 3 != 2){
            cout << a[i] << " ";
          }
        else
            cout << a[i] << endl;
    }
}

//check the winner, if someone wins return true
bool check(string a){
  flag = false;
  //vertically
  for (int i = 0; i < 3; i++){
    if ((a[i] == a[i+3]) && (a[i+3] == a[i+6]))
      flag = true;
      }
  //horizontally
  for (int i = 0; i < 7; i += 3){
    if ((a[i] == a[i+1]) && (a[i+1] == a[i+2]))
      flag = true;
  }
  //diagonally
  if ((a[0] == a[4]) && (a[4] == a[8]))
    flag = true;
  if ((a[2] == a[4]) && (a[4] == a[6]))
    flag = true;
  return flag;
}

//check whther a position is valid for choosing
bool valid(string pos){
  string poss;
  poss = pos;
  vflag = false;
  for (int i = 0; i < 9; i ++){
    if (poss[0] == ele[i])
      vflag = true;
  }
  return vflag;
}

int Game2(){
    cout << "welcome to play Tic Tac Toe!! You will obtain a prize of 2000 dollars if you win, LET'S BEGIN" << endl;
    cout << "Rules : choose a position(by number), you are X while the computer is O" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    string begin;
    cout << "Press any key to start the game" << endl;
    cin >> begin;
    int count = 0, pos,pos2;
    string player,pos1;
    printboard(ele);
    while (check(ele) == false){
      if (count % 2 == 0){
        player = "your";
        cout << "It's " << player << " turn, choose a position:  ";
        cin >> pos1;
        while (valid(pos1) == false){
          cout << "plseae choose another valid posotion" << endl;
          cin >> pos1;
        }
        stringstream str;
        str << pos1;
        str >> pos;
        ele[pos - 1] = 'X';
        printboard(ele);
        cout << endl;
        count ++;
      }
      else {
        cout << "It's the computer's turn" << endl;
        srand(time(NULL));
        pos2 = rand() % 9 + 1;
        string poss2;
        stringstream str1;
        str1 << pos2;
        str1 >> poss2;
        while (valid(poss2) == false){
          pos2 = rand() % 9 + 1;
          poss2 = to_string(pos2);
        }
        ele[pos2 - 1] = 'O';
        printboard(ele);
        cout << endl;
        count ++;
      }
    }
    string input;
    if (count%2 == 1){
      cout << "YOU win!\xF0\x9F\x92\x8E Press any key to continue: ";
      cin >> input;
      ele = "123456789";
      return 1000;
    }
    else{
      cout << "THE COMPUTER wins! Press any key to continue: ";
      cin >> input;
      ele = "123456789";
      return 0;
    }
}
