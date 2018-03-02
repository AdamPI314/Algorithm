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
     * @param number: A 3-digit number.
     * @return: Reversed number.
     */
  int reverseInteger(int number)
  {
    // write your code here
    int result = 0;
    while (number > 0)
    {
      auto d = number % 10;
      result = result * 10 + d;
      number /= 10;
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
  auto x = sln.reverseInteger(234);

  return EXIT_SUCCESS;
}