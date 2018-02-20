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

// binary search tree
struct TreeNode
{
  int val = 0;
  TreeNode *left = nullptr;
  TreeNode *right = nullptr;

  TreeNode(int val)
  {
    this->val = val;
  }
};

class Solution
{
public:
  /*
     * @param inorder: A list of integers that inorder traversal of a tree
     * @param postorder: A list of integers that postorder traversal of a tree
     * @return: Root of a tree
     */
  typedef vector<int>::iterator Iter;

  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
  {
    // write your code here
    TreeNode *root = nullptr;

    if (inorder.size() != postorder.size())
      return root;
    int n = inorder.size();
    if (n == 0)
      return root;

    // use the fact that to post order traversal, left->right->middle, the most right element is the root
    // also, should use recursive algorithm
    // besides, to in order traversal, left->middle->right, left node, middle node and right value, there index shall be contigent
    root = buildTreeTraversal(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    return root;
  }

  TreeNode *buildTreeTraversal(Iter ibegin, Iter iend, Iter pbegin, Iter pend)
  {
    if (ibegin == iend)
      return nullptr;
    // the right most value shall be the root
    TreeNode *root = new TreeNode(*(pend - 1));

    Iter ibegin_root = std::find(ibegin, iend, *(pend - 1));
    root->left = buildTreeTraversal(ibegin, ibegin_root, pbegin, pbegin + (ibegin_root - ibegin));
    root->right = buildTreeTraversal(ibegin_root + 1, iend, pbegin + (ibegin_root - ibegin), pend - 1);

    return root;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  vector<int> inorder = {1, 2, 3};
  vector<int> postorder = {1, 3, 2};
  // my solution
  Solution sln;
  auto x = sln.buildTree(inorder, postorder);

  // correct answer

  return EXIT_SUCCESS;
}