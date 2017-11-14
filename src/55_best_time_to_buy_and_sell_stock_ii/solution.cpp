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
    vector<int> diff(prices.size(), 0);
    for (int i = 1; i < prices.size(); ++i)
    {
      diff[i] = prices[i] - prices[i - 1];
    }

    int result = 0;
    for (int i = 1; i < diff.size(); ++i)
    {
      if (diff[i] > 0)
        result += diff[i];
    }
    return result;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  vector<int> prices = {2, 1, 2, 0, 1};
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.maxProfit(prices);

  return EXIT_SUCCESS;
}