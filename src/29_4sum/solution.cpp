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

class Solution
{
  public:
	/**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
	vector<vector<int>> fourSum(vector<int> nums, int target)
	{
		// write your code here
		vector<vector<int>> result;
		int n = nums.size();
		if (n < 4)
			return result;

		sort(nums.begin(), nums.end());
		for (int i = 0; i < n; ++i)
		{
			if (i > 0)
				i = upper_bound(nums.begin() + i - 1, nums.end(), nums[i - 1]) - nums.begin();
			for (int j = i + 1; j < n; ++j)
			{
				if (j > i + 1)
					j = upper_bound(nums.begin() + j - 1, nums.end(), nums[j - 1]) - nums.begin();
				int start = j + 1, end = n - 1;
				int tmp1 = nums[i] + nums[j] - target;
				while (start < end)
				{
					int tmp2 = tmp1 + nums[start] + nums[end];
					if (tmp2 == 0)
					{
						result.push_back(vector<int>{nums[i], nums[j], nums[start], nums[end]});

						start = upper_bound(nums.begin() + start, nums.begin() + end, nums[start]) - nums.begin();
						end = lower_bound(nums.begin() + start, nums.begin() + end + 1, nums[end]) - nums.begin() - 1;
					}
					else if (tmp2 > 0)
						end = lower_bound(nums.begin() + start, nums.begin() + end, nums[end]) - nums.begin() - 1;
					else
						start = upper_bound(nums.begin() + start, nums.begin() + end + 1, nums[start]) - nums.begin();
				}
			}
		}
		return result;
	}
};

int main(int argc, char **argv)
{
	// initialization, data preparation
	vector<int> nums = {1, 0, -1, -1, -1, -1, 0, 1, 1, 1, 2};
	int target = 2;
	// my solution
	Solution sln;
	auto result = sln.fourSum(nums, target);

	// correct answer

	return EXIT_SUCCESS;
}