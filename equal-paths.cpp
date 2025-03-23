#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
bool checkEqualPaths(Node* node, int depth, int& leafDepth)
{
  if(node == nullptr) return true;

  // if leaf
  if(node->left == nullptr && node->right == nullptr)
  {
    if(leafDepth == -1)
    {
      leafDepth = depth;
      return true;
    }
    return depth == leafDepth;
  }

  bool left = checkEqualPaths(node->left, depth + 1, leafDepth);
  bool right = checkEqualPaths(node->right, depth + 1, leafDepth);

  return (left && right);
}

bool equalPaths(Node * root)
{
    // Add your code below
    int leafDepth = -1;
    return checkEqualPaths(root, 0, leafDepth);
}

