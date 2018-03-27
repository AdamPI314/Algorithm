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
    if (buildings.size() == 0)
      return ans;

    // keep track of unsolved_sub intervals, guaranteed there will not be collision
    set<int> un_visited;
    map<int, pair<int, int>> myM;

    // first, determine all critical points, O(n)
    for (auto x : buildings)
    {
      if (myM.find(x[0]) == myM.end())
        myM.emplace(x[0], make_pair(-1, -1));
      if (myM.find(x[1]) == myM.end())
        myM.emplace(x[1], make_pair(-1, -1));
    }
    // determine sub-intervals
    auto p1 = myM.rbegin();
    auto p2 = myM.rbegin();
    ++p1; // p1 < p2
    for (; p1 != myM.rend(); ++p1, ++p2)
    {
      p1->second.first = p2->first;
      un_visited.emplace(p1->first);
    }
    myM.erase(prev(myM.end()));

    // sort buildings by height, O(nlog(n))
    auto comp = [](const vector<int> &v1, const vector<int> &v2) { return v1.back() > v2.back(); };
    sort(buildings.begin(), buildings.end(), comp);

    // from the largest height to the smallest height
    for (auto x : buildings)
    {
      if (un_visited.size() <= 0)
        break;
      // search for iterator, guaranteed can find it, search un_visited instead
      auto l_p = un_visited.lower_bound(x[0]);
      auto h_p = un_visited.upper_bound(x[1] - 1); // can not be x[1]
      auto l_p2 = l_p;
      auto h_p2 = h_p;
      while (l_p != h_p)
      {
        auto value = *l_p;
        myM[value].second = x[2];
        ++l_p;
      }
      un_visited.erase(l_p2, h_p2);
    }

    // p1<=p2
    for (auto x : myM)
    {
      if (x.second.second == -1)
        continue;
      // first element
      if (ans.size() == 0)
      {
        ans.push_back({x.first, x.second.first, x.second.second});
        continue;
      }
      // else
      if (x.second.second == ans.back().back())
        ans.back()[1] = x.second.first;
      else
        ans.push_back({x.first, x.second.first, x.second.second});
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