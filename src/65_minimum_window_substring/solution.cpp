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
    string ans;
    unordered_map<char, int> smp;
    unordered_map<char, int> tmp;

    for (auto c : t)
    {
      tmp[c] += 1;
    }
    int start_i = 0, end_i = 0;
    int min_len = INT_MAX;
    for (; start_i < s.size(); ++start_i)
    {
      while (!valid(smp, tmp) && end_i < s.size())
      {
        smp[s[end_i]]++;
        end_i++;
      }
      if (valid(smp, tmp))
      {
        // find a shorter one
        if (end_i - start_i < min_len)
        {
          min_len = min(min_len, end_i - start_i);
          ans = s.substr(start_i, end_i - start_i);
        }
      }
      // without current start_i, see what's gonna to happen
      smp[s[start_i]]--;
    }

    return ans;
  }

  bool valid(const unordered_map<char, int> &smp, const unordered_map<char, int> &tmp) const
  {
    for (auto const &x : tmp)
    {
      if (smp.find(x.first) == smp.end())
        return false;
      if (smp.at(x.first) < x.second)
        return false;
    }
    return true;
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