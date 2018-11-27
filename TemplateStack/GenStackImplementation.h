#include <iostream>

using namespace std;

//
// Uh oh, its a template class
// Because of that, we for some reason have to define the class methods in the same file
// .cpp -> .h, include the .h at the end of the class header
//

// Default Constructor
template <typename T>
GenStack<T>::GenStack()
{
  size = 0;
  t = -1;
  stackArray = new T[5];
}

// Destructor
template <typename T>
GenStack<T>::~GenStack()
{
  delete[] stackArray;
  stackArray = NULL;
}

// Removes and returns the top element
template <typename T>
T GenStack<T>::pop() throw(GenStackEmptyException)
{
  if (empty())
    throw GenStackEmptyException();
  int r = t;
  --size;
  --t;
  if (t == -1)
    t = 5;
  return stackArray[r];
}

// Returns the top element
template <typename T>
T GenStack<T>::top()
{
  if (empty())
    throw GenStackEmptyException();
  return stackArray[t];
}

// Pushes an element to the top of the stack
template <typename T>
void GenStack<T>::push(T element)
{
  if (size < 5)
    ++size;
  ++t;
  if (t == 6)
    t = 0;
  stackArray[t] = element;
}

// Returns the number of items in the stack
template <typename T>
int GenStack<T>::getSize()
{
  return size;
}

// Returns true if the stack is empty
template <typename T>
bool GenStack<T>::empty()
{
  return (size == 0);
}
