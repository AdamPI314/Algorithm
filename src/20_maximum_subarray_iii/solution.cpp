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
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
	int maxSubArray(vector<int> nums, int k)
	{
		const int n = nums.size();
		vector<vector<int>> f(k + 1, vector<int>(n + 1));
		vector<vector<int>> p(k + 1, vector<int>(n + 1));
		int sum;
		for (int i = 1; i <= k; i++)
		{
			sum = INT_MIN;
			// the diagonal element of f[i][i] is the integral up to nums[i-1], same to p[i][i]
			f[i][i] = f[i - 1][i - 1] + nums[i - 1];
			p[i][i] = f[i][i];
			sum = f[i][i];
			// i sub-intervals, at least i numbers, but i number is handled already, so j = i+1
			for (int j = i + 1; j <= n; j++)
			{
				// p is global, correct answer with i sub-intervals, j numbers
				// what f[i][j] is tracking here? max i sub-intervals, j numbers
				// it seems j[i][j] represents, max, i sub-intervals, j numbers,
				// the last intervals must contains nums[j-1] 
				if (f[i][j - 1] < p[i - 1][j - 1])
				{
					// current number, nums[j-1], as a individual intervals
					f[i][j] = p[i - 1][j - 1] + nums[j - 1];
				}
				else
				{
					// current number, nums[j-1], not as a individual intervals, 
					// but append to last interval of f[i][j-1] since the last interval of f[i][j-1] 
					// must contains nums[j-2]
					// so, f[i][j] always including current number, nums[j-1]
					f[i][j] = f[i][j - 1] + nums[j - 1];
				}
				sum = max(sum, f[i][j]);
				p[i][j] = sum;
			}
		}
		return p[k][n];
	}
};

int main(int argc, char **argv)
{
	// initialization, data preparation
	// vector<int> nums;
	// int k;
	// fileIO::vector_int("./input.in", nums, k);

	vector<int> nums = {1, 3, -100, 1};
	int k = 1;

	// my solution
	Solution sln;
	auto result = sln.maxSubArray(nums, k);

	// correct answer

	return EXIT_SUCCESS;
}
