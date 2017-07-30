#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>
#include <stack>
#include <forward_list>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <functional>
#include <iterator>

#include "../../include/fileIO/fileIO.h"
#include "../../include/dataStructure/dataStructure.h"
#include "../../include/misc/misc.h"

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        // write you code here
		int n = num.size();
		if (n == 1)
			return 1;

		sort(num.begin(), num.end());
		int maxLen = 1;
		int currLen = 1;
		for (int i = 1; i < n; ++i)
		{
			if (num[i] == num[i-1])
				continue;
			if (num[i] == num[i-1] + 1)
			{
				++currLen;
				maxLen = (currLen>maxLen ? currLen : maxLen);
			}
			else
				currLen = 1;
		}


		return maxLen;
    }
};

int main(int argc, char **argv)
{
	// initialization, data preparation
	vector<int> num = {100, 4, 200, 1, 3, 2};
	// my solution
	Solution sln;
	auto result = sln.longestConsecutive(num);
	// correct answer

	return EXIT_SUCCESS;
}