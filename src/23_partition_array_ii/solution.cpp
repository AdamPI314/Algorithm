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

class Solution {
public:
    /**
     * @param nums an integer array
     * @param low an integer
     * @param high an integer
     * @return nothing
     */
    void partition2(vector<int>& nums, int low, int high) {
        // Write your code here
		if (nums.size() <= 1)
			return;

		int cur_index = 0;
		int low_index = 0, high_index = nums.size() - 1;

		for (; cur_index <= high_index; )
		{
			if (nums[cur_index] > high)
				swap(nums[cur_index], nums[high_index--]);
			else if (nums[cur_index] < low)	
				swap(nums[cur_index++], nums[low_index++]);
			else
				++cur_index;
		}
    }
};


int main(int argc, char **argv)
{
	// initialization, data preparation
	vector<int> nums = {4,3,4,1,2,3,1,2};
	int low = 2, high = 3;
	// my solution
	Solution sln;
	sln.partition2(nums, low, high);

	// correct answer

	return EXIT_SUCCESS;
}