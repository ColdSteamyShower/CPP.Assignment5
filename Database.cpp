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

void Database::addStudent()
{
      // get id
  int id;
  while (true){
    int id = demandType<int>("Please enter student ID(0 to exit): ","An integer is required...",);
    if (id == 0)
      return;
    if (studentTree.search(id)) // if the tree contains the student already
    {
      cout << "Student with that ID already exists, please choose another" << endl;
      continue;
    }
    break;
  }

      // get name
  int name = demandType<string>("Please enter student's name: ","A string is required... How do you see this?");
      // get major
  int major = demandType<string>("Please enter student's major: ","A string is required... How do you see this?");
      // get level
  int level;
  switch (choiceToInt("What is this student's grade?",["Freshman","Sophomore","Junior","Senior"],4)){
    case 1:
      level = "Freshman";
      break;
    case 2:
      level = "Sophomore";
      break;
    case 3:
      level = "Junior";
      break;
    case 4:
      level = "Senior";
      break;
    default:
      level = "";
  }
      // get gpa
  double grade = demandType<double>("Please enter student GPA: ","A double is required...");
      // get adviser
  int a;
  while (true)
  {
    int advisorID = demandType<int>("Please enter student's advisor's ID(0 to exit): ","An integer is required...",);
    if (!facultyTree.search(advisorID)) // if the advisors ID is unavailable
    {
      cout << "A faculty member with that ID is not available" << endl;
      continue;
    }
    break;
  }
  if (advisorID == 0)
  return;

  // add the student to the tree
  studentTree.insert(new Student(int id, string name, string level, string major, double grade, int advisorID));

  // add student id to advisor
  Faculty* facultyPtr = findFaculty(new Student(advisorID, "", ""));
  facultyPtr->advisees->push_back(id);

}

void Database::deleteStudent()
{
    // get id
  int id;
  while (true){
    int id = demandType<int>("Please enter student ID(0 to exit): ","An integer is required...",);
    if (id == 0)
      return;
    if (!studentTree.search(id)) // if the tree contains the student already
    {
      cout << "Student with that ID does not exist, please choose another" << endl;
      continue;
    }
    break;
  }


  // delete student and remove their id from their advisor
  Student* studentPtr = findStudent(id);
  int adv = studentPtr->advisor;
  Faculty* facultyPtr = findFaculty(adv);
  facultyPtr->advisees->remove(adv)
  studentTree.deleteNode(new Student(id, "", ""));
}

void Database::addFaculty(int id, string n, string l, string dep, int a)
{
  // get id
  int id;
  while (true){
    int id = demandType<int>("Please enter faculty member's ID(0 to exit): ","An integer is required...",);
    if (id == 0)
      return;
    if (facultyTree.search(id)) // if the tree contains the faculty member already
    {
      cout << "Faculty member with that ID already exists, please choose another" << endl;
      continue;
    }
    break;
  }
}

    // get name
  int name = demandType<string>("Please enter faculty member's name: ","A string is required... How do you see this?");
    // get major
  int department = demandType<string>("Please enter faculty member's department: ","A string is required... How do you see this?");
    // get level
  int level;
  switch (choiceToInt("What is this faculty member's position?",["Lecturer","Assistant Professor","Associate Professor"],3))
  {
    case 1:
      level = "Lecturer";
      break;
    case 2:
      level = "Assistant Professor";
      break;
    case 3:
      level = "Associate Professor";
      break;
    default:
      level = "";
  }
    // advisee list will be empty be default
}

void Database::deleteFaculty()
{
  int choice; // 1 = delete advisees, 2 = migrate advisees
  choice = choiceToInt("What would you like to do with the faculty member's advisees?",["Delete Advisees","Migrate to new faculty member",2]);

  int id;
  while (true){
    int id = demandType<int>("Please enter faculty member's ID to delete(0 to exit): ","An integer is required...",);
    if (id == 0)
      return;
    if (!facultyTree.search(id)) // if the tree contains the faculty member already
    {
      cout << "Faculty member with that ID does not exist, please choose another" << endl;
      continue;
    }
    break;
  }
  if (choice == 1) // delete all the advisees
  {
    Faculty* facultyPtr = findFaculty(id);
    for (int i : facultyPtr->advisees)
    {
      Student* studentPtr = findStudent(i);
      studentTree.deleteNode(studentPtr);
    }
  } else if (choice == 2) // migrate all advisees
  {
    int migrateid;
    while (true){
      int migrateid = demandType<int>("Please enter faculty member's ID to migrate to(0 to exit): ","An integer is required...",);
      if (id == 0)
        return;
      if (!facultyTree.search(id)) // if the tree does not contain the faculty member
      {
        cout << "Faculty member with that ID does not exist, please choose another" << endl;
        continue;
      }
      break;
    }
    for (int i : facultyPtr->advisees)
    {
      Student* studentPtr = findStudent(i);
      studentPtr->studentID = migrateid;
      Faculty* migrateFaculty = findFaculty(migrateid);
      migrateFaculty->advisees->push_back(i);
    }
    facultyTree.deleteNode(Faculty(id,"",""));
  }
}

//void Database::updateStudentAdvisor()


//void Database::removeAdvisee()
