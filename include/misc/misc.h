#ifndef _MISC_H__
#define _MISC_H__

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>

#include "../dataStructure/dataStructure.h"
using namespace dataStructure;

namespace misc
{

class UnionFind
{
	// Weighted Quick Union With PathCompression
  public:
	UnionFind(int n);

  public:
	// id
	std::vector<int> id;
	// weight
	std::vector<int> w;

  public:
	int root(int i);
	bool find(int p, int q);
	void unite(int p, int q);
};

} //namespace;

#endif
