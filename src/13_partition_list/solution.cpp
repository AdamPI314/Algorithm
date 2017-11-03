#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>
#include <cstdlib>

#include "../../include/fileIO/fileIO.h"
#include "../../include/dataStructure/dataStructure.h"
#include "../../include/misc/misc.h"

using namespace std;
class Solution
{
public:
  /**
     * @param head: The first node of linked list.
     * @param x: an integer
     * @return: a ListNode 
     */
  ListNode *partition(ListNode *head, int x)
  {
    // write your code here
    if (head == nullptr || head->next == nullptr)
      return head;

    // at least two elements
    // put right after anchor
    ListNode *anchor = head;
    ListNode *pre_anchor = nullptr;
    if (head->val < x)
      anchor = head;
    // find the first val less than x
    // element before anchor
    else
    {
      pre_anchor = head;
      anchor = head->next;
      while (anchor != nullptr && anchor->val >= x)
      {
        anchor = anchor->next;
        pre_anchor = pre_anchor->next;
      }
    }
    // not value less than x
    if (anchor == nullptr)
      return head;

    // find one target, move to the beginning if it is not at the beginning
    if (anchor != head)
    {
      auto oldHead = head;
      auto newHead = anchor;

      pre_anchor->next = anchor->next;

      head = newHead;
      head->next = oldHead;
    }

    // where we were
    auto p1 = anchor;
    auto p2 = anchor->next;
    anchor = head;

    while (p2 != nullptr)
    {
      if (p2->val < x)
      {
        p1->next = p2->next;
        p2->next = anchor->next;
        anchor->next = p2;
        anchor = p2;
      }

      p1 = p2;
      p2 = p2->next;
    }

    return head;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  vector<int> in = {3, 3, 1, 2, 4};
  auto root = new ListNode(1);
  auto p = root;

  for (int i = 1; i < in.size(); ++i)
  {
    p->next = new ListNode(in[i]);
    p = p->next;
  }

  // my solution
  Solution sln;
  auto result = sln.partition(root, 3);

  // correct answer
  auto p1 = result;
  auto p2 = p1->next;
  while (p2 != nullptr)
  {
    delete p1;
    p1 = p2;
    p2 = p1->next;
  }

  return EXIT_SUCCESS;
}

