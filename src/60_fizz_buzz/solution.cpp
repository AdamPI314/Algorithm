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
     * @param n: An integer
     * @return: A list of strings.
     */
  vector<string> fizzBuzz(int n)
  {
    // write your code here
    vector<string> fb(n);
    for (int i = 1; i <= n; ++i)
    {
      bool is3 = (i % 3 == 0);
      bool is5 = (i % 5 == 0);
      if (is3 && is5)
        fb[i - 1] = "fizz buzz";
      else if (is3)
        fb[i - 1] = "fizz";
      else if (is5)
        fb[i - 1] = "buzz";
      else
        fb[i - 1] = std::to_string(i);
    }

    return fb;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  int n = 15;
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.fizzBuzz(n);
  return EXIT_SUCCESS;
}