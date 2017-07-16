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
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here
		int result = 0;
		int n = S.size();
		if (n < 3)
			return result;

		// sort, n(log(n)) time
		sort(S.begin(), S.end());

		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				auto x1 = std::upper_bound(S.begin()+j+1, S.end(), abs(S[i] - S[j]));
				auto x2 = std::lower_bound(S.begin()+j+1, S.end(), S[i] + S[j]);
				if (S[x2 - S.begin()] >= S[i] + S[j] || x2 == S.end())
					--x2;	
				auto diff = x2 - x1 + 1;
				if (i >= (x1-S.begin()) && i <= (x2 - S.begin()))
					diff--;
				if (j >= (x1-S.begin()) && j <= (x2 - S.begin()))
					diff--;
				if (diff > 0)
					result += diff;
			}
		}

		return result;
    }
};


int main(int argc, char **argv)
{
	// initialization, data preparation
	vector<int> nums = {8990,3146,9568,3889,7253,7395,10032,6179,1299,8738,1315,1280,830,6593};
	// my solution
	Solution sln;
	auto result = sln.triangleCount(nums);
	// correct answer

	return EXIT_SUCCESS;
}