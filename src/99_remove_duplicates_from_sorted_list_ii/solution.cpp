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
     * @return: head of the linked list
     */
  ListNode *deleteDuplicates(ListNode *head)
  {
    // write your code here
    if (head == nullptr)
      return nullptr;

    auto comp = [](ListNode *p1, ListNode *p2) { return p1->val < p2->val; };
    unordered_map<ListNode *, int, decltype(comp)> myM;
    vector<ListNode *> v;

    auto curr = head;
    while (curr != nullptr)
    {
      // check whether it appears before or not
      myM[curr] += 1;
      curr = curr->next;
    }
    curr = head;
    ListNode *n_head = nullptr, *n_curr = nullptr;
    while (curr != nullptr)
    {
      // it is a good one
      if (myM.at(curr) == 1)
      {
        if (n_head == nullptr)
        {
          n_head = curr;
          n_curr = n_head;
        }
        else
        {
          n_curr->next = curr;
          n_curr = n_curr->next;
        }
        curr = curr->next;
      } //if
      else
      {
        // free the memory
        auto x = curr;
        curr = curr->next;
        delete x;
      } //else
    }

    return n_head;
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