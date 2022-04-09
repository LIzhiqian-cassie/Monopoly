//this program will return the structs stored in saved files
#include <iostream>
#include <fstream>
#include <string>
#include "Player_info.h"
#include "Map.h"
#include "printSaving.h"
#include "checkName.h"

using namespace std;


bool Load(Player_info * player, Map map[16], int &step, int &player_num)
{ //ask for load name
  cout << "****************************************" << endl;
  cout << "These are existing savings:" << endl << endl;
  int t = printSaving();
  if (t == 0){
    cout << "No existing savings" << endl;
    return t;
  }

  cout << "****************************************" << endl;
  cout << "Which one do you want to load? " << endl;
  string input;
  cin >> input;

  //check load name
  while (checkName(input) == false){
    cout << "Oops, no such file, please re-enter name: ";
    getline(cin, input);
  }

  //open file and read in data
  ifstream fin;
  fin.open("Gamedata/savings/" + input + ".txt");
  if (fin.fail()){
    cout << "File damaged, please re-download the game." << endl;
    exit(1);
  }
  //return values of structs
  fin >> step;
  fin >> player_num;
  for (int i = 0; i < 16; i++){
    string a, b;
    fin >> a >> b;
    if (a == "0"){
      a = "";
    }
    if (b  == "0"){
      b = "";
    }
    map[i].owner = a;
    map[i].player_pos = b;
  }
  for (int i = 0; i < player_num; i++){
    fin >> player[i].player_name >> player[i].player_cash >> player[i].player_house >> player[i].player_net >> player[i].pos;
  }
  fin.close();
  return t;
}
