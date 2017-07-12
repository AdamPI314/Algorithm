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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
	ListNode *detectCycle(ListNode *head)
	{
		// write your code here
		if (head == nullptr || head->next == nullptr)
			return nullptr;
		if (head->next == head)
			return head;
		set<ListNode *> hash;
		hash.insert(head);
		head = head->next;

		while (head != nullptr)
		{
			auto it = hash.find(head);
			if (it != hash.end())
				return *it;
			hash.insert(head);
			head = head->next;
		}

		return nullptr;
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