// 2317839
// Ayden Best
// Class for holding two databases and handles all operations needed on the databases

#include <iostream>
#include <list>
#include "Database.h"

using namespace std;

Database::Database()
{

}

Database::~Database()
{
  delete studentTree;
  delete facultyTree;
}

Student* Database::findStudent(int id)
{
  return studentTree.access(new Student(id, "", ""))->value;
}

Faculty* Database::findFaculty(int id)
{
  return facultyTree.access(new Faculty(id, "", ""))->value;
}

void Database::printStudents()
{
  studentTree.printTree();
}

void Database::printFaculty()
{
  facultyTree.printTree();
}

void Database::displayStudent()
{
  int id = demandType<int>("Please enter student ID: ","An integer is required...");
  Student* studentPtr = findStudent(id);
  if (studentPtr == NULL)
  {
    cout << "No student found with ID:" << id << endl;
    return;
  }
  studentPtr->print();
}

void Database::displayFaculty()
{
  int id = demandType<int>("Please enter faculty member ID: ","An integer is required...");
  Faculty* facultyPtr = findFaculty(id);
  if (facultyPtr == NULL)
  {
    cout << "No faculty member found with ID:" << id << endl;
    return;
  }
  facultyPtr->print();
}

void Database::studentToFaculty()
{
  int id = demandType<int>("Please enter student ID: ","An integer is required...");
  Student* studentPtr = findStudent();
  int studentid = studentPtr->studentID;
  Faculty* facultyPtr = findFaculty(studentid);
  cout << "Student #" << id << " has advisor:" << endl;
  facultyPtr->print();
}

void Database::facultyToStudents(int id)
{
  int id = demandType<int>("Please enter faculty member ID: ","An integer is required...",);
  Faculty* facultyPtr = findFaculty(id);
  cout << "Faculty Member #" << id << " advises Students:" << endl;
  int unfound = 0;
  for(int studentid : facultyPtr->advisees)
  {
    Student* studentPtr = findStudent(studentid);
    if (studentPtr==NULL)
    {
      ++unfound;
      continue;
    }
    studentPtr->print();
  }
  if (unfound > 0)
    cout << "Faculty Member has " << unfound << " student id's that do not correlate to students" << endl;
}

void Database::addStudent(int id, string n, string l, string m, double grade, int a)
{
  if (studentTree.search())
}

void Database::deleteStudent()
{

}

void Database::addFaculty()
{

}

void Database::deleteFaculty()
{

}

void Database::updateStudentAdvisor()
{

}

void Database::removeAdvisee()
{

}
