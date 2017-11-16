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
     * @param s1: A string
     * @param s2: A string
     * @param s3: A string
     * @return: Determine whether s3 is formed by interleaving of s1 and s2
     */
  bool isInterleave(const string &s1, const string &s2, const string &s3)
  {
    // write your code here
    int n1 = s1.size();
    int n2 = s2.size();
    int n3 = s3.size();

    if (n1 + n2 != n3)
      return false;
    if (n1 == 0)
      return s2 == s3;
    if (n2 == 0)
      return s1 == s3;

    if (s3[0] != s1[0] && s3[0] != s2[0])
    {
      return false;
    }
    else if (s3[0] == s1[0] && s3[0] == s2[0])
      return isInterleave(s1.substr(1), s2, s3.substr(1)) || isInterleave(s1, s2.substr(1), s3.substr(1));
    else if (s3[0] == s1[0])
      return isInterleave(s1.substr(1), s2, s3.substr(1));
    else
      return isInterleave(s1, s2.substr(1), s3.substr(1));
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  string s1 = "aabcc";
  string s2 = "dbbca";
  string s3 = "aadbbcbcac";
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.isInterleave(s1, s2, s3);

  return EXIT_SUCCESS;
}