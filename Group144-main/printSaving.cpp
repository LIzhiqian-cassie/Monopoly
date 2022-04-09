#include <iostream>
#include <fstream>
#include "printSaving.h"
using namespace std;

int printSaving()
{
  ifstream fin;
  fin.open("Gamedata/save_directory.txt");
  //fail to open
  if (fin.fail()){
    cout << "File damaged, unable to access data directory, please re-download game." << endl;
    exit(1);
  }
  //print the names
  string name;
  cout << "Existing Names:" << endl;
  int i = 0;
  while(getline(fin, name)){
    cout << name << endl;
    i++;//empty or not
  }
  if (i == 0){
    return 0;
  }
  fin.close();
  return 1;
}
