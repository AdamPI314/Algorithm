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

class Solution
{
  public:
	/**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
	int maxDiffSubArrays(vector<int> nums)
	{
		// write your code here
		// key point is how to find minimum subarray
		int n = nums.size();
		if (n <= 1)
			return 0;

		vector<int> leftMin(n), leftMax(n), rightMin(n), rightMax(n);
		// negative copy
		vector<int> copy(nums.begin(), nums.end());
		for (auto &x : copy)
			x *= -1;

		int sum = 0, minSum = 0, maxSum = INT_MIN;
		// forward, get max subarray
		for (int i = 0; i < n; ++i)
		{
			sum += nums[i];
			maxSum = max(maxSum, sum - minSum);
			leftMax[i] = maxSum;
			minSum = min(minSum, sum);
		}
		// backward, get max subarray
		sum = 0; minSum = 0; maxSum = INT_MIN;
		for (int i = n-1; i >= 0; --i) {
			sum += nums[i];
			maxSum = max(maxSum, sum - minSum);
			rightMax[i] = maxSum;
			minSum = min(minSum, sum);
		}
		// forward, get min subarray
		sum = 0; minSum = 0; maxSum = INT_MIN;
		for (int i = 0; i < n; ++i)
		{
			sum += copy[i];
			maxSum = max(maxSum, sum - minSum);
			leftMin[i] = -1*maxSum;
			minSum = min(minSum, sum);
		}
		// backward, get min subarray
		sum = 0; minSum = 0; maxSum = INT_MIN;
		for (int i = n-1; i >= 0; --i) {
			sum += copy[i];
			maxSum = max(maxSum, sum - minSum);
			rightMin[i] = -1*maxSum;
			minSum = min(minSum, sum);
		}
		
		int diff = 0;
		for (int i = 0; i < n-1; ++i) {
			diff = max(diff, max(abs(leftMax[i]-rightMin[i+1]), abs(rightMax[i+1]-leftMin[i])));
		}
		return diff;
	}
};

int main(int argc, char **argv)
{
	// initialization, data preparation
	vector<int> nums = {-5, -4};

	// my solution
	Solution sln;
	auto result = sln.maxDiffSubArrays(nums);

	// correct answer

	return EXIT_SUCCESS;
}
