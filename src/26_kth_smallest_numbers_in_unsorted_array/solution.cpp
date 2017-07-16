#include <iostream>
#include <vector>
#include <list>
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
#include <numeric>
#include <functional>

#include "../../include/fileIO/fileIO.h"
#include "../../include/dataStructure/dataStructure.h"
#include "../../include/misc/misc.h"

using namespace std;

class Solution {
public:
    /*
     * @param k an integer
     * @param nums an integer array
     * @return kth smallest element
     */
    int kthSmallest(int k, vector<int> nums) {
        // write your code here
		int result = 0;
		int n = nums.size();
		if (k > n)
			return 0;
		// use priority_queue, pop the first-k element (n + klog(n))
		// create priority_queue O(n)
		// pop(), O(log(n))
		priority_queue<int, vector<int>, greater<int> > pq(nums.begin(), nums.end());
		for (int i = 0; i < k; ++i)
		{
			result = pq.top();
			pq.pop();
		}

		return result;
		
    }
};

int main(int argc, char **argv)
{
	// initialization, data preparation
	vector<int> nums = {3, 4, 1, 2};
	int k = 3;
	// my solution
	Solution sln;
	auto result = sln.kthSmallest(k, nums);
	// correct answer

	return EXIT_SUCCESS;
}