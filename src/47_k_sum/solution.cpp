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
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
  int kSum(vector<int> A, int k, int target)
  {
    // wirte your code here
    sort(A.begin(), A.end());
    int n = A.size();
    vector<vector<int> > f(k+1, vector<int>(n+1, 0));
    for (int i = 1; i <= k; ++i) {
      for (int j = 1; j <= n; ++j) {
        f[i][j] = 0;
      }
    }
    return -1;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  vector<int> A = {1, 2, 3, 4};
  int k = 2;
  int target = 5;
  // my solution
  Solution sln;
  auto result = sln.kSum(A, k, target);

  // correct answer

  return EXIT_SUCCESS;
}