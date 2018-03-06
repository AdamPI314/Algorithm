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
  std::vector<std::vector<int>> ans;
  vector<vector<int>> kSumII(vector<int> &A, int k, int target)
  {
    // write your code here
    std::vector<int> tmp;
    backtrack(A, k, target, 0, tmp);
    return ans;
  }

  void backtrack(vector<int> A, int k, int target, int start, vector<int> tmp)
  {
    if (start >= A.size() || k <= 0 || target < 0)
    {
      return;
    }
    // whether have current point of not
    // have current point
    tmp.push_back(A[start]);
    // whether change happens, check result
    if (k == 1 && target == A[start])
    {
      this->ans.push_back(tmp);
    }
    backtrack(A, k - 1, target - A[start], start + 1, tmp);
    // don't have current point
    tmp.pop_back();
    backtrack(A, k, target, start + 1, tmp);
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