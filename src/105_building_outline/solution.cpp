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
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
  vector<vector<int>> buildingOutline(vector<vector<int>> &buildings)
  {
    // write your code here
    vector<vector<int>> ans;

    // search for possible intervals, has form of (i, i+1)
    // represented by i in a hashmap
    // the second element represent the height of current inteval
    // O(m*n)
    // save both start and end index
    map<int, int> myM;

    for (auto x : buildings)
    {
      // search, partition and assign value
      if (myM.size() == 0)
      {
        myM[x[0]] = x[2];
        myM[x[1]] = -1;
        continue;
      }
      // else
      // use binary search, find the range could be affected by this new building
      auto iter_l = myM.lower_bound(x[0]);
      auto iter_u = myM.upper_bound(x[1]);
      // update
      if (iter_l->first < x[0])
      {
        // a new building, no overlap
        myM[x[0]] = x[2];
        myM[x[1]] = -1;
        continue;
      }

    }

    // merge them O(myM)

    for (auto x : myM)
    {
      if (ans.size() == 0)
      {
        ans.push_back(vector<int>({x.first, x.first + 1, x.second}));
        continue;
      }
      // else
      if (x.second == ans.back().back())
      {
        ans.back()[1] = x.first + 1;
        continue;
      }
      // else, have a new height
      ans.push_back(vector<int>({x.first, x.first + 1, x.second}));
    }

    return ans;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  vector<vector<int>> buildings = {{1, 3, 3}, {2, 4, 4}, {5, 6, 1}};
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.buildingOutline(buildings);
  return EXIT_SUCCESS;
}