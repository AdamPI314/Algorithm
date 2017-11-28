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
     * @param head: ListNode head is the head of the linked list 
     * @param m: An integer
     * @param n: An integer
     * @return: The head of the reversed ListNode
     */
  ListNode *reverseBetween(ListNode *head, int m, int n)
  {
    // write your code here
    int counter = 1;

    ListNode *root1 = head;
    ListNode *root2 = nullptr;

    while (counter++ < m)
    {
      root2 = head;
      head = head->next;
    }
    ListNode *tail1 = nullptr;
    tail1 = head;

    ListNode *preceding = nullptr;
    ListNode *following = nullptr;
    while (head != nullptr && counter++ <= n + 1)
    {
      following = head->next;
      head->next = preceding;
      preceding = head;
      head = following;
    }

    // has a tail afterwards
    if (head != nullptr)
      tail1->next = head;
    if (m == 1)
      return preceding;
    // original head is still head
    if (m > 1)
    {
      root2->next = preceding;
      return root1;
    }
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