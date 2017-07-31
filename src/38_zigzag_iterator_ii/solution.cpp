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

class ZigzagIterator2
{
  public:
	int ind_i = -1;
	vector<vector<int>::iterator> begin;
	vector<vector<int>::iterator> end;
	int m = 0;

  public:
	/**
     * @param vecs a list of 1d vectors
     */
	ZigzagIterator2(vector<vector<int>> &vecs)
	{
		// initialize your data structure here.
		m = vecs.size();
		this->begin.resize(m);
		this->end.resize(m);
		for (int i = 0; i < m; ++i)
		{
			begin[i] = vecs[i].begin();
			end[i] = vecs[i].end();
		}
	}

	int next()
	{
		// Write your code here
		ind_i = (ind_i + 1) % m;
		int tmp = *(begin[ind_i]);
		begin[ind_i] += 1;
		return tmp;
	}

	bool hasNext()
	{
		// Write your code here
		int counter = 0;
		while (counter < m && begin[(ind_i + 1) % m] == end[(ind_i + 1) % m])
		{
			++counter;
			++ind_i;
		}
		if (begin[(ind_i + 1) % m] == end[(ind_i + 1) % m])
			return false;
		return true;
	}
};

int main(int argc, char **argv)
{
	// initialization, data preparation
	vector<vector<int>> vecs = {{1, 2, 3}, {4, 5, 6, 7}, {8, 9}};
	// my solution
	ZigzagIterator2 sln(vecs);
	vector<int> result;
	while (sln.hasNext())
		result.push_back(sln.next());

	// correct answer

	return EXIT_SUCCESS;
}