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
  string minWindow(string s, string t)
  {
    unordered_map<char, int> mp;
    for (char now : t)
    {
      mp[now]++;
    }
    // count indicates, between i and j, whether we find every thing
    int count = mp.size();
    int j = 0;
    int ans = INT_MAX;
    string res;
    for (int i = 0; i < s.size(); i++)
    {
      while (count != 0 && j < s.size())
      {
        // find a char, suppose use this char
        mp[s[j]]--;
        if (mp[s[j]] == 0)
        {
          // this char is be taken care of
          count--;
        }
        j++;
        if (count == 0)
        {
          break;
        }
      }
      if (count == 0 && j - i < ans)
      {
        ans = j - i;
        res = s.substr(i, j - i);
      }
      if (mp[s[i]] == 0)
      {
        count++;
      }
      mp[s[i]]++;
    }
    return res;
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