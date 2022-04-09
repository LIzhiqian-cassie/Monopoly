#ifndef MAP_H
#define MAP_H
#include <string>

struct Map{
  int block;
  std::string type;
  int price;
  int rent_p;
  std::string owner;
  std::string player_pos;
  void print_map();
};


#endif
