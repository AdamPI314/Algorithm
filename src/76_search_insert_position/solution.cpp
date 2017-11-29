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
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: An integer
     */
  int searchInsert(vector<int> &A, int target)
  {
    // write your code here
    int n = A.size();
    if (n == 0)
      return 0;

    // binary search
    int start = 0, end = n - 1;
    int mid = 0;
    while (start + 1 < end)
    {
      mid = start + (end - start) / 2;
      if (A[mid] == target)
        return mid;
      else if (A[mid] > target)
        end = mid;
      else
        start = mid;
    }
    if (target == A[start])
      return start;
    if (target == A[end])
      return end;
    if (target < A[start])
      return 0;
    if (target > A[end])
      return n;
    return end;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  vector<int> A = {1, 3, 5, 6};
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.searchInsert(A, 7);

  return EXIT_SUCCESS;
}