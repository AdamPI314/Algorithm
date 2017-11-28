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
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The majority number
     */
  int majorityNumber(vector<int> &nums, int k)
  {
    // write your code here
    int n = nums.size();
    if (n == 0)
      return -1;
    float threshold = 1.0 * n / k;

    unordered_map<int, int> um;
    for (auto x : nums)
    {
      um[x]++;
      if (um.at(x) > threshold)
        return x;
    }
    return -1;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  vector<int> nums = {3, 1, 2, 3, 2, 3, 3, 4, 4, 4};
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.majorityNumber(nums, 3);
  return EXIT_SUCCESS;
}