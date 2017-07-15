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
	/*
     * @param nums an array of Integer
     * @param target an integer
     * @return [index1 + 1, index2 + 1] (index1 < index2)
     */
	vector<int> twoSum7(vector<int> &nums, int target)
	{
		// write your code here
		vector<int> result;
		int n = nums.size();
		if (n <= 1)
			return result;

		map<int, int> hash;
		for (int i = 0; i < n; ++i) {
			if (hash.find(nums[i]) != hash.end() && target == 0)
			{
				result.push_back(hash[nums[i]]);
				result.push_back(i+1);
				return result;
			}
			hash.emplace(nums[i], i + 1);
		}

		for (int i = 0; i < n / 2 + 1; ++i)
		{
			if (hash.find(nums[i] - target) != hash.end())
			{
				result.push_back(min(hash[nums[i] - target], i + 1));
				result.push_back(max(hash[nums[i] - target], i + 1));
				return result;
			}
			if (hash.find(target + nums[i]) != hash.end())
			{
				result.push_back(min(hash[target + nums[i]], i + 1));
				result.push_back(max(hash[target + nums[i]], i + 1));
				return result;
			}
		}
		return result;
	}
};

int main(int argc, char **argv)
{
	// initialization, data preparation
	vector<int> nums = {2, 7, 15, 24};
	// my solution
	Solution sln;
	auto result = sln.twoSum7(nums, 5);

	// correct answer

	return EXIT_SUCCESS;
}