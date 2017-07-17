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

#include "../../include/fileIO/fileIO.h"
#include "../../include/dataStructure/dataStructure.h"
#include "../../include/misc/misc.h"

using namespace std;

class Solution
{
  public:
	/**
     * @param arrays k sorted integer arrays
     * @return a sorted array
     */
	vector<int> mergekSortedArrays(vector<vector<int>> &arrays)
	{
		// Write your code here
		int k = arrays.size() - 1;
		while (k > 0)
		{
			int i = 0, j = k;
			while (i < j)
			{
				int n = arrays[i].size();
				arrays[i].resize(arrays[i].size() + arrays[j].size());
				std::copy(arrays[j].begin(), arrays[j].end(), arrays[i].begin() + n);
				std::inplace_merge(arrays[i].begin(), arrays[i].begin() + n, arrays[i].end());
				// destroy arrays[j], free memory
				arrays[j].resize(0);
				++i;
				--j;
			}
			k = j;
		}
		return arrays[0];
	}
};

int main(int argc, char **argv){
	// initialization, data preparation
	vector<vector<int>> arrays = {{1, 2, 3}, {1, 2}};
	// my solution
	Solution sln;
	auto result = sln.mergekSortedArrays(arrays);

	// correct answer

	return EXIT_SUCCESS;
}