#include <iostream>
#include "TreeNode.h"

using namespace std;

template <typename T>
class BST{
public:
  TreeNode<T> *root;


  BST();
  ~BST();

  bool search(T value); // returns true if the value exists in the tree
  TreeNode<T>* access(T value); // accesses the requested value. Returns NULL pointer if it does not exist
  void insert(T value);

  bool deleteNode(T value);

  // helper function
  bool isEmpty();
  TreeNode<T>* getMin();
  TreeNode<T>* getMax();

  void printTree();
  void recPrint(TreeNode<T> *node);

  TreeNode<T>* getSuccessor(TreeNode<T> *d);
};

template <typename T>
BST<T>::BST(){
root = NULL; // empty Tree
}

template <typename T>
BST<T>::~BST(){

}

template <typename T>
void BST<T>::recPrint(TreeNode<T> *node)
{
  if(node == NULL)
    return;

  cout << node->key << endl;
  recPrint(node->left);
  recPrint(node->right);
}

template <typename T>
void BST<T>::printTree(){
  recPrint(root);
}

template <typename T>
TreeNode<T>* BST<T>::getMax(){
  TreeNode<T> *current = root;

  if(root == NULL) // empty tree
    return NULL;

  while(current->right != NULL)
  {
    current = current->right;
  }

  return (current);
}

template <typename T>
TreeNode<T>* BST<T>::getMin(){
  TreeNode<T> *current = root;

  if(root == NULL) // empty tree
    return NULL;

  while(current->left != NULL)
  {
    current = current->left;
  }

  return (current);
}

template <typename T>
void BST<T>::insert(T value){

  TreeNode<T> *node = new TreeNode<T>(value);

  if (root==NULL)
  { // empty tree
    root = node;
  }
  else
  { // non-empty tree, lets find insertion location
    TreeNode<T> *current = root;
    TreeNode<T> *parent = NULL;

    while (true){
      parent = current;

      if (value < current->key){ // go to left
        current = current->left;
        if (current == NULL){ // insertion point found
          parent->left = node;
          break;
        }
      }
      else if (value > current->key){ // go to right
        current = current->right;
        if (current == NULL){ // insertion point found
          parent->right = node;
          break;
        }
      }
    }
  }
}

template <typename T>
bool BST<T>::search(T value){

  if (root==NULL){
    return false;
  }else{
    // tree is not empty, let's attempt to look for it
    TreeNode<T> *current = root;
    while (current->key != value){
      if(value < current->key)
        current = current->left;
      else
        current = current->right;

      if(current == NULL) // we did not find the value
        return false;
    }
  }
  return true;
}

template <typename T>
TreeNode<T>* BST<T>::access(T value){

  TreeNode<T>* current;

  if (root==NULL){
    return NULL;
  }else{
    // tree is not empty, let's attempt to look for it
    current = root;
    while (current->key != value){
      if(value < current->key)
        current = current->left;
      else
        current = current->right;

      if(current == NULL) // we did not find the value
        return NULL;
    }
  }
  return current;
}

template <typename T>
bool BST<T>::deleteNode(T value){

  if (root == NULL)
    return false;

  TreeNode<T> *current = root;
  TreeNode<T> *parent = root;
  bool isLeft = true;

  // look for the node
  while (current->key != value){
    parent = current;
    if(value < current->key)
    {
      current = current->left;
      isLeft = true;
    }
    else
    {
      current = current->right;
      isLeft = false;
    }

    if(current == NULL) // we did not find the value
      return false;
  }

  // At this point, we've found the node that needs to be deleted
  // check for different cases

  // no children
  if(current->left == NULL && current->right == NULL){
    if(current == root){
      root = NULL;
    } else if (isLeft){
      parent->left = NULL;
    } else if (!isLeft){
      parent->right = NULL;
    }
  }

  // node has children, we need to determine if child is left or right to proceed
  else if (current->right == NULL) // has no right child
  {
    if (current == root)
    {
      root = current->left;
    }
    else if (isLeft)
    {
      parent->left = current->left;
    }
    else
    {
      parent->right = current->left;
    }
  }

  else if (current->left == NULL) // has no left child
  {
    if (current == root){
      root = current->right;
    } else if (isLeft){
      parent->left = current->right;
    } else {
      parent->right = current->right;
    }
  }

  // the node has 2 children... oh no
  else
  {
    TreeNode<T> *successor = getSuccessor(current);

    if(current == root)
      root = successor;
    else if (isLeft)
      parent->left = successor;
    else
      parent->right = successor;

    successor->left = current->left;
  }
  return true;
}

template <typename T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d)// d is the node to be deleted
{
  TreeNode<T> *sp = d; // sp is the successor's parent and is initialized to d
  TreeNode<T> *successor = d;
  TreeNode<T> *current = d->right; // start one right
                                // because value to replace current must be greater than left, and all right > left

  while(current != NULL) // one right all the way left
  {
    sp = successor;
    successor = current;
    current = current->left;
  }

  if(successor != d->right){
    //successor is a descendant of the right child
    sp->left = successor->right;
    successor->right = d->right;
  }
}
