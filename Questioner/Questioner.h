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

int choiceToInt(string prompt, string options[], int numOfOptions);
