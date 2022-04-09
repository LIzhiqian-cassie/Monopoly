#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <cctype>
#include <iostream>
#include "Map.h"
#include "Player_info.h"
#include "Save.h"
#include "Load.h"
#include "Game1.h"
#include "Game2.h"
#include "Game3.h"
#include "Game4.h"
#include "Game5.h"

using namespace std;

//----------------------all the data used in this game-------------------------------------------------
//-----------------------------------------------------------------------------------------------------
int num_players, steps, step = 0;//step is for counting the length of the game
string cur_type, live = "";  //live string represent the index of the player

//use struct to store the information of each player

Player_info * player = new Player_info [num_players];  //set array of stucts using dynamic arrays

Map map[16];


//----------------------all the function used in this game---------------------------------------------
//-----------------------------------------------------------------------------------------------------
//define a void function to read user input and initialize the beginnig amount of cash&house&debt as well as caculating net_asset
void get_input(){
    cout << "Please select the total number of players(2,3 or 4) :" << endl;
    cin >> num_players;
    player = new Player_info [num_players];
    for (int k = 0; k < num_players; k++)
      live += to_string(k);
    cout << "now please input the name of each player(with 6 characters) :" << endl;
    for (int i = 0; i < num_players; i++){
        cin >> player[i].player_name;
        player[i] = {player[i].player_name, 100000, 0, 10000, 0};
    }
}

//print a table of user information
void print_table1(Player_info player[]){
  cout << "-------------------------------------------------------------------------------" << endl;
  cout << left;
  cout << setw(12) << "Name" << setw(12) << "Cash" << setw(12) << "House" << setw(12) << "Net" << "Current position" << endl;
  for (int j = 0; j < num_players; j++){
    player[j].print_userinfo();
  }
  cout << endl;
}

//print a table of map
void print_table2(Map map[]){
  cout << "-------------------------------------------------------------------------------" << endl;
  cout << left;
  cout << setw(12) << "Block" << setw(10) << "Type" << setw(12) << "Price" <<  setw(12) << "Rent_p" << setw(12) << "Owner" << setw(12) << "Player_pos" << endl;
  for (int j = 0; j < 16; j++)
    map[j].print_map();
}

//initialize the map
void set_map(){
  map[0] = {0, "start\xF0\x9F\x92\x8E",0, 0};
  map[1] = {1, "Store\xF0\x9F\x8F\xA0", 100000, 10000};
  map[2] = {2, "Service\xF0\x9F\x8F\xA6", 180000, 20000};
  map[3] = {3, "Chance\xF0\x9F\x8E\xB2"};
  map[4] = {4, "House\xF0\x9F\x8F\xA1", 350000, 50000};
  map[5] = {5, "Store\xF0\x9F\x8F\xA0", 100000, 10000};
  map[6] = {6, "Chance\xF0\x9F\x8E\xB2"};
  map[7] = {7, "Service\xF0\x9F\x8F\xA6", 180000, 20000};
  map[8] = {8, "Chance\xF0\x9F\x8E\xB2"};
  map[9] = {9, "Store\xF0\x9F\x8F\xA0", 100000, 10000};
  map[10] = {10, "Service\xF0\x9F\x8F\xA6", 180000, 20000};
  map[11] = {11, "Chance\xF0\x9F\x8E\xB2"};
  map[12] = {12, "House\xF0\x9F\x8F\xA1", 350000, 50000};
  map[13] = {13, "Service\xF0\x9F\x8F\xA6", 180000, 20000};
  map[14] = {14, "Chance\xF0\x9F\x8E\xB2"};
  map[15] = {15, "Service\xF0\x9F\x8F\xA6", 180000, 20000};

}



