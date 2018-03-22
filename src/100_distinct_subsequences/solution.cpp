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
     * @param : A string
     * @param : A string
     * @return: Count the number of distinct subsequences
     */
  int numDistinct(string S, string T)
  {
    // write your code here
    return backtrack(S, T);
  }

  int backtrack(string S, string T)
  {
    if (T.size() == 0)
      return 1;
    if (S.size() == 0 || T.size() > S.size())
      return 0;
    // unit element
    if (S == T)
      return 1;
    // guaranteed that S.size() >= 1, T.size() >= 1, S.size() >= T.size()
    // find first of
    auto beg = S.find_first_of(T.front());
    auto end = S.find_last_of(T.back());
    if (beg < 0 || beg > S.size() || end < 0 || end > S.size() || beg > end)
      return 0;

    // contingent operation, use current point or not
    return backtrack(S.substr(beg + 1, end - beg), T.substr(1)) + backtrack(S.substr(beg + 1, end - beg + 1), T);
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  string S = "rabbbit";
  string T = "rabbit";
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.numDistinct(S, T);
  return EXIT_SUCCESS;
}