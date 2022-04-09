#include <iostream>
#include <fstream>
#include <string>
#include "checkName.h"

using namespace std;

//function to check for existence of new name input, return true is already exist, false otherwise
bool checkName(string name)
{
  ifstream fin;
  fin.open("Gamedata/save_directory.txt");
  //fail to open
  if (fin.fail()){
    cout << "File damaged, unable to access data directory, please re-download game." << endl;
    exit(1);
  }
  //check for the same name
  string temp;
  while (getline(fin, temp)){
    if (temp == name){
      fin.close();
      return true;
    }
  }
  fin.close();
  return false;
}
