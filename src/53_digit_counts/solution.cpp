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
     * @param : An integer
     * @param : An integer
     * @return: An integer denote the count of digit k in 1..n
     */
  int digitCounts(int k, int n)
  {
    // write your code here
    int result = 0;
    for (int i = 0; i <= n; ++i)
    {
      result += numberk(k, i);
    }

    return result;
  }

  int numberk(int k, int n)
  {
    if (k == 0 && n == 0)
      return 1;
    int result = 0;
    while (n > 0)
    {
      if (k == n % 10)
        ++result;
      n /= 10;
    }
    return result;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation

  // my solution
  Solution sln;

  // correct answer
  int n = 12;
  int k = 1;
  auto x = sln.digitCounts(k, n);

  return EXIT_SUCCESS;
}