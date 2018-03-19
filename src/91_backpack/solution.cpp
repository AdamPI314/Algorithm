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
     * @return: The maximum size
     */
  int backPack(int m, vector<int> &A)
  {
    // write your code here
    std::sort(A.begin(), A.end());
    int n = A.size();
    if (m <= 0 || n == 0 || m < A[0])
      return 0;

    // bellman-ford algorithm, minimize m - sum(A*)
    std::vector<bool> f(m + 1, false);
    f[0] = true;
    // iterate over nodes, not the first one
    for (int i = 0; i < n; ++i)
    {
      // iterate over edges
      for (int j = m; j >= A[i]; --j)
      {
        // updating f vector
        f[j] = f[j] || f[j - A[i]];
      } // j
    }   // i
    int ans = std::distance(std::find_if(f.rbegin(), f.rend(), [](bool x) { return x; }), f.rend()) - 1;
    // std::cout << ans << std::endl;
    return ans;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  int m = 11;
  std::vector<int> A = {2, 3, 5, 7};
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.backPack(m, A);
  return EXIT_SUCCESS;
}