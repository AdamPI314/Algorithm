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

class Vector2D
{
  public:
	forward_list<int> my_list;
	forward_list<int>::iterator curr_it = my_list.before_begin();

  public:
	Vector2D(vector<vector<int>> &vec2d)
	{
		// Initialize your data structure here
		for (auto x : vec2d)
		{
			if (x.size() > 0)
				curr_it = my_list.insert_after(curr_it, x.begin(), x.end());
		}
		curr_it = my_list.before_begin();
	}

	int next()
	{
		// Write your code here
		++curr_it;
		return *curr_it;
	}

	bool hasNext()
	{
		// Write your code here
		return std::next(curr_it, 1) != my_list.end();
	}
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

int main(int argc, char **argv)
{
	// initialization, data preparation
	vector<vector<int>> vec2d = {{1, 2}, {3}, {4, 5, 6}};
	// my solution
	Vector2D i(vec2d);
	while (i.hasNext())
		cout << i.next();

	// correct answer

	return EXIT_SUCCESS;
}