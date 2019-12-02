#include <iostream>
#include <list>
#include "Questioner.h"

using namespace std;

int choiceToInt(string prompt, string options[], int numOfOptions)
{
  while (true){
    cout << prompt << endl;
    for (int i=0 ; i<numOfOptions ; ++i){
      cout << (i+1) << ". " << options[i] << endl;
    }
    int option;
    cin >> option;
    if (!cin){
      cin.clear();
      cin.ignore();
      cout << endl << "A number is required..." << endl;
    } else if (option < 1 || numOfOptions < option){
      cout << endl << "That is not an option..." << endl;
    } else {
      return option;
    }
  }
}
