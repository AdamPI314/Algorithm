#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>
#include <cstdlib>

#include "../../include/fileIO/fileIO.h"
#include "../../include/dataStructure/dataStructure.h"
#include "../../include/misc/misc.h"

using namespace std;

class Solution
{
public:
  vector<int> result;

public:
  /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
  vector<int> previousPermuation(vector<int> &nums)
  {
    // write your code here
    if (nums.size() <= 1)
      return nums;
    helper(nums, nums.size() - 2);
    return this->result;
  }

  void helper(vector<int> &nums, int index)
  {
    if (index < 0)
    {
      result.resize(nums.size());
      reverse_copy(nums.begin(), nums.end(), result.begin());
      return;
    }
    int pos = locate(nums, index);
    if (pos != -1)
    {
      result.resize(nums.size());
      std::copy(nums.begin(), nums.end(), result.begin());
      std::swap(result[index], result[pos]);

      for (int i = 1; index+i < result.size()-i; ++i)
        std::swap(result[index+i], result[result.size()-i]);

      return;
    }
    else
      helper(nums, index - 1);
  }

  int locate(vector<int> &nums, int index)
  {
    if (nums[index] <= nums[index + 1])
      return -1;
    else
    {
      int pos = index + 1;
      // [5,2,4,6]      
      // find the last that is less than nums[index]
      while(pos <= nums.size() - 1 && nums[pos] < nums[index])
        ++pos;
      --pos;
      return pos;
    }
  }
};

int main(int argc, char **argv)
{
  vector<int> nums = {1, 3, 2, 3};

  // my solution
  Solution sln;
  // correct answer
  auto result = sln.previousPermuation(nums);

  // correct answer

  return EXIT_SUCCESS;
}
