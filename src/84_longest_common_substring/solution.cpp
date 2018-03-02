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
     * @param A: A string
     * @param B: A string
     * @return: the length of the longest common substring.
     */
  int longestCommonSubstring(string &A, string &B)
  {
    // write your code here
    int m = A.size();
    int n = B.size();
    if (m == 0 || n == 0)
      return 0;
    std::vector<std::vector<int>> f(m + 1, std::vector<int>(n + 1, 0));

    int max = 0;
    // longest substring till index i, covering (0, i)
    for (int i = 1; i <= m; ++i)
    {
      for (int j = 1; j <= n; ++j)
      {
        if (A[i - 1] == B[j - 1])
        {
          f[i][j] = f[i - 1][j - 1] + 1;
          max = std::max(max, f[i][j]);
        }
        else
        {
          f[i][j] = 0;
        }
      }
    }

    return max;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  std::string A = "ABCD";
  std::string B = "CBCE";

  // my solution
  Solution sln;

  // correct answer
  auto x = sln.longestCommonSubstring(A, B);

  return EXIT_SUCCESS;
}