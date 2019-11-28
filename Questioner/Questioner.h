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

int choiceToInt(string prompt, string options[], int numOfOptions)
{
  while (true){
    cout << prompt << endl;s
    for (int i=1 ; i<=numOfOptions ; ++i){
      cout << i << ". " << options[i-1] << endl;
    }
    int option;
    cin >> option;
    if (!cin){
      cin.clear();
      cin.ignore();
      cout << endl << "A number is required..." << endl;
    } else if (option < 1 || numOfOptions <= option){
      cout << endl << "That is not an option..." << endl;
    } else {
      return option;
    }
  }
}
