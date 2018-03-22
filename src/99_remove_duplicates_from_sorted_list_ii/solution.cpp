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
  ListNode *deleteDuplicates(ListNode *head)
  {
    ListNode *root = NULL;
    ListNode **ppNext = &root;
    while (head)
    {
      // it is guaranteed current value is brand new value, this is a conditional assumption made here
      if (head->next == NULL || head->next->val != head->val)
      {
        *ppNext = head;
        ppNext = &(head->next);
        head = head->next;
      }
      else
      {
        int val = head->val;
        // until find a new value
        do
        {
          head = head->next;
        } while (head != NULL && head->val == val);
      }
    }
    *ppNext = NULL;
    return root;
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