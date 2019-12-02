#include <iostream>
#include "Faculty.h"

using namespace std;

Faculty::Faculty()
{
  facultyID = 0;
  name = "";
  level = "";
  department = "";
}

Faculty::Faculty(int id, string n, string l, string dep)
{
  facultyID = id;
  name = n;
  level = l;
  department = dep;
  // advisee list left black
}

// constructor for comparing students
Faculty::Faculty(int id)
{
  facultyID = id;
  name = "";
  level = "";
  department = "";
}

// destructor not necessary because the class does not deal with pointers


// who needs mutator functions? not me, thats who

void Faculty::print()
{
  cout << "-----===[Faculty Member #" << facultyID << "]===-----" << endl
       << "Name: " << name << endl
       << "Position: " << level << endl
       << "Department: " << department << endl
       << "Advisees: ";
  for(int i : advisees)
  {
    cout << i << "; ";
  }
  cout << endl;
}
// print all faculty information to console
