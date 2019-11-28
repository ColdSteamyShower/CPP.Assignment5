// 2317839
// Ayden Best
// Class for holding two databases and handles all operations needed on the databases

#include <iostream>
#include "Questioner.h"
#include "./TemplateBST/BST.h"
#include "./Records/Faculty.h"
#include "./Records/Students.h"

class Database{
private:

  BST<Student> studentTree;
  BST<Faculty> facultyTree;

public:

  Database(); // loads the databases from files, otherwise creates blank databases
  ~Database();

  Student* findStudent(int id);
  Faculty* findFaculty(int id);

  void printStudents();
  void printFaculty();
  void displayStudent(int id);
  void displayFaculty(int id);
  void studentToFaculty();
  void facultyToStudents();
  void addStudent();
  void deleteStudent();
  void addFaculty();
  void deleteFaculty();
  void updateStudentAdvisor();
  void removeAdvisee();

};
