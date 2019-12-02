

BST<Student> readStudentFile();
// reads from the student file

BST<Faculty> readFacultyFile();
// reads from the faculty file

void writeFile(BST<Student> sTree, BST<Faculty> fTree);
//writes student and faculty trees to file

void writeStudent(TreeNode<Student>* node, ofstream stream);
// writes the student's children and itself to file

void writeFaculty(TreeNode<Faculty>* node, ofstream stream);
// writes the faculty's children and itself to file

void writeFile(BST<Student>* sTree, BST<Faculty>* fTree);
 // writes students and faculty of trees to file
