#include <iostream>
#include "Faculty.h"

using namespace std;

Faculty::Faculty(int id, string n, string l, string dep, int a)
{
  facultyID = id;
  name = n;
  level = l;
  department = dep;
}

// constructor for comparing students
Faculty::Faculty(int id, string l, string dep)
{
  facultyID = id;
  name = "";
  level = l;
  department = dep;
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
  for (list<int>::iterator s=advisees.begin(); s != advisees.end(); ++s)
  {
    cout << s->studentID;
    if (s != advisees.end())
      cout << ", ";
  }
  cout << endl;
}
// print all faculty information to console
