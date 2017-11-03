#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>
#include <cstdlib>

#include "../../include/fileIO/fileIO.h"
#include "../../include/dataStructure/dataStructure.h"
#include "../../include/misc/misc.h"

using namespace std;

// class Solution
// {
// public:
//   /**
//      * @param s a string
//      * @return an integer
//      */

//   // a global set that tells whether a interval [1,3] is calculated or not
//   map<int, int> hash;
//   // index, there is a overlap problem
//   int minCut(string s)
//   {
//     // write your code here
//     if (s.size() == 1)
//       return 0;

//     int result = helper(s, 0, s.size() - 1);

//     return result;
//   }

//   int helper(string s, int start, int end)
//   {
//     if (this->hash.find(start*s.size() + end) != hash.end())
//       return hash[start*s.size() + end];

//     if (start == end || isPalindrome(s, start, end)) {
//       hash[start*s.size() + end] = 0;
//       return 0;
//     }
//     else
//     {
//       // [1,2]
//       if (start + 1 == end)
//       {
//         hash[start*s.size() + end] = 1;
//         return 1;
//       }

//       // else [1,...2,...3]
//       int minN = INT_MAX;
//       for (int i = start; i < end; ++i)
//       {
//         auto N1 = helper(s, start, i);
//         if ((N1 + 1) > minN)
//           continue;
//         auto N2 = helper(s, i + 1, end);
//         minN = min(N1 + N2 + 1, minN);
//       }
//       hash[start*s.size() + end] = minN;
//       return minN;
//     }
//   }

//   bool isPalindrome(const string &s, int start, int end)
//   {
//     while (start < end)
//     {
//       if (s[start] != s[end])
//         return false;
//       ++start;
//       --end;
//     }
//     return true;
//   }
// };

class Solution
{
public:
  /**
     * @param s a string
     * @return an integer
     */
  int minCut(string s)
  {
    if (s.size() == 1)
        return 0;
      
    int n = s.length();
    vector<int> f(n+1);
    vector<vector<bool> > isPalin(n, vector<bool>(n));

    for (int i = 0; i < n; i++)
    {
      isPalin[i][i] = true;
      if (i + 1 < n)
      {
        isPalin[i][i + 1] = (s[i] == s[i + 1]);
      }
    }

    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = i + 2; j < n; j++)
      {
        isPalin[i][j] = isPalin[i + 1][j - 1] && (s[i] == s[j]);
      }
    }

    f[0] = -1;
    for (int i = 1; i <= n; i++)
    {
      f[i] = i - 1;
      for (int j = 0; j < i; j++)
      {
        if (isPalin[j][i - 1])
        {
          f[i] = min(f[i], f[j] + 1);
        }
      }
    }

    return f[n];
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  string s = "abcccb";

  // my solution
  Solution sln;
  auto result = sln.minCut(s);
  cout << result << endl;

  // correct answer

  return EXIT_SUCCESS;
}
