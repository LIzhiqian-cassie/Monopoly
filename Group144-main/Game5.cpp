//Author: LI Haochen
//UID: 3035638052
//Minigame 5 ---

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <unistd.h>
#include "Game5.h"

using namespace std;

unsigned int microsecond = 1000000;

#define BSPADE  "\xE2\x99\xA0"
#define WSPADE  "\xE2\x99\xA4"
#define BCLUB  "\xE2\x99\xA3"
#define WCLUB  "\xE2\x99\xA7"
#define BHEART  "\xE2\x99\xA5"
#define WHEART  "\xE2\x99\xA1"
#define BDIAMOND  "\xE2\x99\xA6"
#define WDIAMOND  "\xE2\x99\xA2"

void rule();
void delay(int);
bool check1(const int [4]);
bool check2(const int [4]);
bool check3(const int [4]);
bool check4(const int [4]);

int Game5(){
  rule();
  //store:BSPADE,WSPADE,BCLUB,WCLUB,BHEART,WHEART,BDIAMOND,WDIAMOND
  string pool[8] = {BSPADE,WSPADE,BCLUB,WCLUB,BHEART,WHEART,BDIAMOND,WDIAMOND};
  int money = 0;

  //rule asking
  /*cout << "Need rules? Press[Y] if you need, [ANY OTHER KEY] + [ENTER] to continue: ";
  string ans;
  cin >> ans;
  if (ans == "y"){
    rule();
  }
  cout << "Press [ANY KEY] + [ENTER] to start: " ;
  cin >> ans;*/

  //generate random result
  srand(time(NULL));//need furether modification**********
  int result[4];
  for (int i = 0; i < 4; i++){
    result[i] = rand() % 7;
  }
  //judge
  if (check1(result)){
    money += 10000;
  }
  else if (check2(result)){
    money += 5000;
  }
  else if (check3(result)){
    money += 3000;
  }
  else if (check4(result)){
    money += 2000;
  }
  else
    money += 1000;

  //Print result
  for (int i = 0; i < 4; i++){
    cout << pool[result[i]] << endl;
    usleep(1 * microsecond) ;
  }
  cout << endl;
  cout << "You have won $" <<  money << endl;
  cout << "Press ant key to continue: " << endl;
  string input;
  cin >> input;
  return money;
}

//this is a print rule function
void rule()
{
  cout << "Rule for slot machine: " << endl
  << "After start, the machine will eventually show 3 slots, some combinations' existence will bring you return:" << endl
  << "1. Four exactly same slots will bring you $10,000" << endl
  << "2. Three exactly same slots will bring you $5,000" << endl
  << "3. Four slots with the same shape will bring you $3,000" << endl
  << "4. Four slots with the same color will bring you $2,000" << endl
  << "5. Any other slots will bring you $1,000" << endl
  << "All the awards are non-cumulatetive, i.e. you can get the highest reward out of your slots." << endl << endl;
}

//this function will return true if the reult matchs situation 1 (Four exactly same slots)
bool check1(const int b[4])
{
  for (int i = 1; i < 4; i++){
    if (b[i] != b[0]){
      return false;
    }
  }
  return true;
}

//this function will return true if the reult matchs situation 2 (Three exactly same slots)
bool check2(const int b[4])
{
  //check the same elements with element i
  int same[4] = {};
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      if (b[j] == b[i]){
        same[i]++;
      }
    }
  }

  //count the similarity pattern
  int numof3 = 0;
  for (int i = 0; i < 4; i++){
    if (same[i] == 3){
      numof3++;
    }
  }

  //output according to the pattern
  if (numof3 == 3){
    return true;
  }
  else {
    return false;
  }
}

//this function will return true if the reult matchs situation 4 (Four  slots with the same color)
bool check3(const int b[4])
{
  for (int i = 0; i < 4; i++){
    if ((b[i]/2) != (b[0]/2)){  //if there exists differnt shape
      return false;
    }
  }
  return true;
}

//this function will return true if the reult matchs situation 3 (Four slots with the same color)
bool check4(const int b[4])
{
  //check black and white number
  int blackNum = 0, whiteNum = 0;
  for (int i = 0; i < 4; i++){
    int color = b[i] % 2; //return 0 if blck, return 1 if white
    if (color == 0){
      blackNum++;
    }
    else{
      whiteNum++;
    }
  }
  //if all white or all black, return true
  if (whiteNum == 4  || blackNum == 4){
    return true;
  }
  else{
    return false;
  }
}
