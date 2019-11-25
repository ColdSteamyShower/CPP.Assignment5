#include <iostream>

using namespace std;

template <typename T>
class TreeNode
{
private:


public:
  TreeNode();
  TreeNode(T k); // k = key, which in this example is also the value(data)
  ~TreeNode(); // when creating a template class, destructor must be virtual

  T key;
  TreeNode *left;
  TreeNode *right;

};

template <typename T>
TreeNode<T>::TreeNode(T k){
  key = k;
  left = NULL;
  right = NULL;
}

template <typename T>
TreeNode<T>::~TreeNode(){
  left = NULL;
  right = NULL;
}
