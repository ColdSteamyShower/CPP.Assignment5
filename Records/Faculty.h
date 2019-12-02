// 2317839
// Ayden Best
// Class for handling faculty members

#include <list> // because I'm lazy and don't want to make an iterator

using namespace std;

class Faculty{
private:

  friend class Database;
  int facultyID;
  string name;
  string level; // lecturer, assistant prof., associate prof)
  string department;
  list<int> advisees; // list of students that this faculty member advises

public:

  // constructor
  Faculty();

  Faculty(int id, string n, string l, string dep);

  // constructor for comparing students
  Faculty(int id);

  // destructor not necessary because the class does not deal with pointers

  //
  // operator overloads
  //
  friend bool operator== (const Faculty &f1, const Faculty &f2)
  {
    return (f1.facultyID == f2.facultyID);
  }

  friend bool operator!= (const Faculty &f1, const Faculty &f2)
  {
    return !(f1.facultyID == f2.facultyID);
  }

  friend bool operator> (const Faculty &f1, const Faculty &f2)
  {
    return (f1.facultyID > f2.facultyID);
  }

  friend bool operator< (const Faculty &f1, const Faculty &f2)
  {
    return (f1.facultyID < f2.facultyID);
  }

  friend ostream& operator<<(ostream& out, const Faculty& f)
  {
    out << "-----===[Faculty Member #" << f.facultyID << "]===-----" << endl
         << "Name: " << f.name << endl
         << "Position: " << f.level << endl
         << "Department: " << f.department << endl
         << "Advisees: ";
    for(int i : f.advisees)
    {
      out << i << "; ";
    }
    out << endl;
    return out;
  }


  void print();
  // print all faculty information to console

};
