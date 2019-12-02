// 2317839
// Ayden Best
// Class for handling student members

#include <iostream>

using namespace std;

class Student{
private:

  friend class Database;
  int studentID;
  string name;
  string level; // freshman, sophomore, junior, senior
  string major;
  double gpa;
  int advisor; // facultyID of their advisor

public:

  // constructor
  Student();

  Student(int id, string n, string l, string m, double grade, int a);

  // constructor for comparing students
  Student(int id);

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

  friend ostream& operator<<(ostream& out, const Student& s)
  {
    out << "-----===[Student #" << s.studentID << "]===-----" << endl
        << "Name: " << s.name << endl
        << "Grade: " << s.level << endl
        << "Major: " << s.major << endl
        << "GPA: " << s.gpa << endl
        << "Advisor: Faculty Advsisor #" << s.advisor << endl << endl;
    return out;
  }


  // who needs mutator functions? not me, thats who

  void print();
  // print all student information to console

};
