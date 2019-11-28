// Ayden Best
// 2317839
// Functions that make it easier to ask for input from the user

#include <iostream>
#include <list>

using namespace std;

template <typename T>
T demandType(string prompt, string msgIncorrect)
{
  cout << prompt;
  T input;
  cin >> input;
  while (!cin) {
    cin.clear();
    cin.ignore();
    cout << msgIncorrect << endl;
    cout << prompt;
    cin >> input;
  }
  return input;
}

int choiceToInt(string prompt, list<string> options)
{
  while (true){
    int optionNum = 0;
    cout << prompt << endl;
    for (string s : options){
      cout << ++optionNum << ". " << s << endl;
    }
    cin >> option;
    if (!cin){
      cin.clear();
      cin.ignore();
      cout << string( 100, '\n' ) << "A number is required..." << endl;
    } else if (option < 1 || numOfOptions <= option){
      cout << string( 100, '\n' ) << "That is not an option..." << endl;
    } else {
      return option;
    }
  }
}
