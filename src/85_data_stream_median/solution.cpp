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
  /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
  // left branch using a maximum Heap, right branch uses a minimum maximum Heap
  // when a new numbers comes, assign to left branch first, then do some comparison
  priority_queue<int, vector<int>, std::less<int> > leftB, rightB;
  vector<int> ans;
  int numOfElements = 0;
  vector<int> medianII(vector<int> &nums)
  {
    // write your code here
    int cnt = nums.size();
    for (int i = 0; i < cnt; ++i)
    {
      addNumber(nums[i]);
      ans.push_back(getMedian());
    }
    return ans;
  }
  void addNumber(int value)
  {
    leftB.push(value);
    if (numOfElements % 2 == 0)
    {
      if (rightB.empty())
      {
        numOfElements++;
        return;
      }
      else if (leftB.top() > -rightB.top())
      {
        int leftBRoot = leftB.top();
        int rightBRoot = -rightB.top();
        leftB.pop();
        rightB.pop();
        leftB.push(rightBRoot);
        rightB.push(-leftBRoot);
      }
    }
    else
    {
      rightB.push(-leftB.top());
      leftB.pop();
    }
    numOfElements++;
  }
  int getMedian()
  {
    return leftB.top();
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  std::vector<int> nums = {1, 2, 3, 4, 5};
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.medianII(nums);
  return EXIT_SUCCESS;
}