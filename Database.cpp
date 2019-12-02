// 2317839
// Ayden Best
// Class for holding two databases and handles all operations needed on the databases

#include <iostream>
#include <list>
#include "Database.h"
#include "./Saves/ReaderWriter.h"

using namespace std;

Database::Database()
{
  studentTree = readStudentFile();
  facultyTree = readFacultyFile();
}

void Database::save()
{
  BST<Student>* sTree = &studentTree;
  BST<Faculty>* fTree = &facultyTree;

  writeFile(sTree, fTree);
}

Database::Database(const Database &d)
{
  studentTree = d.studentTree;
  facultyTree = d.facultyTree;
}

Database::~Database()
{

}

Student* Database::findStudent(int id)
{
  Student s(id);
  return &(studentTree.access(s)->key);
}

Faculty* Database::findFaculty(int id)
{
  Faculty f(id);
  return &(facultyTree.access(f)->key);}

int Database::pickStudent()
{
  int id;
  while (true){
    id = demandType<int>("Please enter student's ID(0 to exit): ","An integer is required...");
    if (id == 0)
      return id;
    if (!studentTree.search(Student(id))) // if the tree does not contain the student
    {
      cout << "Student with that ID does not exist, please choose another" << endl;
      continue;
    }
    break;
  }
  cout << "Successfully found student with ID " << id << endl;
  return id;
}

int Database::pickFaculty()
{
  int id;
  while (true){
    id = demandType<int>("Please enter faculty member's ID(0 to exit): ","An integer is required...");
    if (id == 0)
      return id;
    if (!facultyTree.search(Faculty(id))) // if the tree does not contain the student
    {
      cout << "Faculty member with that ID does not exist, please choose another" << endl;
      continue;
    }
    break;
  }
  cout << "Successfully found faculty with ID " << id << endl;
  return id;
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
  int id = pickStudent(); // have user give the id of a real student
  if (id == 0)
    return;
  Student* studentPtr = findStudent(id);
  studentPtr->print();
}

void Database::displayFaculty()
{
  int id = pickFaculty(); // have user give the id of a real faculty member
  if (id == 0)
    return;
  Faculty* facultyPtr = findFaculty(id);
  facultyPtr->print();
}

void Database::studentToFaculty()
{
  int id = pickStudent(); // have user give the id of a real student
  if (id == 0)
    return;
  Student* studentPtr = findStudent(id);
  int advisorid = studentPtr->advisor;
  Faculty* facultyPtr = findFaculty(advisorid);
  cout << "Student #" << id << " has advisor:" << endl;
  facultyPtr->print();
}

