#include <iostream>
#include <sstream>
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
public:
  /**
     * This method will be invoked first, you should design your own algorithm
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */

  string serialize(TreeNode *root)
  {
    // write your code here
    if (root == nullptr)
      return std::string("{}");

    // use dynamical array
    std::vector<TreeNode *> myv;
    myv.push_back(root);

    for (int i = 0; i < myv.size(); ++i)
    {
      // array will dynamical expanding, until ...
      if (myv[i] == nullptr)
        continue;
      // push_back both left and right, no matter what, placeholder if they are nullptr
      myv.push_back(myv[i]->left);
      myv.push_back(myv[i]->right);
    }

    // get rid of nullptr in the end
    while (myv.back() == nullptr)
    {
      myv.pop_back();
    }

    // convert to string
    std::stringstream ss;
    ss << "{" << myv[0]->val;
    for (std::size_t i = 1; i < myv.size(); ++i)
    {
      if (myv[i] == nullptr)
        ss << ",#";
      else
        ss << "," << myv[i]->val;
    }
    ss << "}";
    return ss.str();
  }

  /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     */
  TreeNode *deserialize(string data)
  {
    // write your code here
    TreeNode *root = nullptr;
    if (data == "{}")
      return nullptr;

    // split data by delimiter ','
    std::vector<std::string> dstr = split(data.substr(1, data.size() - 2), ',');
    root = new TreeNode(std::stoi(dstr[0]));

    // to keep track of who is the next needs children
    std::queue<TreeNode *> myq;
    myq.push(root);

    TreeNode *p = nullptr;
    for (std::size_t i = 1; i < dstr.size(); ++i)
    {
      if (i % 2 == 1)
      {
        p = myq.front();
        myq.pop();
        // left children
        if (dstr[i] != "#")
        {
          p->left = new TreeNode(std::stoi(dstr[i]));
          myq.push(p->left);
        }
        // otherwise it will be the same pointer
      }
      else
      {
        if (dstr[i] != "#")
        {
          p->right = new TreeNode(std::stoi(dstr[i]));
          myq.push(p->right);
        }
      }
    }
    return root;
  }

  // it is guaranteed outside, the input string is good
  std::vector<std::string> split(std::string str, char del)
  {
    std::vector<std::string> ans;
    std::size_t beg_idx = 0, token_idx = 0;
    while (beg_idx < str.size() && token_idx != std::string::npos)
    {
      token_idx = str.find(del, beg_idx);
      if (beg_idx != std::string::npos)
      {
        ans.push_back(str.substr(beg_idx, token_idx - beg_idx));
        beg_idx = token_idx + 1;
      }
    }

    return ans;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  std::string in = "1,2,#,3";
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.split(in, ',');
  return EXIT_SUCCESS;
}