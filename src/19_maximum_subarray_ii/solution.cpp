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
#include <numeric>
#include <functional>

#include "../../include/fileIO/fileIO.h"
#include "../../include/dataStructure/dataStructure.h"
#include "../../include/misc/misc.h"

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
		int n = nums.size();
		if (n <= 1)
			return 0;

		vector<int> leftMax(n), rightMax(n);
		// forward, max
		int sum = 0, minSum = 0, maxSum = INT_MIN;
		for (int i = 0; i < n; ++i) {
			sum += nums[i];
			maxSum = max(maxSum, sum - minSum);
			leftMax[i] = maxSum;
			minSum = min(minSum, sum);
		}
		// backward, max
		sum = 0; minSum = 0; maxSum = INT_MIN;
		for (int i = n-1; i >= 0; --i) {
			sum += nums[i];
			maxSum = max(maxSum, sum-minSum);
			rightMax[i] = maxSum;
			minSum = min(minSum, sum);
		}
		int result = INT_MIN;
		for (int i = 0; i < n - 1; ++i)
			result = max(result, leftMax[i] + rightMax[i+1]);
		return result;
    }
};

int main(int argc, char **argv)
{
	// initialization, data preparation
	vector<int> nums = {1, 3, -1, 2, -1, 2};
	// my solution
	Solution sln;
	auto result = sln.maxTwoSubArrays(nums);
	// correct answer

	return EXIT_SUCCESS;
}