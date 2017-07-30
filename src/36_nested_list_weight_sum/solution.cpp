#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
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

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer,
    // rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds,
    // if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds,
    // if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
public:
    int depthSum(const vector<NestedInteger>& nestedList) {
        // Write your code here
		int sum = 0;
		for (auto x : nestedList)
			sum += helper(x, 1);
		return sum;
    }

	int helper(const NestedInteger &nestedList, int level) {
		// return condition
		// holds a single integer
		int sum = 0;
		if (nestedList.isInteger())
		{
			cout << nestedList.getInteger() << endl;
			return level*nestedList.getInteger();
		}
		else {
			for (auto x : nestedList.getList())
				sum += helper(x, level + 1);
		}
		return sum;
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