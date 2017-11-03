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
     * @param nums: a vector of integers
     * @return: an integer
     */
	int maxProduct(vector<int> &nums)
	{
		// write your code here
		if (nums.size() <= 0)
			return 0;
		if (nums.size() == 1)
			return nums[0];

		int result = INT_MIN;

		int ind = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] != 0)
				continue;
			else
			{
				if (ind <= i - 1)
					result = max(nonZeroProduct(nums, ind, i - 1), result);
				ind = i + 1;
			}
		}
		if (ind < nums.size())
			result = max(nonZeroProduct(nums, ind, nums.size() - 1), result);

		return result;
	}

	int nonZeroProduct(vector<int> &nums, int begin, int end)
	{
		// notice here end >= begin
		if (begin == end)
			return nums[begin];
		if (begin + 1 == end)
			return max(nums[begin] * nums[end], max(nums[begin], nums[end]));

		// at least three elements
		vector<int> product(nums.begin() + begin, nums.begin() + end + 1);
		for (int i = 1; i < product.size(); ++i)
		{
			product[i] *= product[i - 1];
		}

		// first positive or first negative
		map<int, int> hash;
		hash[1] = 1;

		int result = product[0];
		for (int i = 1; i < product.size(); ++i)
		{
			int v = product[i]/nums[begin+i];
			if (v < 0 && hash.find(-1) == hash.end())
				hash[-1] = v;
				
			if (product[i] > 0)
			    result = max(result, product[i] / hash[1]);

			if (product[i] < 0 && hash.find(-1) != hash.end())
			    result = max(result, product[i] / hash[-1]);			    

		}

		return result;
	}
};

int main(int argc, char **argv)
{
	// initialization, data preparation
	vector<int> nums = {-3,-1,3,5,-6,-6,-1,6,-3,-5,1,0,-6,-5,0,-2,6,1,0,5};

	// my solution
	Solution sln;
	auto result = sln.maxProduct(nums);

	// correct answer

	return EXIT_SUCCESS;
}
