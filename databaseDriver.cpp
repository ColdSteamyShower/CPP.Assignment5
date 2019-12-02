#include <iostream>
#include "Database.h"

using namespace std;

int main(){
  Database database;

  bool cont = true;
  string question = "------Database Menu------\nEnter number to select option:";
  string answers[] = {
    "Print all student information",
    "Print all faculty information",
    "Print student information from student ID",
    "Print faculty information from faculty ID",
    "Print advisor information from student ID",
    "Print advisee information from faculty ID",
    "Add a new student",
    "Delete a student by ID",
    "Add a new faculty member",
    "Delete a faculty member by ID",
    "Change a student advisor",
    "Remove an advisee from a faculty member",
    "Rollback",
    "Exit"};

  while (cont)
  {
    switch (choiceToInt(question,answers,14))
    {
      case 1:
        cout << "Printing all students" << endl;
        database.printStudents();
        break;
      case 2: // works
        cout << "Printing all faculty members" << endl;
        database.printFaculty();
        break;
      case 3:
        database.displayStudent();
        break;
      case 4:
        database.displayFaculty();
        break;
      case 5:
        database.studentToFaculty();
        break;
      case 6:
        database.facultyToStudents();
        break;
      case 7:
        database.addStudent();
        break;
      case 8:
        database.deleteStudent();
        break;
      case 9: // works
        database.addFaculty();
        break;
      case 10:
        database.deleteFaculty();
        break;
      case 11:
        database.updateStudentAdvisor();
        break;
      case 12:
        database.removeAdvisee();
        break;
      case 13:
        cout << "Rollback" << endl;
        break;
      case 14:
        cont = false;
        break;
      default:
        cout << "U wot?" << endl;
        break;
    }
  }
}
