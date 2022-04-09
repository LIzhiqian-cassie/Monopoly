#include "Map.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Map::print_map(){
  cout << left;
  cout << setw(12) << block << setw(12) << type << setw(12) << price <<  setw(12) << rent_p << setw(12) << owner << setw(12) << player_pos << endl;
}
