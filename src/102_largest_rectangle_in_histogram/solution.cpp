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
  int largestRectangleArea(vector<int> &height)
  {

    int ret = 0;
    height.push_back(0);
    vector<int> index;

    for (int i = 0; i < height.size(); i++)
    {
      while (index.size() > 0 && height[index.back()] >= height[i])
      {
        int h = height[index.back()];
        index.pop_back();

        int sidx = index.size() > 0 ? index.back() : -1;
        if (h * (i - sidx - 1) > ret)
          ret = h * (i - sidx - 1);
      }
      index.push_back(i);
    }

    return ret;
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