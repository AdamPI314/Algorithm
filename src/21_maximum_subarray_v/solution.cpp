#include<iostream>
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
     * @param nums an array of integers
     * @param k1 an integer
     * @param k2 an integer
     * @return the largest sum
     */
	int maxSubarray5(vector<int> &nums, int k1, int k2)
	{
		// Write your code here
		if (k1 > k2)
			return 0;
		int n = nums.size();
		if (n < k1)
			return 0;
		if (n == 1 && n >= k1)
			return nums[0];
		vector<int> sum(nums.begin(), nums.end());
		for (int i = 1; i < n; ++i)
		{
			sum[i] += sum[i - 1];
		}

		k1 = (k1 >= 0 ? k1 : 0);
		k2 = (k2 <= n ? k2 : n);

		multiset<int> pre_min;
		for (int i = 0; i < k2-k1+1; ++i)
			pre_min.insert(0);

		int min_tmp = 0, maxSum = INT_MIN;
		for (int i = 0; i + k1 - 1 < n; ++i)
		{
			min_tmp = (*pre_min.begin());
			maxSum = max(maxSum, sum[i + k1 - 1] - min_tmp);


			if (i-k2+k1 >= 0)
			{
				pre_min.erase(pre_min.find(sum[i-k2+k1]));
				pre_min.insert(sum[i]);
			}
		}

		return maxSum;
	}
};

int main(int argc, char **argv)
{
	// initialization, data preparation
	vector<int> nums = {-1, -2, -3, -100, -1, -50};
	int k1 = 4, k2 = 6;

	// my solution
	Solution sln;
	auto result = sln.maxSubarray5(nums, k1, k2);
	// correct answer

	return EXIT_SUCCESS;
}