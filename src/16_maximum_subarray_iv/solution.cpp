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
     * @param nums an array of integers
     * @param k an integer
     * @return the largest sum
     */
	int maxSubarray4(vector<int> &nums, int k)
	{
		// Write your code here
		if (k > nums.size() || k == 0)
			return 0;
		if (nums.size() == 1)
			return nums[0];

		int result = INT_MIN;

		vector<int> sum(nums.begin(), nums.end());
		// integral, O(n)
		for (int i = 1; i < sum.size(); ++i)
			sum[i] += sum[i - 1];

		// find minimum all valid points before current point
		// index of previous minimum, k steps before
		int pre_min = 0;
		for (int i = 0; i < sum.size(); ++i)
		{
			// update index of previous minimum
			if (i < k - 1)
				pre_min = 0;
			else
			{
				pre_min = (sum[i - k + 1] - nums[i - k + 1] < sum[pre_min] - nums[pre_min]) ? i - k + 1 : pre_min;
				result = max(result, sum[i] - sum[pre_min] + nums[pre_min]);
				// pre_min = ( sum[i-k+1]-nums[i-k+1] < sum[pre_min]-nums[pre_min] ) ? i-k+1 : pre_min;
			}
		}

		return result;
	}
};

int main(int argc, char **argv)
{
	// initialization, data preparation
	vector<int> nums = {-5, 15};

	// my solution
	Solution sln;

	auto result = sln.maxSubarray4(nums, 1);

	// correct answer

	return EXIT_SUCCESS;
}

