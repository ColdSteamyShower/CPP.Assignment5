#include <iostream>
#include "./TemplateStack/GenStack.h"
#include "Database.h"

using namespace std;

int main(){
  Database database;
  GenStack<Database> rollbackCache;

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
    "Save and Exit"};

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
        rollbackCache.push(database);
        database.addStudent();
        break;
      case 8:
        rollbackCache.push(database);
        database.deleteStudent();
        break;
      case 9: // works
        rollbackCache.push(Database(database));
        database.addFaculty();
        break;
      case 10:
        rollbackCache.push(database);
        database.deleteFaculty();
        break;
      case 11:
        rollbackCache.push(database);
        database.updateStudentAdvisor();
        break;
      case 12:
        rollbackCache.push(database);
        database.removeAdvisee();
        break;
      case 13:
        try
        {
          rollbackCache.top().printFaculty();
          database = rollbackCache.pop();
          cout << "\nPrevious change to database has been reverted" << endl;
        } catch (GenStackEmptyException e)
        {
          cout << "\nThere are no operations left to rollback!" << endl;
        }
        break;
      case 14:
        database.save();
        cont = false;
        break;
      default:
        cout << "U wot?" << endl;
        break;
    }
  }
}
