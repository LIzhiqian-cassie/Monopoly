#include "Player_info.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Player_info::print_userinfo(){
  cout << left;
  cout << setw(12) << player_name << setw(12) << player_cash << setw(12) << player_house <<  setw(12) << player_net << setw(12) << pos << endl;
}
