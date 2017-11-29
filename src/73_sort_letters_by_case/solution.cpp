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
     * @param chars: The letter array you should sort by Case
     * @return: nothing
     */
  void sortLetters(string &chars)
  {
    // write your code here
    // similar idea to quicksort
    int n = chars.size();
    if (n <= 1)
      return;
    int left = 0, right = n - 1;
    while (left <= right)
    {
      while (left <= right && chars[left] <= 'z' && chars[left] >= 'a')
        ++left;
      while (left <= right && chars[right] >= 'A' && chars[right] <= 'Z')
        --right;

      if (left <= right)
      {
        std::swap(chars[left], chars[right]);
        ++left;
        --right;
      }
    }
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  string chars = "abAcD";
  // my solution
  Solution sln;

  // correct answer
  sln.sortLetters(chars);
  return EXIT_SUCCESS;
}