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
  /**
     * @param head: head is the head of the linked list
     * @return: head of linked list
     */
  ListNode *deleteDuplicates(ListNode *head)
  {
    // write your code here
    if (head == nullptr)
      return nullptr;
    vector<ListNode *> v;
    auto curr = head;
    while (curr != nullptr)
    {
      if (v.size() > 0 && v.back()->val == curr->val)
      {
        auto x = curr;
        curr = curr->next;
        // free the memory
        delete x;
        continue;
      }
      v.push_back(curr);
      curr = curr->next;
    }

    if (v.size() <= 0)
      return nullptr;

    head = v.front();
    curr = head;
    for (int i = 1; i < v.size(); ++i)
    {
      curr->next = v[i];
      curr = curr->next;
    }
    // finish up
    curr->next = nullptr;

    return head;
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