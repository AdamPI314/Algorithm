#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <forward_list>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <functional>
#include <iterator>

#include "../../include/fileIO/fileIO.h"
#include "../../include/dataStructure/dataStructure.h"
#include "../../include/misc/misc.h"

using namespace std;

// Definition of TreeNode:
class TreeNode
{
public:
  int val;
  TreeNode *left, *right;
  TreeNode(int val)
  {
    this->val = val;
    this->left = this->right = NULL;
  }
};

class Solution
{
  /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
  typedef vector<int>::iterator Iter;
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
  {
    // write your code here
    if (preorder.size() != inorder.size())
      return nullptr;
    if (preorder.size() == 0)
      return nullptr;

    TreeNode *root = nullptr;
    root = buildTreeTraversal(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());

    return root;
  }

  TreeNode *buildTreeTraversal(Iter pbegin, Iter pend, Iter ibegin, Iter iend)
  {
    if (pbegin == pend)
      return nullptr;
    int val = *(pbegin);

    Iter inorder_root = std::find(ibegin, iend, val);

    TreeNode *root = new TreeNode(val);

    root->left = buildTreeTraversal(pbegin + 1, pbegin + 1 + (inorder_root - ibegin), ibegin, ibegin + (inorder_root - ibegin));
    root->right = buildTreeTraversal(pend - (iend - inorder_root - 1), pend, inorder_root + 1, iend);

    return root;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation

  // my solution
  Solution sln;

  // correct answer

  return EXIT_SUCCESS;
}