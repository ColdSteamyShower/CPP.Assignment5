#include <iostream>
#include "Student.h"

using namespace std;

// constructor
Student::Student()
{
  studentID = 0;
  name = "";
  level = "";
  major = "";
  gpa = 0.0;
  advisor = 0;
}

Student::Student(int id, string n, string l, string m, double grade, int a)
{
  studentID = id;
  name = n;
  level = l;
  major = m;
  gpa = grade;
  advisor = a;
}

// constructor for comparing students
Student::Student(int id)
{
  studentID = id;
  name = "";
  level = "";
  major = "";
  gpa = 0.0;
  advisor = -1;
}


// who needs mutator functions? no me, thats who

void Student::print()
{
  cout << "-----===[Student #" << studentID << "]===-----" << endl
       << "Name: " << name << endl
       << "Grade: " << level << endl
       << "Major: " << major << endl
       << "GPA: " << gpa << endl
       << "Advised by Faculty Advisor #" << advisor << endl << endl;
}
// print all student information to console
