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
    return -1;
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