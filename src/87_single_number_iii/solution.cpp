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
  vector<int> singleNumberIII(vector<int> &nums)
  {
    int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    //even many bits may differ, we use only one bit, for example the last bit
    //the following operation get the last 1 in the bitwise representation
    diff &= -diff;
    vector<int> res(2, 0);
    for (auto &a : nums)
    {
      if (a & diff)
        res[0] ^= a;
      else
        res[1] ^= a;
    }
    return res;
  }
};
int main(int argc, char **argv)
{
  // initialization, data preparation
  std::vector<int> nums = {1, 1, 2, 2, 3, 4};
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.singleNumberIII(nums);

  return EXIT_SUCCESS;
}