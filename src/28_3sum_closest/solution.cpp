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
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
	int threeSumClosest(vector<int> nums, int target)
	{
		// write your code here
		int n = nums.size();
		if (n < 3)
			return 0;
		// O(nlog(n))
		sort(nums.begin(), nums.end());
		int result = nums[0] + nums[1] + nums[2];

		for (int i = 0; i < n; ++i)
		{
			int start = i + 1, end = n - 1;
			while(start < end)
			{
				int tmp = nums[i] + nums[start] + nums[end];
				if (abs(tmp - target) < abs(result - target))
					result = tmp;
				if (tmp < target)
					++start;
				else
					--end;
			}
		}

		return result;
	}
};

int main(int argc, char **argv)
{
	// initialization, data preparation
	vector<int> nums = {-2, -3, -4, -5, -100, 99, 1, 4, 4, 4, 5, 1, 0, -1, 2, 3, 4, 5};
	int target = 77;
	// my solution
	Solution sln;
	auto result = sln.threeSumClosest(nums, target);
	// correct answer

	return EXIT_SUCCESS;
}