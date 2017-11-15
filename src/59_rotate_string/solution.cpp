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
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     */
  void rotateString(string &str, int offset)
  {
    // write your code here
    int n = str.size();
    if (n == 0 || offset <= 0)
      return;
    if (offset >= n)
      offset = offset % n;

    // linear time complexity const * O(n)
    // 2 tranpose/reverse and 1 mirror image operation
    // in chinese, "三步翻转法"
    // http://blog.csdn.net/u010016196/article/details/45126853
    for (int i = 0, j = n - offset - 1; i < j; ++i, --j)
    {
      swap(str[i], str[j]);
    }
    for (int i = n - offset, j = n - 1; i < j; ++i, --j)
    {
      swap(str[i], str[j]);
    }
    // mirror image
    for (int i = 0, j = n - 1; i < j; ++i, --j)
    {
      swap(str[i], str[j]);
    }
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  string str = "abcdefg";
  int offset = 3;
  // my solution
  Solution sln;

  // correct answer
  sln.rotateString(str, offset);

  return EXIT_SUCCESS;
}