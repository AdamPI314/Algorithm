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
     * @param nums: an array of integer
     * @param target: an integer
     * @return: an integer
     */
	int twoSum2(vector<int> &nums, int target)
	{
		// Write your code here
		int n = nums.size();
		if (n <= 1)
			return 0;
		int result = 0;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n - 1; ++i)
		{
			auto f = std::upper_bound(nums.begin() + i + 1, nums.end(), target - nums[i]);
            result += n - (f - nums.begin());

		}
		return result;
	}
};

int main(int argc, char **argv)
{
	// initialization, data preparation
	vector<int> nums = {1, 0, -1};
	int k = 1;
	// vector<int> nums;
	// int k;
	// fileIO::vector_int("./input.in", nums, k);
	// my solution
	Solution sln;
	auto result = sln.twoSum2(nums, k);

	// correct answer

	return EXIT_SUCCESS;
}