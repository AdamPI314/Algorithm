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
     * @param nums: a list of integers
     * @return: A integer indicate the sum of minimum subarray
     */
  int minSubArray(vector<int> &nums)
  {
    // write your code here
    int n = nums.size();
    int pre_max = 0;
    int sum = 0;
    int min_sum = nums[0];

    for (int i = 0; i < n; ++i)
    {
      sum += nums[i];
      pre_max = max(pre_max, sum - nums[i]);
      min_sum = min(min_sum, sum - pre_max);
    }

    return min_sum;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  // vector<int> nums = {-1, -2, -3, -100, -1, -50};
  vector<int> nums = {1, -1, -2, 1};
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.minSubArray(nums);

  return EXIT_SUCCESS;
}