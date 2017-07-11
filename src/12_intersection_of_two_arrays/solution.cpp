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
  /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
  {
    // Write your code here
    vector<int> result;

    map<int, int> hash;
    for (auto x : nums1)
      hash[x] += 1;

    for (auto x : nums2)
    {
      if (hash[x] > 0)
      {
        result.push_back(x);
        hash[x] = -1;
      }
    }

    return result;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  vector<int> nums1 = {1, 2, 3};
  vector<int> nums2 = {2, 3, 4};

  // my solution
  Solution sln;
  auto result = sln.intersection(nums1, nums2);
  // correct answer

  return EXIT_SUCCESS;
}