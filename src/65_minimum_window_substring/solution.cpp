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
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
  string minWindow(string &source, string &target)
  {
    // write your code here
    string ans;
    int n1 = source.size();
    int n2 = target.size();
    if (n2 > n1 || n1 == 0)
      return ans;

    // dict
    unordered_map<char, int> s_map;
    unordered_map<char, int> t_map;

    for (auto x : source)
      s_map[x] += 1;
    for (auto x : target)
      t_map[x] += 1;

    // can not find case
    for (auto x : t_map)
    {
      if (s_map.find(x.first) == s_map.end())
        return "";
      else
      {
        if (s_map.at(x.first) < x.second)
          return "";
      }
    }
    // can find case

    return ans;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  string source = "ADOBECODEBANC";
  string target = "ABC";
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.minWindow(source, target);

  return EXIT_SUCCESS;
}