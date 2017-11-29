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
     * @param nums: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
  vector<long long> productExcludeItself(vector<int> &nums)
  {
    // write your code here
    int n = nums.size();
    vector<long long> ans(n, 1);
    if (n <= 1)
      return ans;
    vector<long long> f(n + 1, 1);
    for (int i = n - 1; i >= 0; --i)
    {
      f[i] = f[i + 1] * nums[i];
    }
    long long prod = 1;
    for (int i = 0; i < n; ++i)
    {
      ans[i] = prod * f[i + 1];
      prod *= nums[i];
    }
    return ans;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  vector<int> nums = {1, 2, 3};
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.productExcludeItself(nums);

  return EXIT_SUCCESS;
}