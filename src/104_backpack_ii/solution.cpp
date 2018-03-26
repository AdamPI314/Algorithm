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
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
  int backPackII(int m, vector<int> &A, vector<int> &V)
  {
    // write your code here
    int n = A.size();
    if (n == 0 || A.size() != V.size())
      return 0;
    vector<int> f(m + 1, 0);

    // iterate over nodes
    for (int i = 1; i <= n; ++i)
    {
      for (int j = m; j >= A[i - 1]; --j)
      // for (int j = A[i - 1]; j <= m; ++j)
      {
        // the question is, how much space left
        f[j] = max(f[j], f[j - A[i - 1]] + V[i - 1]);
      }
    }

    return f[m];
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  int m = 10;
  vector<int> A = {2, 3, 5, 7};
  vector<int> V = {1, 5, 2, 4};
  // my solution
  Solution sln;
  auto x = sln.backPackII(m, A, V);
  // correct answer

  return EXIT_SUCCESS;
}