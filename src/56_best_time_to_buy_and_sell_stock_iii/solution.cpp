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
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
  int maxProfit(vector<int> &prices)
  {
    // write your code here
    if (prices.size() <= 1)
      return 0;
    vector<int> f_diff(prices.size(), 0);
    for (int i = 1; i < f_diff.size(); ++i)
    {
      f_diff[i] = prices[i] - prices[i - 1];
      f_diff[i] += f_diff[i - 1];
    }
    // forward maximum, up to current point
    vector<int> f_max(f_diff.size(), 0);
    int fmin = 0;
    for (int i = 1; i < f_diff.size(); ++i)
    {
      f_max[i] = max(f_max[i - 1], f_diff[i] - fmin);
      fmin = min(fmin, f_diff[i]);
    }

    vector<int> b_diff(prices.size(), 0);
    for (int i = b_diff.size() - 2; i >= 0; --i)
    {
      b_diff[i] = prices[i] - prices[i + 1];
      b_diff[i] += b_diff[i + 1];
    }
    // backward maximum, up to current point
    vector<int> b_max(b_diff.size(), 0);
    int bmax = 0;
    for (int i = b_diff.size() - 2; i >= 0; --i)
    {
      b_max[i] = max(b_max[i + 1], bmax - b_diff[i]);
      bmax = max(bmax, b_diff[i]);
    }
    int result = f_max.back();
    for (int i = 0; i < f_diff.size() - 1; ++i)
    {
      result = max(result, f_max[i] + b_max[i + 1]);
    }
    return result;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  // vector<int> prices = {4, 4, 6, 1, 1, 4, 2, 5};
  vector<int> prices = {2, 1, 4, 5, 2, 9, 7};

  // my solution
  Solution sln;

  // correct answer
  auto x = sln.maxProfit(prices);

  return EXIT_SUCCESS;
}