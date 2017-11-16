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
     * @param n an integer
     * @return a list of pair<sum, probability>
     */
  vector<pair<int, double>> dicesSum(int n)
  {
    // Write your code here
    vector<pair<int, double>> result;
    vector<vector<double>> f(n + 1, vector<double>(6 * n + 1));

    for (int i = 1; i <= 6; ++i)
    {
      f[1][i] = 1.0 / 6;
    }
    // more than one throw
    for (int i = 2; i <= n; ++i)
    {
      //possible result in the index of 2nd dimension of f, results from previous throw
      for (int j = i - 1; j <= 6 * (i - 1); ++j)
      {
        for (int k = 1; k <= 6; ++k)
        {
          f[i][j + k] += f[i - 1][j] * 1.0 / 6;
        }
      }
    }
    result.reserve(6 * n - n + 1);
    for (int i = n; i <= 6 * n; ++i)
    {
      result.push_back(make_pair(i, f[n][i]));
    }
    return result;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  int n = 2;
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.dicesSum(n);
  return EXIT_SUCCESS;
}