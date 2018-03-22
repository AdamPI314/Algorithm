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
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
  vector<vector<int>> combine(int n, int k)
  {
    // write your code here
    vector<vector<int>> ans;
    if (n <= 0 || k > n)
      return ans;
    vector<int> com;
    backtrack(n, k, 0, com, ans);

    return ans;
  }
  void backtrack(int n, int k, int start, vector<int> &com, vector<vector<int>> &ans)
  {
    //termination step
    if (com.size() == k)
    {
      ans.push_back(com);
      return;
    }

    // bring which number into candidate solution com
    for (int i = start; i < n; ++i)
    {
      com.push_back(i + 1);
      //contingent assumption, assume a solution with having previous numbers are solved by previous sub-array
      backtrack(n, k, i + 1, com, ans);
      com.pop_back();
    }
  }
};
int main(int argc, char **argv)
{
  // initialization, data preparation

  // my solution
  Solution sln;

  // correct answer
  auto x = sln.combine(4, 2);
  return EXIT_SUCCESS;
}