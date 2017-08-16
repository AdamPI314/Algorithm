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
  /**
     * @param m the number of eggs
     * @param n the umber of floors
     * @return the number of drops in the worst case supposing the best strategy
     */
  // with M eggs and k floors, supposing using the best strategy, in the worst case, the number of trials/drops is
  // find a smallest d, such that
  // sum_{i=1}^{M}{C(d,i)} >= k holds

  // calculate the sum of binomials, verify if it is greater than x
  // M eggs, d trials/drops
  long long int sum_binomial(int M, int d, long long x)
  {
    long long int result = 0;
    double aux = 1;
    for (int i = 1; i <= M; ++i)
    {
      aux /= (double)i;
      aux *= (double)d - i + 1;
      result += aux;

      // since this a binary search job, if sum_binomial > k, there is no need to keep calculating
      // because current scenario shall not be considered the best solution
      if (result > x)
      {
        break;
      }
    }
    return result;
  }

  int dropEggs2(int m, int n)
  {
    int begin = 0, end = n;
    int mid = 0;

    while (end - begin > 1)
    {
      // the reason don't use (begin+end)/2 is to avoid potential overflow
      mid = begin + (end - begin) / 2;
      if (sum_binomial(m, mid, n) < n)
        begin = mid;
      else
        end = mid;
    }
    return begin + 1;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  int m = 2, n = 100;
  // my solution
  Solution sln;
  auto result = sln.dropEggs2(m, n);
  // correct answer

  return EXIT_SUCCESS;
}