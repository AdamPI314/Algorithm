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
     * @param A: an integer array
     * @param k: a postive integer <= length(A)
     * @param targer: an integer
     * @return: A list of lists of integer
     */
  vector<vector<int>> kSumII(vector<int> &A, int k, int target)
  {
    // write your code here
    std::vector<std::vector<int>> ans;
    backtrack(A, k, 0, ans);
    return ans;
  }

  void backtrack(vector<int> A, int k, int start, vector<vector<int>> &ans)
  {
    if (start == A.size())
    {
      ans.push_back(std::vector<int>(A.begin(), A.begin() + k));
      return;
    }
    // swap
    for (int i = start; i < A.size(); ++i)
    {
      std::swap(A[i], A[start]);
      // every swap create a new combination
      // save previous first
      backtrack(A, k, start + 1, ans);
      std::swap(A[i], A[start]);
    }
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  std::vector<int> A = {1, 2, 3, 4};

  // my solution
  Solution sln;
  auto x = sln.kSumII(A, 2, 5);
  // correct answer

  return EXIT_SUCCESS;
}