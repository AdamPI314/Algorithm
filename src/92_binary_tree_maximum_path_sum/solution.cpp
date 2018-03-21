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

//  Definition of TreeNode:
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
  int max_sum = INT_MIN;

public:
  /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
  int maxPathSum(TreeNode *root)
  {
    // write your code here
    if (root == nullptr)
      return 0;

    backtrack(root);

    return this->max_sum;
  }

  // can only go left or right branch
  int backtrack(TreeNode *curr)
  {
    if (curr == nullptr)
      return 0;

    // guaranteed curr is not nullptr, left branch
    auto l = backtrack(curr->left);
    auto r = backtrack(curr->right);

    this->max_sum = std::max(this->max_sum, l + r + curr->val);

    // use only one branch, the larger branch
    auto sum_tmp = (l > r) ? (l + curr->val) : (r + curr->val);

    // return only one branch result
    if (sum_tmp > 0)
      return sum_tmp;
    else
      return 0;
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