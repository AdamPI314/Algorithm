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
  int singleNumberII(vector<int> &A)
  {
    if (A.size() == 0)
    {
      return -1;
    }
    int result = 0;
    vector<int> bits(32, 0);
    for (int i = 0; i < 32; i++)
    {
      for (int j = 0; j < A.size(); j++)
      {
        bits[i] += A[j] >> i & 1;
        bits[i] %= 3;
      }

      result |= (bits[i] << i);
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

  return EXIT_SUCCESS;
}