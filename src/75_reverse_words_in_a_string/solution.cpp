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
     * @param s: A string
     * @return: A string
     */
  string reverseWords(string &s)
  {
    // write your code here
    string ans;
    vector<string> words;
    int n = s.size();
    if (n == 0)
      return ans;

    int beg = 0, end = 0;
    while (end < n)
    {
      while (s[beg] == ' ' && beg < n)
        ++beg;
      end = beg + 1;
      while (s[end] != ' ' && end < n)
        ++end;
      if (beg < end && beg < n)
      {
        words.push_back(s.substr(beg, end - beg));
        beg = end;
      }
    }

    beg = 0, end = words.size() - 1;
    while (beg <= end)
    {
      swap(words[beg], words[end]);
      ++beg;
      --end;
    }
    if (words.size() == 1)
      return words[0];
    for (int i = 0; i < words.size(); ++i)
    {
      ans += words[i];
      if (i < words.size() - 1)
        ans += " ";
    }

    return ans;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  string s = "the sky is blue   ";
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.reverseWords(s);

  return EXIT_SUCCESS;
}