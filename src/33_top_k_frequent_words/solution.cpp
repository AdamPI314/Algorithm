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

class Solution
{
  public:
	/**
     * @param words an array of string
     * @param k an integer
     * @return an array of string
     */
	vector<string> topKFrequentWords(vector<string> &words, int k)
	{
		// Write your code here
		vector<string> result;
		map<string, int> hash;
		for (auto w : words)
			hash[w] += 1;
		multimap<int, string, std::greater<int>> hash2;
		for (auto x : hash)
			hash2.emplace(x.second, x.first);

		if (k > hash2.size())
			std::transform(hash2.begin(), hash2.end(), std::back_inserter(result), [](pair<int, string> kv) { return kv.second; });
		else
			std::transform(hash2.begin(), std::next(hash2.begin(), k), std::back_inserter(result), [](pair<int, string> kv) { return kv.second; });

		return result;
	}
};

int main(int argc, char **argv)
{
	// initialization, data preparation
	vector<string> words = {"yes", "lint", "code",
							"yes", "code", "baby",
							"you", "baby", "chrome",
							"safari", "lint", "code",
							"body", "lint", "code"};
	int k = 3;
	// my solution
	Solution sln;
	auto result = sln.topKFrequentWords(words, k);
	// correct answer

	return EXIT_SUCCESS;
}