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

// class ListNode
// {
// public:
// int val;
// ListNode *next;
//
// ListNode(int val)
// {
// this->val = val;
// this->next = NULL;
// }
// };

class Solution
{
public:
  /*
     * @param head: n
     * @return: The new head of reversed linked list.
     */
  ListNode *reverse(ListNode *head)
  {
    // write your code here
    if (head == nullptr)
      return nullptr;
    ListNode *previous = nullptr;
    ListNode *following = nullptr;
    while (head != nullptr)
    {
      following = head->next;
      head->next = previous;
      previous = head;
      head = following;
    }
    return previous;
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