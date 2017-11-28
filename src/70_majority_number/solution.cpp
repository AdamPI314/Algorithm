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
     * @return: find a  majority number
     */
  int majorityNumber(vector<int> &nums)
  {
    // write your code here
    int n = nums.size();
    unordered_map<int, int> um;
    for (auto x : nums)
      um[x]++;
    int max = INT_MIN;
    int num = 0;
    for (auto x : um)
    {
      if (x.second > max)
      {
        max = x.second;
        num = x.first;
      }
    }
    if (float(max) > (n / 2.0))
      return num;
    else
      return -1;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  vector<int> nums = {1, 1, 1, 1, 2, 2, 2};
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.majorityNumber(nums);
  return EXIT_SUCCESS;
}