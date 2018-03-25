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
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
  // good explanation
  // https://www.youtube.com/watch?v=VNbkzsnllsU
  int largestRectangleArea(vector<int> &height)
  {

    int ans = 0;
    height.push_back(0);
    vector<int> position;

    for (int i = 0; i < height.size(); i++)
    {
      while (position.size() > 0 && height[i] <= height[position.back()])
      {
        int h = height[position.back()];
        position.pop_back();

        int idx_low = position.size() > 0 ? position.back() : -1;
        ans = max(ans, h * (i - idx_low - 1));
      }

      // always push current index into stack, since it can be idx_low for future rectangle
      position.push_back(i);
    }

    return ans;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  vector<int> height = {2, 1, 5, 6, 2, 3};
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.largestRectangleArea(height);
  return EXIT_SUCCESS;
}