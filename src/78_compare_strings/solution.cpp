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
     * @param A: A string
     * @param B: A string
     * @return: if string A contains all of the characters in B return true else return false
     */
  bool compareStrings(string &A, string &B)
  {
    // write your code here
    unordered_map<char, int> umA;
    unordered_map<char, int> umB;
    for (auto x : A)
    {
      umA[x] += 1;
    }
    for (auto x : B)
    {
      umB[x] += 1;
      if (umA.find(x) == umA.end())
        return false;
      if (umB.at(x) > umA.at(x))
        return false;
    }
    return true;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  string A = "ABCD";
  string B = "ACD";
  // my solution
  Solution sln;
  auto x = sln.compareStrings(A, B);
  // correct answer

  return EXIT_SUCCESS;
}