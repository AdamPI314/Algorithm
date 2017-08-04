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
     * @param stones a list of stones' positions in sorted ascending order
     * @return true if the frog is able to cross the river or false
     */
  bool canCross(vector<int> &stones)
  {
    // Write your code here
    int n = stones.size();
    if (n <= 0)
      return false;
    if (n == 1)
      return true;

    // store the all jumps that can reach current point
    unordered_map<int, unordered_set<int>> hash;
    for (auto x : stones)
      hash[x] = unordered_set<int>();
    hash[0].insert(0);
    for (auto x : stones)
    {
      for (auto k : hash[x])
      {
        //k -1
        if (k - 1 > 0 && hash.find(x + k - 1) != hash.end())
          hash[x + k - 1].insert(k - 1);
        //k
        if (k > 0 && hash.find(x + k) != hash.end())
          hash[x + k].insert(k);
        //k + 1
        if (k + 1 > 0 && hash.find(x + k + 1) != hash.end())
          hash[x + k + 1].insert(k + 1);
      }
    }
    return !hash[stones.back()].empty();
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
  // my solution
  Solution sln;
  auto result = sln.canCross(stones);

  // correct answer

  return EXIT_SUCCESS;
}