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

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        // write your code here
        if (nums.size() <= 1)
          return;
        helper(nums, nums.size() - 2);

    }

    void helper(vector<int>& nums, int currentIndex) {
      if (currentIndex == -1) {
        reverse(nums.begin(), nums.end());
        return;
      }
      // operation
      if (nums[currentIndex] >= nums[currentIndex+1] )
        helper(nums, currentIndex - 1);
      else {
        // locate the first number that is greater than currentIndex
        int pos = currentIndex+2;
        while(pos < nums.size() && nums[currentIndex] < nums[pos])
          ++pos;
        --pos;
        swap(nums[currentIndex], nums[pos]);
        if (currentIndex+1<nums.size() - 1)
          reverse(nums.begin()+currentIndex+1, nums.end());
      }
      return;
    }
};

int main(int argc, char** argv)
{
  // initialization, data preparation
  vector<int> nums = {1, 2, 3};
  // my solution
  Solution sln;
  sln.nextPermutation(nums);
  // correct answer
  

  return EXIT_SUCCESS;

}