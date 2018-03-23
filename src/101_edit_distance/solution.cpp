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
     * @param word1: A string
     * @param word2: A string
     * @return: The minimum number of steps.
     */
  int minDistance(string &word1, string &word2)
  {
    // write your code here
    // upper bound, max(m, n)
    // lower bound, abs(m - n)
    int m = word1.size(), n = word2.size();
    if (m == 0 || n == 0)
      return max(m, n);

    vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
    // edge cases, unit element
    // later
    for (int i = 1; i <= m; ++i)
      f[i][0] = i;
    for (int i = 1; i <= n; ++i)
      f[0][i] = i;

    for (int i = 1; i <= m; ++i)
    {
      for (int j = 1; j <= n; ++j)
      {
        // contingent operation, making assumption that f[i-1][j] and f[i][j-1] are ready the best solution
        // use current word1[i-1] or not, corresponding to delete operation and replace operation
        if (word1[i - 1] == word2[j - 1])
        {
          f[i][j] = min(f[i - 1][j - 1], f[i - 1][j] + 1);
        }
        else
        {
          f[i][j] = min(f[i - 1][j - 1] + 1, f[i - 1][j] + 1);
        }
        // corrresponding to insert operation
        f[i][j] = min(f[i][j], min(f[i - 1][j] + 1, f[i][j - 1] + 1));
      }
    }

    return f[m][n];
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  string word1 = "mart";
  string word2 = "karma";
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.minDistance(word1, word2);
  return EXIT_SUCCESS;
}