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
	int k = 0;
	multiset<int, std::greater<int>> hash;

  public:
	Solution(int k)
	{
		// initialize your data structure here.
		this->k = k;
	}

	void add(int num)
	{
		// Write your code here
		hash.insert(num);
		if (hash.size() > k)
			hash.erase(std::prev(hash.end()));
	}

	vector<int> topk()
	{
		// Write your code here
		return vector<int>(hash.begin(), hash.end());
	}
};

int main(int argc, char **argv)
{
	// initialization, data preparation

	// my solution
	Solution sln(3);
	sln.add(3);
	sln.add(10);
	auto result = sln.topk();

	// correct answer

	return EXIT_SUCCESS;
}