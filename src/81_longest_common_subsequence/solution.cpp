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
     * @return: The length of longest common subsequence of A and B
     */
  int longestCommonSubsequence(string &A, string &B)
  {
    // write your code here
    int m = A.size();
    int n = B.size();
    if (m == 0 || n == 0)
      return 0;

    std::vector<std::vector<int>> f(m + 1, std::vector<int>(n + 1, 0));
    // O(m*n)
    for (int i = 1; i <= m; ++i)
    {
      // i indicates the starting point of string A
      for (int j = 1; j <= n; ++j)
      {
        // j indicates the starting point of string B
        // A[i], B[j]
        if (A[i - 1] == B[j - 1])
        {
          f[i][j] = f[i - 1][j - 1] + 1;
        }
        else
        {
          // either use current one don't use current one
          f[i][j] = std::max(f[i - 1][j], f[i][j - 1]);
        }
      }
    }

    // for (int i = 0; i < m + 1; ++i)
    // {
    //   for (int j = 0; j < n + 1; ++j)
    //   {
    //     std::cout << f[i][j] << "\t";
    //   }
    //   std::cout << "\n";
    // }
    return f[m][n];
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  std::string A = "ABCD";
  std::string B = "EACB";
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.longestCommonSubsequence(A, B);

  return EXIT_SUCCESS;
}