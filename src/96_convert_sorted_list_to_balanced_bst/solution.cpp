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

class Solution
{
public:
  /*
     * @param head: The first node of linked list.
     * @return: a tree node
     */
  TreeNode *sortedListToBST(ListNode *head)
  {
    // write your code here
    if (head == nullptr)
      return NULL;
    vector<ListNode *> v;
    auto curr = head;
    while (curr != nullptr)
    {
      v.push_back(curr);
      curr = curr->next;
    }

    return partition(v, 0, v.size() - 1);
  }

  TreeNode *partition(const vector<ListNode *> &v, int beg, int end)
  {
    if (beg > end)
      return nullptr;
    // one point case
    if (beg == end)
    {
      return new TreeNode(v[beg]->val);
    }
    // number of points >= 2
    // partition, mid favors beg, meaning right branch might be longer than left branch
    int mid = beg + (end - beg) / 2;
    // mid pointer
    auto mid_p = new TreeNode(v[mid]->val);
    auto left_p = partition(v, beg, mid - 1);
    auto right_p = partition(v, mid + 1, end);

    mid_p->left = left_p;
    mid_p->right = right_p;

    return mid_p;
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