//--------------------------------------------main part------------------------------------------------
//-----------------------------------------------------------------------------------------------------
void Maingame(bool is_N){
  // initialize all the information of players
  if (is_N == true){
    get_input();
    set_map();
  }
  else{
    set_map();
    bool t2 = Load(player, map, step, num_players);
    if (t2 == 0)
      return;
  }


  for (int i = 0; i < 10000; i++){
    step++;
    system("clear");
    print_table1(player);
    print_table2(map);
    string begin = "";
    int cur_rent, cur_price;
    int cur = i % num_players;

    //skip the dead player
    if (live.find(to_string(cur)) > live.length())
      continue;
    if (player[cur].player_net >= 0){
      cout << "It's " << player[cur].player_name << "'s turn, press anything to throw a dice" << endl;
      cin >> begin;
      }

      // part varaible
      string ans_buy;
      srand(time(NULL));
      steps = rand() % 6 + 1;
      cout << player[cur].player_name <<  " will move " << steps << " steps" << endl;
      player[cur].pos =(player[cur].pos + steps) % 16;
      //delete the last position and refresh the new one
      for (int m = 0; m < 16; m++){
        if (map[m].player_pos.find(player[cur].player_name) <= 8)
          map[m].player_pos.erase(map[m].player_pos.find(player[cur].player_name),map[m].player_pos.find(player[cur].player_name) + player[cur].player_name.length());
      }
      //if (map[player[cur].pos].player_pos != "")
      map[player[cur].pos].player_pos += player[cur].player_name;
      cur_type = map[player[cur].pos].type;
      cur_price = map[player[cur].pos].price;
      cur_rent = map[player[cur].pos].rent_p;
      if (cur_type == "Chance\xF0\x9F\x8E\xB2"){
        cout << "Loading little games ..." << endl;
        srand(time(NULL));
        int gamei = rand() % 5 + 1;
        switch (gamei){
          case 1:
            player[cur].player_cash += Game1();
            break;
          case 2:
            player[cur].player_cash += Game2();
            break;
          case 3:
            player[cur].player_cash += Game3();
            break;
          case 4:
            player[cur].player_cash += Game4();
            break;
          case 5:
            player[cur].player_cash += Game5();
            break;
        }
      }
      else if (cur_type == "start\xF0\x9F\x92\x8E"){
        cout << "Congratulations ! You hit the *start* and will be given 2000 for the next round " << endl;
        player[cur].player_cash += 2000;
        player[cur].player_net = player[cur].player_cash + player[cur].player_house;
        }
      else{

      // if ((cur_type == "Store") || (cur_type == "House") || (cur_type == "Service")) {
        if (map[player[cur].pos].owner == ""){
          cout << "The price of " << cur_type << " is " << cur_price <<" and the rent price is " << cur_rent << ", would you like to buy it? (input yes/no)" << endl;
          cin >> ans_buy;
          while ((ans_buy != "yes") && (ans_buy != "Yes") && (ans_buy != "no") && (ans_buy != "No")) {
            cout << "please input valid yes / no again" << endl;
            cin >> ans_buy;
          }

          //player will buy the house and change the info for table1 and table2
          if ((ans_buy == "yes") || (ans_buy == "Yes")){
            cout << "Nice choice !!! You bought it~~" << endl;
            map[player[cur].pos].owner = player[cur].player_name;
            player[cur].player_cash -= cur_price;
            player[cur].player_house += cur_price;
            player[cur].player_net = player[cur].player_cash + player[cur].player_house;
          }
          else
            cout << "Oh, You lose the chance to buy it now, looking forwards to next transaction." << endl;
        }
        else if (map[player[cur].pos].owner == player[cur].player_name)
          cout << "Haha, you passed by your own house ~ ~" << endl;
        else{
          //part varaible
          string cur_owner;
          cur_owner = map[player[cur].pos].owner;
          cout << "Sorry, it belongs to " << cur_owner << ". You are supposed to pay him/her " << cur_rent << " for passing by." << endl;
          player[cur].player_cash -= cur_rent;
          player[cur].player_net = player[cur].player_cash + player[cur].player_house;
          for (int j = 0; j < num_players; j++){
            if (player[j].player_name == cur_owner)
              player[j].player_cash += cur_rent;
              player[j].player_net = player[j].player_cash + player[j].player_house;
          }
        }

    }


    if (player[cur].player_net < 0)  {
      cout << player[cur].player_name << " is broke up" << endl;

      //
      if (live.length() == 1){
        cout << "\xF0\x9F\x8E\x89 game over \xF0\x9F\x8E\x89!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl << endl << endl << endl << endl << endl;
        system("clear");
        return ;
      }
      map[player[cur].pos].player_pos.erase(map[player[cur].pos].player_pos.find(player[cur].player_name),map[player[cur].pos].player_pos.find(player[cur].player_name) + player[cur].player_name.length());
      live.erase(live.begin() + live.find(to_string(cur)));
      //cout << "3";
      //map[player[cur].pos].player_pos = "";
      for (int m = 0; m < 16; m++){
        if (map[m].owner == player[cur].player_name)
          map[m].owner = "";
      }
    }
    if (live.length() == 1){
      cout << "\xF0\x9F\x8E\x89 game over \xF0\x9F\x8E\x89!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl << endl << endl << endl << endl << endl;
      system("clear");
      return;
    }
    player[cur].player_net = player[cur].player_cash + player[cur].player_house;
    cout << endl << endl << endl << endl << endl << endl;

    //give player choice to continue the game or just save and quit or quit without saving
    cout << "NOW, choose from the following options, and input the number before your choice" << endl;
    cout << "1.CONTINUE       2.SAVE and QUIT      3.QUIT" << endl;
    int num;
    cin >> num;
    while((num != 1) && (num != 2) && (num != 3)){
      cout << "please input valid number !" << endl;
      cin >> num;
    }
    switch(num){
      case 2:{
        Save(player, map, step, num_players);
        string b;
        return;
      }
      case 3:
        return;
    }

    }
}
