#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>

#include "../../include/fileIO/fileIO.h"
#include "../../include/dataStructure/dataStructure.h"
#include "../../include/misc/misc.h"

using namespace std;

class UnionFind
{
  // Weighted Quick Union With PathCompression
public:
  UnionFind(int n)
  {
    this->id.assign(n, 0);
    for (int i = 0; i < n; ++i)
      this->id[i] = i;
    this->w.assign(n, -1);
  }

public:
  // id
  vector<int> id;
  // weight
  vector<int> w;

public:
  int root(int i)
  {
    // path compression, flat tree, avoid deep tree
    while (i != id[i])
    {
      id[i] = id[id[i]];
      i = id[i];
    }
    return i;
  }

  bool find(int p, int q)
  {
    return root(p) == root(q);
  }

  void unite(int p, int q)
  {
    auto i = root(p);
    auto j = root(q);

    if (w[i] < w[j])
    {
      id[i] = j;
      w[j] += w[i];
    }
    else
    {
      id[j] = i;
      w[i] += w[j];
    }
  }
};

class Solution
{
public:
  /**
     * @param n an integer
     * @param m an integer
     * @param operators an array of point
     * @return an integer array
     */
  vector<int> numIslands2(int n, int m, vector<Point> &operators)
  {
    // Write your code here
    // Better use union-find
    size_t k = operators.size();
    UnionFind uf(m * n);

    vector<int> result(k);

    if (n <= 0 || m <= 0 || k == 0)
      return result;

    for (size_t i = 0; i < k; ++i)
    {
      auto x = operators[i].x;
      auto y = operators[i].y;

      int currentIndex = index(m, x, y);

      if (i == 0)
      {
        result[i] = 1;
        uf.w[currentIndex] = 1;
        continue;
      }

      // current point occupied already or not a valid point
      if (uf.w[currentIndex] != -1 || !isValid(x, y, n, m))
      {
        result[i] = result[i - 1];
        continue;
      }

      uf.w[currentIndex] = 1;

      // check around and group by value
      std::set<int> hash;
      if (isValid(x - 1, y, n, m) && uf.w[index(m, x - 1, y)] != -1)
        hash.insert(uf.root(index(m, x - 1, y)));
      if (isValid(x + 1, y, n, m) && uf.w[index(m, x + 1, y)] != -1)
        hash.insert(uf.root(index(m, x + 1, y)));
      if (isValid(x, y - 1, n, m) && uf.w[index(m, x, y - 1)] != -1)
        hash.insert(uf.root(index(m, x, y - 1)));
      if (isValid(x, y + 1, n, m) && uf.w[index(m, x, y + 1)] != -1)
        hash.insert(uf.root(index(m, x, y + 1)));

      int change = -1 * hash.size() + 1;
      result[i] = result[i - 1] + change;

      // merge island
      for (const auto &ind : hash)
      {
        uf.unite(currentIndex, ind);
      }
    }

    return result;
  }

  int index(int n, int x, int y)
  {
    return y + x * n;
  }
  bool isValid(int x, int y, int m, int n)
  {
    if (x >= 0 && x < m && y >= 0 && y < n)
      return true;
    return false;
  }
};

int main()
{

  int m, n;
  vector<dataStructure::Point> mat;
  fileIO::int_int_int_sparse_matrix("input.in", m, n, mat);
  Solution sln;
  auto result = sln.numIslands2(m, n, mat);
}