#include <iostream>

using namespace std;

class Student{
private:

  int studentID;
  string name;
  string level; // freshman, sophomore, junior, senior
  string major;
  double gpa;
  int advisor; // facultyID of their advisor

public:

  // constructor
  Student(int id, string n, string l, string m, double grade, int a);

  // constructor for comparing students
  Student(int id, string l, string m);

  // destructor not necessary because the class does not deal with pointers

  // operator overloads
  friend bool operator== (const Student &s1, const Student &s2)
  {
    return (s1.studentID == s2.studentID);
  }

  friend bool operator!= (const Student &s1, const Student &s2)
  {
    return !(s1.studentID == s2.studentID);
  }

  friend bool operator> (const Student &s1, const Student &s2)
  {
    return (s1.studentID > s2.studentID);
  }

  friend bool operator< (const Student &s1, const Student &s2)
  {
    return (s1.studentID < s2.studentID);
  }

  // who needs mutator functions? not me, thats who

  void print();
  // print all student information to console

};
