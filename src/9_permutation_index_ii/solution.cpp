#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>
#include <cstdlib>

#include "../../include/fileIO/fileIO.h"
#include "../../include/dataStructure/dataStructure.h"
#include "../../include/misc/misc.h"

using namespace std;

class Solution
{
public:
  /**
     * @param A an integer array
     * @return a long integer
     */
  long long permutationIndexII(vector<int> &A)
  {
    // Write your code here
    if (A.size() <= 1)
      return A.size();

    // maintain a map<int, int>
    map<int, long long> hash;
    hash.emplace(A.back(), 1);
    // maintain a denominator
    long long denominator = 1;
    long long localDenominator = 1;

    // start from 1, what the problem requires
    long long index = 1;
    long long weight = 1;

    for (int i = A.size() - 2; i >= 0; --i)
    {
      hash[A[i]] += 1;
      // every insert update denominator
      denominator *= hash[A[i]];

      // find value that strictly less than A[i]
      for (auto it = hash.begin(); it != hash.end(); ++it)
      {
        if (it->first >= A[i])
          break;
        else
        {
          // calculate local denominator
          // consider the swap of A[i] and it->first
          localDenominator = denominator;
          if (it->second >= 2)
            localDenominator /= it->second;
          // update
          index += (weight / localDenominator);
        }
      }

      weight *= (A.size() - i);
    }

    return index;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  vector<int> A = {22,9,9,11,11,9,14,8,9,9,9,8,6,9,9,9,9,10,10,20};
  // my solution
  Solution sln;
  auto result = sln.permutationIndexII(A);

  // correct answer

  return EXIT_SUCCESS;
}
