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
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums)
    {
        // write your code here
        if (nums.size() <= 1)
            return nums;

        result.resize(nums.size());

        helper(nums, nums.size() - 2);

        return result;
    }
    // index starts from 1, till nums.size() - 1
    void helper(vector<int> nums, int index)
    {
        // descending order to the end, reverse
        if (index < 0)
        {
            reverse_copy(nums.begin(), nums.end(), result.begin());
            return;
        }

        int pos = locate(nums, index);
        // find and swap
        if (pos != -1)
        {
            swap(nums[index], nums[pos]);
            for (int i = 1; index + i < nums.size() - i; ++i)
                swap(nums[index + i], nums[nums.size() - i]);
            std::copy(nums.begin(), nums.end(), this->result.begin());
            return;
        }
        else
            helper(nums, index - 1);
    }

    // is descending order, if no, locate position
    int locate(const vector<int> &nums, int index)
    {
        // still descending order
        if (nums[index] >= nums[index + 1])
            return -1;

        // find the smallest number in subVector[1:-1] that greater than subVector[0], linear time
        int pos = index + 1;
        while (pos <= nums.size() - 1 && nums[pos] > nums[index])
            ++pos;
        --pos;
        return pos;
    }
};

int main(int argc, char **argv)
{
    // input
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 11, 11, 23, 4, 5, 6, 7, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 5};

    // my solution
    Solution sln;
    // correct answer
    auto result = sln.nextPermutation(nums);

    return EXIT_SUCCESS;
}

