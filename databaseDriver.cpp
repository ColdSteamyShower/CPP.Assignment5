#include <iostream>
#include "./TemplateBST/BST.h"

using namespace std;

int main(){
  BST<string> tree;

  tree.insert("help");
  tree.insert("lazer");
  tree.insert("teleport");
  tree.insert("AAA");
  tree.insert("Ayden");
  tree.insert("Rene");

  cout << "Example Tree:" << endl;
  tree.printTree();

  cout << "Max Value in Tree: " << tree.getMax()->key << endl;

  if (tree.deleteNode("Ayden"))
    cout << "[Deletion] Successfully deleted node containing 'Ayden'" << endl;
  else
    cout << "No node containing 'Ayden' found" << endl;

  cout << "New Tree:" << endl;
  tree.printTree();
}
