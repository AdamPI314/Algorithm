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
     * @param str: A string
     * @return: An integer
     */
  int atoi(string &str)
  {
    // write your code here
    int n = str.size();
    if (n == 0)
      return 0;

    long int tmp = 0;
    int i = 0;
    while (i < n && str[i] == ' ')
      ++i;
    if (str[i] == '-')
    {
      i += 1;
      while (i < n)
      {
        if (str[i] < '0' || str[i] > '9')
          return tmp;
        tmp *= 10;
        tmp -= (str[i] - '0');
        if (tmp < INT_MIN)
          return INT_MIN;
        ++i;
      }
      return int(tmp);
    }
    else
    {
      if (str[i] == '+')
        ++i;
      while (i < n)
      {
        if (str[i] < '0' || str[i] > '9')
          return tmp;
        tmp *= 10;
        tmp += (str[i] - '0');
        if (tmp > INT_MAX)
          return INT_MAX;
        ++i;
      }
      return int(tmp);
    }
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  string str = "10";
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.atoi(str);

  return EXIT_SUCCESS;
}