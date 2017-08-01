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

class LFUCache
{
  public:
	int capacity = 0;
	map<int, vector<int>> hash;
	int most_recent = 0;

	typedef map<int, vector<int>>::iterator mpi;
	vector<mpi> frequency;

	std::function<bool(mpi, mpi)> cmp = [](const mpi &x1, const mpi &x2) -> bool {
		if ((*x1).second[1] == (*x2).second[1])
			return (*x1).second[2] < (*x2).second[2]; 
		return (*x1).second[1] > (*x2).second[1];
	};

  public:
	// @param capacity, an integer
	LFUCache(int capacity)
	{
		// Write your code here
		this->capacity = capacity;
	}

	// @param key, an integer
	// @param value, an integer
	// @return nothing
	void set(int key, int value)
	{
	   // std::make_heap(frequency.begin(), frequency.end(), cmp);
		// Write your code here
		if (hash.find(key) != hash.end())
		{
			hash[key][0] = value;
			hash[key][1] += 1;
			hash[key][2] = (--most_recent);
			std::make_heap(frequency.begin(), frequency.end(), cmp);
			return;
		}
		if (hash.size() < capacity)
		{
			vector<int> tmp = {value, 1, --most_recent};
			auto x = hash.insert(std::make_pair(key, tmp));
			if (x.second)
				frequency.push_back(x.first);
			std::push_heap(frequency.begin(), frequency.end(), cmp);
			return;
		}
		else
		{
			std::pop_heap(frequency.begin(), frequency.end(), cmp);
			hash.erase(frequency.back());
			vector<int> tmp = {value, 1, --most_recent};
			auto x = hash.insert(std::make_pair(key, tmp));
			if (x.second)
				frequency[capacity - 1] = x.first;
			std::push_heap(frequency.begin(), frequency.end(), cmp);
			return;
		}
	}

	// @return an integer
	int get(int key)
	{
		// Write your code here
		if (hash.find(key) == hash.end())
			return -1;
		hash[key][1] += 1;
		hash[key][2] = (--most_recent);
// 		std::make_heap(frequency.begin(), frequency.end(), cmp);
		return hash[key][0];
	}
};


int main(int argc, char **argv)
{
	// initialization, data preparation

	// my solution
	// Solution sln;

	// correct answer

	return EXIT_SUCCESS;
}