void Database::facultyToStudents()
{
  int id = pickFaculty(); // have user give the id of a real faculty member
  if (id == 0)
    return;
  Faculty* facultyPtr = findFaculty(id);
  cout << "Faculty Member #" << id << " advisees Students:" << endl;
  int unfound = 0; // to keep track of any advisees that do not exist, this should always be 0
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
  // This annoying block of code is used separately, because this variation is only used once
  ////////////
  int id;
  while (true){
    id = demandType<int>("Please enter student ID(0 to exit): ","An integer is required...");
    if (id == 0)
      return;
    if (studentTree.search(Student(id))) // if the tree contains the student already
    {
      cout << "Student with that ID already exists, please choose another" << endl;
      continue;
    }
    break;
  }
  //////////

      // get name
  string name = demandType<string>("Please enter student's name: ","A string is required... How do you see this?");
      // get major
  string major = demandType<string>("Please enter student's major: ","A string is required... How do you see this?");
      // get level
  string level;
  switch (choiceToInt("What is this student's grade?",levels,4)){
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
  int advisorID = pickFaculty(); // have user give the id of a real faculty member
  if (advisorID == 0)
    return;
  // add the student to the tree
  studentTree.insert(Student(id, name, level, major, grade, advisorID));

  // add student id to advisor
  Faculty* facultyPtr = findFaculty(advisorID);
  facultyPtr->advisees.push_back(id);

}

void Database::deleteStudent()
{
    // get id
  int id;
  while (true){
    id = demandType<int>("Please enter student ID(0 to exit): ","An integer is required...");
    if (id == 0)
      return;
    if (!studentTree.search(Student(id))) // if the tree contains the student already
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
  facultyPtr->advisees.remove(id);
  studentTree.deleteNode(Student(id));
}

void Database::addFaculty()
{
  // get id
  int id;
  while (true){
    id = demandType<int>("Please enter faculty member's ID(0 to exit): ","An integer is required...");
    if (id == 0)
      return;
    if (facultyTree.search(id)) // if the tree contains the faculty member already
    {
      cout << "Faculty member with that ID already exists, please choose another" << endl;
      continue;
    }
    break;
  }


    // get name
  string name = demandType<string>("Please enter faculty member's name: ","A string is required... How do you see this?");
    // get major
  string department = demandType<string>("Please enter faculty member's department: ","A string is required... How do you see this?");
    // get level
  string level;
  switch (choiceToInt("What is this faculty member's position?",departments,3))
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

  // create the faculty member
  facultyTree.insert(Faculty(id, name, level, department));
}

void Database::deleteFaculty()
{
  int choice; // 1 = delete advisees, 2 = migrate advisees
  string options[2] = {"Delete Advisees","Migrate to new faculty"};
  choice = choiceToInt("What would you like to do with the faculty member's advisees?",options,2);

  int id;
  while (true){
    id = demandType<int>("Please enter faculty member's ID to delete(0 to exit): ","An integer is required...");
    if (id == 0)
      return;
    if (!facultyTree.search(Faculty(id))) // if the tree does not contain the faculty member
    {
      cout << "Faculty member with that ID does not exist, please choose another" << endl;
      continue;
    }
    break;
  }

  Faculty* facultyPtr;
  facultyPtr = findFaculty(id);

  // perform the deletion

  if (choice == 1) // delete all the advisees
  {
    for (int i : facultyPtr->advisees)
    {
      studentTree.deleteNode(Student(i));
    }
  } else if (choice == 2) // migrate all advisees to new faculty member
  {
    int migrateid;
    while (true){
      migrateid = demandType<int>("Please enter faculty member's ID to migrate to(0 to exit): ","An integer is required...");
      if (id == 0)
        return;
      if (!facultyTree.search(Faculty(id))) // if the tree does not contain the faculty member
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
      migrateFaculty->advisees.push_back(i);
    }
  }
  facultyTree.deleteNode(Faculty(id));
}

void Database::updateStudentAdvisor()
{
    // target student and new advisor
    int studentid = pickStudent();
    if (studentid == 0)
      return;
    Student* studentPtr = findStudent(studentid);

    int facultyid = pickFaculty();
    if (facultyid == 0)
      return;
    Faculty* facultyPtr = findFaculty(facultyid);

    // remove student id from old faculty member
    Faculty* oldAdvisor = findFaculty(studentPtr->advisor);
    oldAdvisor->advisees.remove(studentid);

    // add student id to new faculty member
    facultyPtr->advisees.push_back(studentid);

    // change student's advisor id
    studentPtr->advisor = facultyid;
}

void Database::removeAdvisee()
{
    // target the faculty member
  int facultyid = pickFaculty();
  if (facultyid == 0)
    return;
  Faculty* facultyPtr = findFaculty(facultyid);

    // get the id of the student to delete
  int studentid;
  while (true)
  {
    cout << "Advisees: ";
    for(int s : facultyPtr->advisees)
      cout << s;
    cout << endl;
    studentid = demandType<int>("Please enter advisee's ID to delete(0 to exit): ","An integer is required...");
    if (studentid == 0)
      return;
    bool contains = false;
    for (int s : facultyPtr->advisees)
    {
      if (studentid == s)
        contains = true;
    }
    if (contains)
      break;
    else
      cout << "The student #" << studentid << " is not an advisee. Please try again" << endl;
  }
    // target the student
  Student* studentPtr = findStudent(studentid);

    // decide what to do with the student
  string options[2] = {"Delete","Migrate"};
  int choice = choiceToInt("What would you like to do with the advised student?",options,2);

    // execute the deletion
  if (choice == 1){ // delete the student
    facultyPtr->advisees.remove(studentid);
    studentTree.deleteNode(Student(studentid));
  } else if (choice == 2){ // migrate the student
    // get new faculty member
    int newFacultyid = pickFaculty();
    Faculty* newFacultyPtr = findFaculty(newFacultyid);

    // remove from old faculty, replace student's advisor, add to new faculty
    facultyPtr->advisees.remove(studentid);
    studentPtr->advisor = newFacultyid;
    newFacultyPtr->advisees.push_back(studentid);
  }
}
