#include <iostream>
#include <utility>
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
     * @param n an integer
     * @return an integer
     */
    int climbStairs2(int n) {
        // Write your code here
		if (n < 0)
			return -1;
		if (n == 0)
			return 1;
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		if (n == 3)
			return 4;
		// store best up to n
		vector<int> f(n, 0);
		f[0] = 1;
		f[1] = 2;
		f[2] = 4;
		for (int i = 3; i < n; ++i) {
				f[i] = f[i-1] + f[i-2] + f[i-3];
		}

		return f[n-1];
    }
};

int main(int argc, char **argv)
{
	// initialization, data preparation

	// my solution
	Solution sln;
	auto result = sln.climbStairs2(10);
	// correct answer

	return EXIT_SUCCESS;
}