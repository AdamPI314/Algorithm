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
     * @param nums: An ineger array
     * @return: An integer
     */
  int removeDuplicates(vector<int> &nums)
  {
    // write your code here
    int n = nums.size();
    if (n == 0)
      return 0;

    int p = 0;
    // guaranteed that n >= 1
    for (size_t q = 1; q < n; ++q)
    {
      if (nums[q] <= nums[p])
        continue;
      // swap nums[p+1] and nums[q]
      ++p;
      std::swap(nums[p], nums[q]);
    }

    return p + 1;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  vector<int> nums = {1, 1, 2};
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.removeDuplicates(nums);
  return EXIT_SUCCESS;
}