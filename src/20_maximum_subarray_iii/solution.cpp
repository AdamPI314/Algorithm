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
			for (int j = i + 1; j <= n; j++)
			{
				// what f[i][j] is tracking here? max i sub-intervals, j numbers
				if (f[i][j - 1] < p[i - 1][j - 1])
				{
					f[i][j] = p[i - 1][j - 1] + nums[j - 1];
				}
				else
				{
					f[i][j] = f[i][j - 1] + nums[j - 1];
				}
				sum = max(sum, f[i][j]);
				p[i][j] = sum;
			}
		}
		int result = INT_MIN;
		for (int i = k; i <= n; i++)
		{
			result = max(result, f[k][i]);
		}
		return result;
	}
};

int main(int argc, char **argv)
{
	// initialization, data preparation
	vector<int> nums;
	int k;
	fileIO::vector_int("./input.in", nums, k);

	// my solution
	Solution sln;
	auto result = sln.maxSubArray(nums, k);

	// correct answer

	return EXIT_SUCCESS;
}
