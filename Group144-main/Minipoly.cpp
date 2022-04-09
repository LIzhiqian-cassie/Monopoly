#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
#include "Maingame.h"
#include "Load.h"

//some icons for fun
#define left_half_block "U+258c";

using namespace std;

void printMenu();
void printAchievement();
void printRules();

int main()
{
  string input;
  while (true){
    //print menu and ask for user input

    printMenu();
    cout << "Your command: ";
    cin >> input;
    cout << "------------------------------" << endl;
    cout << "          loading..." << endl;
    cout << "------------------------------" << endl;
    //enter different modules
    if (input == "Q" || input == "q"){  //end entire game
      cout << "Bye Bye" << endl;
      break;
    }
    else if (input == "N" || input == "n"){  //load new game
      cout << "Creating New Game!" << endl;
      Maingame(true);
    }
    else if (input == "L" || input == "l"){
      cout << "Loading..." << endl;
      Maingame(false);
    }
    else if (input == "R" || input == "r"){
      printRules();
    }
    else {
      cout << "Please enter valid command" << endl;
      cout << "------------------------------" << endl;
    }
  }
  return 0;
}



//function that prints the menu on the terminal and return user input
void printMenu()
{
  cout << endl;
  cout << "       <<<Minipoly>>>      " << endl;
  cout << "           <MENU>           " << endl << endl;
  cout << "        [N]New Game         " << endl;
  cout << "           [L]Load          " << endl;
  cout << "           [Q]Quit          " << endl;
  cout << "          [R]Rules         " << endl << endl;
  cout << "------------------------------" << endl;
}

//function to open text file and print out achievement
void printAchievement()
{
  ifstream fin;
  fin.open("Gamedata/achievement.txt");
  //check for intactness
  if (fin.fail()){
    cout << "Game damaged, achievement is missing, please re-download the game" << endl;
    exit(1);
  }
  //print out Achievement
  string temp;
  while (getline(fin, temp)){
    cout << temp << endl;;
  }
  fin.close();
  cout << "-------------------------------" << endl;
  cout << "-------------------------------" << endl;
  //way to quit
  cout << "Press [Q] to quit: " ;
  while (true){
    string input;
    cin >> input;
    if (input == "Q" || input == "q"){
      cout << "-------------------------------" << endl;
      cout << "     Returning to Menu..." << endl;
      cout << "-------------------------------" << endl;
      break;
    }
  }
}

//function to print rules
void printRules()
{
  cout << "Rule:\n\n\nAbout players \xE2\x98\xBA\n"
"You can set the number of players (2~4) at the start of the game. You can pick your nicknames and symbols at the biginning. Players will play this game by turns."

"Human players: you and your friends; Dave: the banker is the third party. You can borrow extra money from him.\n\n\n"

"About blocks\xE2\x9B\xBA\n\n"
"The neighborhood has 16 blocks and consists of 1*START, 4*STORE, 4*PUBLIC_SERVICE, 2*HOUSE, and 5*CHANCE.\n"

"START: Player passed by START (excluding the beginning of the game) will receive a present (randon gain of money) from Dave.\n"

"STORE, PUBLIC_SERVICE and HOUSE: For the players landed on the unsold STORE, PUBLIC_SERVICE and HOUSE, they would have the options to purchase it at the prices of $100,000, $180,000 and $350,000 respectively or pass. The owner can choose sell their STORE, PUBLIC_SERVICE and HOUSE at 70% of the orignal prices to the public in his/her turn. When other players land on the sold STORE, PUBLIC_SERVICE and HOUSE, they would have to pay the owner $10,000, $20,000, $50,000 as passing fee respectively.Those estates will generate rent of 10% of the purchase price of the estate each round.\n"

"CHANCE: Five blocks are CHANCE, players will encounter one of the following mini games: Random Gain/Loss of money, Chess, Stock Exchange, rock-paper-scissors, Sudoku, Slot machine and cateen running. You can earn a lot but can also loss a lot in these games.\n\n\n"

"About financial system\xF0\x9F\x92\xB0\n\n"
"There are 4 types of financial categories: Cash, Building and Saving.\n"

"Cash: the cash you have, it will be automatically stored in the bank. You can use cash to pay the fees to other players anytime. Or you can pay your debt when you finish each circle(after hitting start point). Building: The value of real estate(s) you own. Net: the savings owned by you.Net = Building + Cash.\n\n\n"

"About rounds\xF0\x9F\x8E\xB2\n\n"
"In each round, player will throw the dice and randomly advance 1 to 4 step(s). Players advance according to their order (i.e. Player1 -> Player 2). After moving, players can do the follwing actions:Continue, Buy, Sell, Quit, Save, Save & Quit while the Pay, Game actions will be executed automatically. Player can only payback/borrow debt when passing by/reach start.\n\n\n"

"Winning cretiria\n"
"The goal is to own all STORE, PUBLIC_SERVICE and HOUSE on the map, Or make all other players go bankrupt"
"The winner is the one who survive till the end.\n\n"
"Losing cretiria\n"
"Dave will not believe in you when your net income is less than 0. Then, you are bankrupt.\n\n\n" << endl;
  cout << "Press [Q] to quit: " ;
  while (true){
    string input;
    cin >> input;
    if (input == "Q" || input == "q"){
      cout << "-------------------------------" << endl;
      cout << "     Returning to Menu..." << endl;
      cout << "-------------------------------" << endl;
      break;
    }
  }
}
