// 2317839
// Ayden Best
// Class for holding two databases and handles all operations needed on the databases

#include <iostream>
#include "./Questioner/Questioner.h"
#include "./TemplateBST/BST.h"
#include "./Records/Faculty.h"
#include "./Records/Student.h"

class Database{
public:

  string levels[4] = {"Freshman","Sophomore","Junior","Senior"};
  string departments[3] = {"Lecturer","Assistant Professor","Associate Professor"};
  BST<Student> studentTree;
  BST<Faculty> facultyTree;


  Database(); // loads the databases from files, otherwise creates blank databases
  Database(const Database &d); // copy constructor for rollbacks
  ~Database();

  Student* findStudent(int id); // Return a pointer to the student with this id
  Faculty* findFaculty(int id); // return a pointer to the faculty with this id

  int pickStudent(); // ask the user to give the id of a valid
  int pickFaculty();

  void printStudents();
  void printFaculty();
  void displayStudent();
  void displayFaculty();
  void studentToFaculty();
  void facultyToStudents();
  void addStudent();
  void deleteStudent();
  void addFaculty();
  void deleteFaculty();
  void updateStudentAdvisor();
  void removeAdvisee();

  void save();

};
