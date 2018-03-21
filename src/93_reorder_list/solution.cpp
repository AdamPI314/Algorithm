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

// //  Definition of singly-linked-list:
// class ListNode
// {
// public:
//   int val;
//   ListNode *next;
//   ListNode(int val)
//   {
//     this->val = val;
//     this->next = NULL;
//   }
// };

class Solution
{
public:
  /**
     * @param head: The head of linked list.
     * @return: nothing
     */
  void reorderList(ListNode *head)
  {
    // write your code here
    // if (head == nullptr)
    //   return;
    vector<ListNode *> v;
    auto curr = head;
    while (curr != nullptr)
    {
      v.push_back(curr);
      curr = curr->next;
    }
    int n = v.size();
    if (n <= 1)
      return;

    curr = head;
    head->next = v.back();
    curr = head->next;

    for (size_t i = 1, j = n - 2; i <= j; ++i, --j)
    {
      curr->next = v[i];
      curr = curr->next;
      if (i < j)
      {
        curr->next = v[j];
        curr = curr->next;
      }
    } // for
    // finish up
    curr->next = nullptr;
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