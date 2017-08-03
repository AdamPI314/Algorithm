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

class Solution
{
  public:
	/**
     * @param envelopes a number of envelopes with widths and heights
     * @return the maximum number of envelopes
     */
	int maxEnvelopes(vector<pair<int, int>> &envelopes)
	{
		// Write your code here
		int n = envelopes.size();
		if (n == 0)
			return -1;

		std::function<bool(const pair<int, int> &, const pair<int, int> &)> cmp = [](const pair<int, int> &p1, const pair<int, int> &p2) -> bool {
			if (p1.first == p2.first)
				return p1.second > p2.second;
			return p1.first < p2.first;
		};

		std::set<pair<int, int>, decltype(cmp)> myset(envelopes.begin(), envelopes.end(), cmp);
		n = myset.size();
		std::copy(myset.begin(), myset.end(), envelopes.begin());

		if (n == 1)
			return 1;

		int maxLen = INT_MIN;
		// path stores the maximum path length including current node
		vector<int> path(n, 1);
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (envelopes[i].first == envelopes[j].first)
					break;
				if (envelopes[i].second > envelopes[j].second)
				{
					path[i] = max(path[i], path[j] + 1);
				}
			}
			maxLen = max(maxLen, path[i]);
		}

		return maxLen;
	}
};

int main(int argc, char **argv)
{
	// initialization, data preparation
	vector<pair<int, int>> envelopes = {{15, 8}, {2, 20}, {2, 14}, {4, 17}, {8, 19}, {8, 9}, {5, 7}, {11, 19}, {8, 11}, {13, 11}, {2, 13}, {11, 19}, {8, 11}, {13, 11}, {2, 13}, {11, 19}, {16, 1}, {18, 13}, {14, 17}, {18, 19}};
	// my solution
	Solution sln;
	auto result = sln.maxEnvelopes(envelopes);

	// correct answer

	return EXIT_SUCCESS;
}