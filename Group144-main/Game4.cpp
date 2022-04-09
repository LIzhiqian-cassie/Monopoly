//Author: LI Haochen
//UID: 3035638052
//Minigame 4 --- stock
//Description:
//need reinforecement: money left to compare with money invested
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Game4.h"

using namespace std;

int Game4(){
  //initialization
  srand(time(NULL)); //need further modification time(NULL)
  double invest,rate;
  string stock, money;
  int stockNum;

  //ask user to choose stock
  while (true){
    cout << "A stock agent is recommending three interesting stocks:" << endl
    << "No.1 ENGG co. with 10% risk; " << endl
    << "No.2 COMP co. with 20% risk; " << endl
    << "No.3 1340 corp. with 30% risk; " << endl
    << "if you don't want to buy, just say no" << endl
    << "Your choice is (input 1,2,3, or no): ";
    getline(cin, stock);
    //validity verification
    if (stock == "1" || stock == "2" || stock == "3"){
      stockNum = atoi(stock.c_str());
      break;
    }
    else if(stock == "no"){
      return 0;
    }
    else{
      cout << "\nAgent: Sorry I don't understand, please say that again." << endl;
    }
  }
  cout << endl;

  //derive a random rate from player's choice
  rate = (rand() % (stockNum * 10 + 1)) - (stockNum * 10);

  //money to invest
  while (true){
    cout << "Agent : How much you want to invest?: ";
    cin >> money;

    int len = money.length();
    bool isDigit = true;
    //check input validity
    for (int i = 0; i < len; i++){
      if (isdigit(money[i]) == 0){
        isDigit = false;
      }
    }
    if (isDigit){
      invest = atoi(money.c_str());
      cout << "Agent: You have invested $" << invest << endl;
      break;
    }
    else{
      cout << "Agent: what do you mean?" << endl;
    }
  }
  cout << endl;

  //result
  cout << "Some time later, the agent come to you and say: " << endl;
  cout << "The rate turns out to be " << rate << "%" << endl;
  if (rate < 0){
    cout << "Unfortunately, you only get back $";
  }
  else if (rate > 0 ){
    cout << "You lucky dog, you get back $";
  }
  else {
    cout << "Well, no gain no loss, you get back $";
  }
  int output = (1 + rate / 100.0) * invest;
  cout << output << endl;

  string input;
  cout << "Press any key to continue: " << endl;
  cin >> input;
  return output;
}
