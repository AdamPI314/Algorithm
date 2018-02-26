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
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
  string longestCommonPrefix(vector<string> &strs)
  {
    std::string result;
    if (strs.size() == 0)
      return result;
    // write your code here
    // n is the shortest string length
    int n = INT_MAX;
    for (auto x : strs)
    {
      if (x.size() < n)
        n = x.size();
    }
    if (n == 0)
      return result;

    for (int i = 0; i < n; ++i)
    {
      for (int j = 1; j < strs.size(); ++j)
      {
        if (strs[j][i] != strs[j - 1][i])
          if (i >= 1)
            return strs[0].substr(0, i);
          else
            return std::string("");
      }
    }
    return strs[0].substr(0, n);
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  std::vector<std::string> strs = {"ABCD", "ABEF", "ACEF"};

  // my solution
  Solution sln;

  // correct answer
  auto x = sln.longestCommonPrefix(strs);
  return EXIT_SUCCESS;
}