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

// class Solution
// {
// public:
//   /*
//      * @param A: An integer array
//      * @param target: An integer
//      * @return: An integer
//      */
//   int MinAdjustmentCost(vector<int> &A, int target)
//   {
//     // write your code here
//     if (A.size() <= 1)
//       return 0;
//     int gain = INT_MAX;
//     for (size_t i = 0; i < A.size(); ++i)
//     {
//       // number in the middle, hold current number fixed, starting point of chain reaction
//       gain = std::min(gain, backtrack(A, target, i - 1, true) + backtrack(A, target, i + 1, false));
//     }
//     return gain;
//   }

//   // indicator left(0, false) means, change leftmost number to fit the number on its left
//   // indicator right(1, true) meants, accommodate rithtmost number to fit the number on its right
//   int backtrack(vector<int> A, int target, int curr, bool indicator)
//   {
//     // boundary termination
//     if (curr < 0 || curr >= A.size())
//     {
//       return 0;
//     }

//     int gain = INT_MAX;

//     // change current number, at location curr, to fit previous number
//     if (indicator == false)
//     {
//       for (int diff = -1 * abs(target); diff <= abs(target); ++diff)
//       {
//         int tmp = abs(A[curr - 1] + diff - A[curr]);

//         auto A_curr_backup = A[curr];
//         A[curr] = A[curr - 1] + diff;
//         gain = std::min(gain, tmp + backtrack(A, target, curr + 1, indicator));
//         A[curr] = A_curr_backup;
//       }
//     }

//     // change current number, at location beg, to fit number after
//     if (indicator == true)
//     {
//       for (int diff = -1 * abs(target); diff <= abs(target); ++diff)
//       {
//         int tmp = abs(A[curr + 1] + diff - A[curr]);

//         auto A_curr_backup = A[curr];
//         A[curr] = A[curr + 1] + diff;
//         gain = std::min(gain, tmp + backtrack(A, target, curr - 1, indicator));
//         A[curr] = A_curr_backup;
//       }
//     }

//     return gain;
//   }
// };

class Solution
{
public:
  /*
     * @param A: An integer array
     * @param target: An integer
     * @return: An integer
     */
  int MinAdjustmentCost(vector<int> &A, int target)
  {
    // since the number in the range 0 to 100, can turn this problem to
    // "shortest path" problem, use dijkstra algorithm, or bellman-ford algorithm
    // dijkstra use a priority queue to greedily relax the outgoing edges of a greedy vertex
    // that has not been processed yet
    // while on the contrast, bellman-ford relax all edges |V|-1 times, eventually, all vertices will
    // have the correct distance, bellman-ford is more versatile than dijkstra, thus can be applied to
    // a wider range of problems with loose input

    // use bellman-ford algorithm here
    int n = A.size();
    int magic_n = 100;
    vector<vector<int>> f(n + 1, vector<int>(magic_n + 1, INT_MAX));

    // sort of reference length
    for (size_t i = 0; i <= magic_n; ++i)
      f[0][i] = 0;

    // the basic idea is bellman-ford
    // for nodes
    //  for edges
    for (size_t i = 1; i <= n; ++i)
    {
      for (int j = 0; j <= magic_n; ++j)
      {
        // if previous node is availabe
        if (f[i - 1][j] != INT_MAX)
        {
          for (int k = 0; k <= magic_n; ++k)
          {
            // compare node i-1 to node i with edge weight k-j
            // if j->k is an edge
            if (abs(j - k) <= target)
            {
              // find a shorter path, set current value to k, what's the cost
              // cost function here
              f[i][k] = std::min(f[i][k], f[i - 1][j] + abs(A[i - 1] - k));
            }
          }
        }
      }
    }

    int ans = INT_MAX;
    for (size_t i = 0; i <= magic_n; ++i)
      ans = std::min(ans, f[n][i]);

    return ans;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  vector<int> A = {1, 4, 2, 3};
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.MinAdjustmentCost(A, 1);
  return EXIT_SUCCESS;
}