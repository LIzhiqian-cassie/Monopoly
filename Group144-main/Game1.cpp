//Author: LI Zhiqian
//Minigame 1 --- generate random payment/price for player and return the gained number

#include <iostream>
#include <cstdlib>
#include <string>
#include "Game1.h"

using namespace std;

int Game1(){
    cout << "Welcome to Game1, you will have random gain/loss in this game for some reasons, wish you good luck!!" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    string begin;
    cout << "Press any key to start the game" << endl;
    cin >> begin;
    srand(time(NULL));
    int a, asset = 0;
    a = rand() % 6;
    switch(a){
      case 0:
          cout << "Congratulations!!! Dividend paid by the bank is received.\nCOLLECT 1000 dollars" << endl;
          asset += 1000;
          break;
      case 1:
          cout << " Congratulations!!! Your bond matures and cash is received.\nCOLLECT 2000 dollars" << endl;
          asset += 2000;
          break;
      case 2:
          cout << " Congratulations!!! Your profit earned from selling the stock is received\nCOLLECT 3000 dollars" << endl;
          asset += 3000;
          break;
      case 3:
          cout << "Sorry… You are fined due to illegal parking\nPAY 1000 dollars" << endl;
          asset -= 1000;
          break;
      case 4:
          cout << " Sorry… You receives a profit tax bill\nPAY 2000 dollars" << endl;
          asset -= 2000;
          break;
      default:
          cout << "Sorry… You clash with a car and medical expense is required for treatment\nPAY 3000 dollars" << endl;
          asset -= 3000;
          break;
    }
    string input;
    cout <<"Press any key to continue: "  << endl;
    cin >> input;
    return asset;

}
