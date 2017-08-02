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
		vector<vector<int>> f(3,vector<int>(n, 0));
		for (int i = 1; i < m; ++i)	{
			for (int j = 1; j < n; ++j) {
				f[i][j] = 0;
			}
		}
		



		return result;
	}

	bool isValid(int m, int n, int x, int y) {
		if (x < 0 || y < 0)
			return false;
		if (x >= m || y >= n)
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