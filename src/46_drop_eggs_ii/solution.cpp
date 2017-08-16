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
  /**
     * @param m the number of eggs
     * @param n the umber of floors
     * @return the number of drops in the worst case
     */
  int dropEggs2(int m, int n)
  {
    // Write your code here
    vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
    // boundary conditions
    for (int i = 0; i <= m; ++i)
    {
      f[i][0] = 0;
    }
    for (int i = 0; i <= n; ++i)
    {
      f[1][i] = i;
      f[0][i] = 0;
    }
    for (int i = 2; i <= m; ++i)
    {
      for (int j = 1; j <= n; ++j)
      {
        int min_drop = INT_MAX;
        for (int k = 1; k <= j; ++k)
        {
          min_drop = min(min_drop, 1 + max(f[i][j - k], f[i - 1][k - 1]));
        }
        f[i][j] = min_drop;
      }
    }

    return f[m][n];
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  int m = 2, n = 100;
  // my solution
  Solution sln;
  auto result = sln.dropEggs2(m, n);
  // correct answer

  return EXIT_SUCCESS;
}