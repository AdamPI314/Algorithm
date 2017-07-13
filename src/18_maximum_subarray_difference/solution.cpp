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

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
		int n = nums.size();
		if (n == 0)
			return 0;
		if (n == 1)
			return nums[0];

		int result;
		vector<vector<int> > sum(n, vector<int>(n, 0));

		// subarray includes at least one element
		for (int i = 0; i < n; ++i)
			sum[0][i] = nums[i];

		for (int i = 1; i < n; ++i) {
			for (int j = i; j < n; ++j ) {
								
			}
		}



		return result;
    }
};


int main(int argc, char **argv)
{
	// initialization, data preparation
	vector<int> nums = {1,2,-3,1};

	// my solution
	Solution sln;
	auto result = sln.maxDiffSubArrays(nums);

	// correct answer

	return EXIT_SUCCESS;
}