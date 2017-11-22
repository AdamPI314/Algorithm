#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <unordered_map>
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
  /*
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
  int totalNQueens(int n)
  {
    // write your code here
    vector<int> path;
    int ans = 0;

    backtrack(n, 0, path, ans);

    return ans;
  }

  void backtrack(const int &n, const int &row, vector<int> &path, int &ans)
  {
    if (path.size() == n)
    {
      ans += 1;
      return;
    }
    for (int i = 0; i < n; ++i)
    {
      if (!is_valid(path, i))
        continue;
      path.push_back(i);
      backtrack(n, row + 1, path, ans);
      // backtrack
      path.pop_back();
    }
  }

  bool is_valid(const vector<int> &path, int col)
  {
    // assume path is a valid path
    int row = path.size();
    // not in the same column
    for (int i = 0; i < row; ++i)
    {
      if (path[i] == col)
        return false;
    }
    for (int i = 0; i < row; ++i)
    {
      // diagonal, slope == 1
      if (col - path[i] == row - i)
        return false;
      // diagonal, slope == -1
      if (col - path[i] == i - row)
        return false;
    }

    return true;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation

  // my solution
  Solution sln;
  auto x = sln.totalNQueens(4);

  // correct answer

  return EXIT_SUCCESS;
}