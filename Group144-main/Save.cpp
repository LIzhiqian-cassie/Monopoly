#include <fstream>
#include <iostream>
#include <string>
#include "Map.h"
#include "Player_info.h"
#include "printSaving.h"
#include "checkName.h"

using namespace std;


void Save(const Player_info * player, const Map map[16], int step, int player_num)
{
  //update Achievement!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  //print existing names
  printSaving();
  cout << "---------------------------------" << endl;
  //ask for saving name
  string name;
  cout << "Input name for this saving: ";
  cin >> name;

  //check if filename already exist
  while (checkName(name) == true){
    string answer;
    cout << "This name is taken, do you want to overwrite the record?[Y/N]: ";
    getline(cin, answer);
    if ( answer == "Y" || answer == "y"){  //true: overwrite
      break;
    }
    else if ( answer == "N" || answer == "n"){  //false: re-enter name
      cout << "Please enter a new name: ";
      getline(cin, name);
    }
  }

  //adjustment to save_directory
  if (checkName(name) == false){
    ofstream fout1;
    fout1.open("Gamedata/save_directory.txt",ios::app);
    //open failure
    if(fout1.fail()){
      cout << "File damaged, unable to access data directory, please re-download game." << endl;
      exit(1);
    }
    //append new name
    fout1 << name << endl;
    fout1.close();
  }

  //create/overwrite
  ofstream fout2;
  fout2.open(("Gamedata/savings/" + name + ".txt").c_str());
  if(fout2.fail()){  //if fail to open
    cout << "File damaged, unable to access data directory, please re-download game." << endl;
    exit(1);
  }

  //add data to file
  //data structure:
  //step
  //player_num
  //16 map info
  //playerinfo
  fout2 << step << endl;
  fout2 << player_num << endl;
  for (int i = 0; i < 16; i++){
    string a = map[i].owner, b = map[i].player_pos;
    if (a == ""){
      a = "0";
    }
    if (b == ""){
      b = "0";
    }
    fout2 << a << " " << b << endl;
  }

  for (int i = 0; i < player_num; i++){
    fout2 << player[i].player_name << " " << player[i].player_cash << " " << player[i].player_house << " " << player[i].player_net << " " << player[i].pos << endl;
  }
  fout2.close();
}
