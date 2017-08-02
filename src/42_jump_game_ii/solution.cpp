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
     * @param A: A list of lists of integers
     * @return: An integer
     */
	int jump(vector<int> A)
	{
		// wirte your code here
		// In essence, this is still the shortest path problem, dijkstra is the best solution
		// It is even easier, bacause one cannot jump back
		int n = A.size();
		if (n == 0)
			return -1;
		if (n == 1)
			return 0;
		vector<int> distance(n, INT_MAX - n);
		distance[0] = 0;
		std::function<bool(const pair<int, int> &, const pair<int, int> &)> cmp = [&distance](const pair<int, int> &x1, const pair<int, int> &x2) -> bool {
			// bigger index comes first
			if (x1.second == x2.second)
				return x1.first > x2.first;
			return x1.second < x2.second;
		};
		std::multiset<pair<int, int>, decltype(cmp)> q(cmp);
		q.insert(std::make_pair(0, 0));

		while (!q.empty())
		{
			auto p = *(q.begin());
			q.erase(p);

			int x = p.first;
			if (x == n - 1)
				break;

			// iterate over x's neighbors
			for (int i = 1; i <= A[x] && i < n - x; ++i)
			{
				int ind = x + i;
				int val = distance[x] + 1;
				if (val < distance[ind])
				{
					distance[ind] = val;
					// remove if exist
					auto iter = q.find(std::make_pair(ind, distance[ind]));
					if (iter != q.end())
						q.erase(iter);

					distance[ind] = val;
					q.insert(std::make_pair(ind, val));
				}
			}
		}

		return distance[n - 1];
	}
};

int main(int argc, char **argv)
{
	// initialization, data preparation
	vector<int> A = {13,46,6,21,30,15,99,9,12,9,7,74,14,5,3,24,1,31,40,35};
	// my solution
	Solution sln;
	auto result = sln.jump(A);

	// correct answer

	return EXIT_SUCCESS;
} // correct answer
