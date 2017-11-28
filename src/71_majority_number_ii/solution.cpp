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
     * @return: The majority number that occurs more than 1/3
     */
  int majorityNumber(vector<int> &nums)
  {
    // write your code here
    int n = nums.size();
    if (n == 0)
      return -1;
    float threshold = n / 3.0;

    unordered_map<int, int> um;
    for (auto x : nums)
    {
      um[x]++;
      if (um.at(x) > threshold)
        return x;
    }

    for (auto x : um)
    {
      if (x.second > threshold)
      {
        return x.first;
      }
    }
    return -1;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  vector<int> nums = {1, 2, 1, 2, 1, 3, 3};
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.majorityNumber(nums);
  return EXIT_SUCCESS;
}