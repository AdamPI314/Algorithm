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
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
  int kthLargestElement(int n, vector<int> &nums)
  {
    // write your code here
    // O(log(k)*n) time complexity
    int len = nums.size();

    if (n <= 0 || n > len)
      return -1;

    // use priority queue, time complexity to construct pq initially, O(n)
    // O(log(n)) performance for inserts and removals
    priority_queue<int, vector<int>, less<int>> pq(nums.begin(), nums.end());
    int result = 0;
    for (int i = 0; i < n; ++i)
    {
      result = pq.top();
      pq.pop();
    }

    return result;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  vector<int> nums = {9, 3, 2, 4, 8};
  int n = 3;

  // my solution
  Solution sln;
  auto x = sln.kthLargestElement(n, nums);
  // correct answer

  return EXIT_SUCCESS;
}