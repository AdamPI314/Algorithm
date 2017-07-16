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
		vector<int> tmp;

		int k = target / 3;
		// O(log(n))
		int x1 = lower_bound(nums.begin(), nums.end(), k) - nums.begin();
		int x2 = upper_bound(nums.begin(), nums.end(), k) - nums.begin();
		// gonna be a circle
		for (int i = -3; i < 3; ++i)
		{
			int ind = x1 + i;
			tmp.push_back(nums[(ind)%n] + nums[(ind+1)%n] + nums[(ind+2)%n]);
		}
		for (int i = -3; i < 3; ++i)
		{
			int ind = x2 + i;
			tmp.push_back(nums[(ind)%n] + nums[(ind+1)%n] + nums[(ind+2)%n]);
		}
		// one more search O(log(n))
				

		// return closest to target
		return *min_element(tmp.begin(), tmp.end(),
							[target](const int x1, const int x2) -> bool { return abs(x1 - target) < abs(x2 - target); });
	}
};

int main(int argc, char **argv)
{
	// initialization, data preparation
	vector<int> nums = {-2,-3,-4,-5,-100,99,1,4,4,4,5,1,0,-1,2,3,4,5};
	int target = 77;
	// my solution
	Solution sln;
	auto result = sln.threeSumClosest(nums, target);
	// correct answer

	return EXIT_SUCCESS;
}