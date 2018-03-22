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
  int numDistinct(string &S, string &T)
  {
    // write your code here
    vector<vector<int>> f(T.length() + 1, vector<int>(S.length() + 1));
    for (int i = 0; i <= T.length(); i++)
      f[i][0] = 0;
    for (int i = 0; i <= S.length(); i++)
      f[0][i] = 0;
    // unit element
    for (int i = 1; i <= S.length(); i++)
    {
      if (T[0] == S[i - 1])
        f[1][i] = f[1][i - 1] + 1;
      else
        f[1][i] = f[1][i - 1];
    }

    for (int i = 2; i <= T.length(); i++)
    {
      for (int j = 1; j <= S.length(); j++)
      {
        // contingent operation, wether the ith element in T is covered or not
        if (T[i - 1] == S[j - 1])
          f[i][j] = f[i - 1][j - 1] + f[i][j - 1];
        else
          f[i][j] = f[i][j - 1];
      }
    }
    return f[T.length()][S.length()];
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