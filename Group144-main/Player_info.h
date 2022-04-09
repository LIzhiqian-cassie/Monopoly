#ifndef PLAYER_INFO_H
#define PLAYER_INFO_H
#include <string>


struct Player_info
{
    std::string player_name;
    int player_cash;
    int player_house;
    int player_net;
    int pos;
    void print_userinfo();
};

#endif
