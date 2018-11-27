// Ayden Best
// 2317839
// A stack structure modified to only hold 5 values

#include <iostream>
#include "GenStackEmptyException.h"

using namespace std;

template <typename T>
class GenStack {
private:
  int size;                // number of elements allowed in stackArray
  int t;                    // The index of the top element in stackArray
  T* stackArray;             // The array that holds all items in the stack


public:

    GenStack();               // Default Constructor
    ~GenStack();                // Destructor

    T pop() throw(GenStackEmptyException); // Removes and returns the top element

    T top();                  // Returns the top element

    void push(T element);     // Pushes an element to the top of the stack to a max of 5. If pushing over 5, delete the first object

    int getSize();               // Returns the number of items in the stack

    bool empty();             // Returns true if the stack is empty


};

#include "GenStackImplementation.h"
