#include <iostream>
#include "../Database.h"
#include "ReaderWriter.h"
#include <fstream>
#include <list>

BST<Student> readStudentFile()
{
  BST<Student> newTree;
  ifstream input("Students.txt");
  if (!input)
  {
    return newTree;
  }

  int level = 0; // in order: ID, name, major, grade, gpa, advisor ID

  int id, aid;
  string name, major, grade;
  double gpa;

  string line;
  while (getline(input, line))
  {
    switch (level)
    {
      case 0: // ID
              id = stoi(line);
              ++level;
              break;
      case 1: // name
              name = line;
              ++level;
              break;
      case 2: // major
              major = line;
              ++level;
              break;
      case 3: // grade
              grade = line;
              ++level;
              break;
      case 4: // gpa
              gpa = stod(line);
              ++level;
              break;
      case 5: // Advisor ID
              aid = stoi(line);
              newTree.insert(Student(id,name,major,grade,gpa,aid));
              level = 0;
              break;
    }
  }
  input.close();
  return newTree;
}

BST<Faculty> readFacultyFile()
{
  {
    BST<Faculty> newTree;
    ifstream input("Faculty.txt");
    if (!input)
    {
      return newTree;
    }

    int level = 0; // in order: ID, name, position, department, advisees
    string line;
    int id;
    string name, pos, dep;
    list<int> advisees;
    while (getline(input, line))
    {
      if (line.empty())
      {
        newTree.insert(Faculty(id,name,pos,dep,advisees));
        level = 0;
        continue;
      }
      switch (level){
        case 0: // ID
                id = stoi(line);
                ++level;
                break;
        case 1: // name
                name = line;
                ++level;
                break;
        case 2: // position
                pos = line;
                ++level;
                break;
        case 3: // department
                dep = line;
                ++level;
                break;
        default:
                break;
      }
    }
    input.close();

    // we will take care of the student-advisor connections later, because we can do it the lazy way

    return newTree;
  }
}

string writeStudent(TreeNode<Student>* node, string str)
{
  if (node == NULL)
    return str;
  string newString;
  if (node->left != NULL)
    newString = writeStudent(node->left, str);


  Student s = node->key;
  newString += to_string(s.studentID) + "\n";
  newString += s.name + "\n";
  newString += s.major + "\n";
  newString += s.level + "\n";
  newString += to_string(s.gpa) + "\n";
  newString += to_string(s.advisor)+ "\n";


  if (node->right != NULL)
    newString = writeStudent(node->right, newString);

  return newString;
}

string writeFaculty(TreeNode<Faculty>* node, string str)
{
  if (node == NULL)
    return "";

  string newString;
  if (node->left != NULL)
    newString += writeFaculty(node->left, str);


  Faculty f = node->key;
  newString += to_string(f.facultyID) + "\n";
  newString += f.name + "\n";
  newString += f.level + "\n";
  newString += f.department + "\n";


  if (node->right != NULL)
    newString = writeFaculty(node->right, newString);

  return newString;
}

void writeFile(BST<Student>* sTree, BST<Faculty>* fTree)
{
  ofstream soutput("Students.txt");
  soutput << writeStudent(sTree->root, "");
  soutput.close();

  ofstream foutput("Faculty.txt");
  foutput << writeFaculty(fTree->root, "");
  foutput.close();

  cout << "Database files saved successfully" << endl;
}
