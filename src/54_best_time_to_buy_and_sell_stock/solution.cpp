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
    if (prices.size() <= 1)
      return 0;
    // write your code here
    int result = 0;
    vector<int> diff(prices.size(), 0);
    for (int i = 1; i < diff.size(); ++i)
    {
      diff[i] = prices[i] - prices[i - 1];
      diff[i] += diff[i - 1];
    }

    // find a interval [m,n], so that diff[m] - diff[n] is maximized
    int pre_min = diff[0];
    int pre_max = diff[0];
    for (int i = 1; i < diff.size(); ++i)
    {
      // current value in between, ignore
      if (diff[i] <= pre_max && diff[i] >= pre_min)
        continue;
      else if (diff[i] > pre_max)
        pre_max = diff[i];
      else if (diff[i] < pre_min)
      {
        int delta = pre_max - pre_min;
        result = (delta > result) ? delta : result;
        pre_min = diff[i];
        pre_max = diff[i];
      }
    }

    int delta = pre_max - pre_min;
    result = (delta > result) ? delta : result;

    return result;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation

  // my solution
  Solution sln;

  // correct answer
  vector<int> prices = {3, 2, 3, 1, 2};
  auto x = sln.maxProfit(prices);

  return EXIT_SUCCESS;
}