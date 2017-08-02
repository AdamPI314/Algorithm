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
     * @param grid a chessboard included 0 and 1
     * @return the shortest path
     */
	int shortestPath2(vector<vector<bool>> &grid)
	{
		// Write your code here
		int result = -1;
		int m = grid.size();
		if (m <= 1)
			return -1;
		int n = grid[0].size();
		if (n <= 1)
			return -1;
		// the same line same volume is not reachable
		// Best to use dijkstra' algorithm here
		int len = m * n;
		vector<int> predecessor(len, -1);
		vector<int> distance(len, INT_MAX - len);
		distance[0] = 0;
		// source (0,0)-->0, target (m-1, n-1)-->(m*n-1)
		std::function<bool(const pair<int, int> &, const pair<int, int> &)> cmp =
			[&distance, n](const pair<int, int> &x1, const pair<int, int> &x2) -> bool {
			return distance[x1.first * n + x1.second]  < distance[x2.first * n + x2.second];
		};
		std::priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);

		q.push(make_pair(0, 0));
		int x = 0, y = 0;
		while (!q.empty())
		{
			std::tie(x, y) = q.top();
			q.pop();

			int ind1 = x * n + y;
			int tmp = distance[ind1] + 1;
			// search all its neighors
			if (isValid(grid, m, n, x + 1, y + 2))
			{
				int ind2 = (x + 1) * n + y + 2;
				if (tmp < distance[ind2])
				{
					distance[ind2] = tmp;
					predecessor[ind2] = ind1;
					q.push(make_pair(x + 1, y + 2));
				}
			}
			if (isValid(grid, m, n, x - 1, y + 2))
			{
				int ind2 = (x - 1) * n + y + 2;
				if (tmp < distance[ind2])
				{
					distance[ind2] = tmp;
					predecessor[ind2] = ind1;
					q.push(make_pair(x - 1, y + 2));
				}
			}
			if (isValid(grid, m, n, x + 2, y + 1))
			{
				int ind2 = (x + 2) * n + y + 1;
				if (tmp < distance[ind2])
				{
					distance[ind2] = tmp;
					predecessor[ind2] = ind1;
					q.push(make_pair(x + 2, y + 1));
				}
			}
			if (isValid(grid, m, n, x - 2, y + 1))
			{
				int ind2 = (x - 2) * n + y + 1;
				if (tmp < distance[ind2])
				{
					distance[ind2] = tmp;
					predecessor[ind2] = ind1;
					q.push(make_pair(x - 2, y + 1));
				}
			}
		}
		result = distance[len - 1] < len ? distance[len - 1] : -1;
		return result;
	}

	bool isValid(vector<vector<bool>> &grid, int m, int n, int x, int y)
	{
		if (x < 0 || y < 0)
			return false;
		if (x >= m || y >= n)
			return false;
		if (grid[x][y] == 1)
			return false;
		return true;
	}
};

int main(int argc, char **argv)
{
	// initialization, data preparation
	vector<vector<bool>> grid = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	// my solution
	Solution sln;
	auto result = sln.shortestPath2(grid);
	// correct answer

	return EXIT_SUCCESS;
}
