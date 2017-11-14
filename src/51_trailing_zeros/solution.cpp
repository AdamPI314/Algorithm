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
     * @param n: A long integer
     * @return: An integer, denote the number of trailing zeros in n!
     */
  long long trailingZeros(long long n)
  {
    // write your code here, try to do it without arithmetic operators.
    // trailing zero cases, 10, 100, ... or 2*5
    long long result = 0;

    // how many 5, how many 2, a lot more 2 than 5,
    // so the number of 5 dertermines the number of trailing zeros
    auto max5 = log(n) / log(5);
    // it could be 5, 25, 125, ...
    for (long long i = 1; i <= floor(max5); ++i)
    {
      result += floor(n / (pow(5, i)));
    }

    return result;
  }

  // long long trailingZeros(long long n)
  // {
  //   long long sum = 0;
  //   while (n != 0)
  //   {
  //     sum += n / 5;
  // just another way to determine the power of 5
  //     n /= 5;
  //   }
  //   return sum;
  // }

};

int main(int argc, char **argv)
{
  // initialization, data preparation

  // my solution
  Solution sln;

  // correct answer
  auto x = sln.trailingZeros(100);

  return EXIT_SUCCESS;
}