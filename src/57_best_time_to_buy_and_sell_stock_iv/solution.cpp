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
  int maxProfit(int k, vector<int> &prices)
  {
    if (prices.empty())
      return 0;

    int ans = 0;
    // simple case, sum up all positive changes
    if (k >= prices.size() / 2)
    {
      for (int i = 1; i < prices.size(); ++i)
      {
        if (prices[i] - prices[i - 1] > 0)
        {
          ans += prices[i] - prices[i - 1];
        }
      }
    }
    else
    {
      //local represents up to current points i, use current point, the maximum
      vector<int> local(k + 1, 0);
      //global represents up to current points i, use or don't use current point, the maximum
      vector<int> global(k + 1, 0);

      for (int i = 0; i < prices.size() - 1; ++i)
      {
        int increase = prices[i + 1] - prices[i];

        for (int j = k; j >= 1; --j)
        {
          // local, have to use current point, either in a global and local way 
          local[j] = max(global[j - 1] + max(increase, 0), local[j] + increase);
          global[j] = max(global[j], local[j]);
        }
      }
      ans = global[k];
    }
    return ans;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  vector<int> prices = {4, 4, 6, 1, 1, 4, 2, 5};
  // vector<int> prices = {1, 2};
  int k = 2;
  // int k = 1;
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.maxProfit(k, prices);
  return EXIT_SUCCESS;
}