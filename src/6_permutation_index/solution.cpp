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

// http://www.geekviewpoint.com/java/numbers/permutation_index

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        if (A.empty())
            return 0;

        long long result = 1;
        // weight like, 4!, 3!, 2!, 1!, 0!, since 1! = 0! = 1, we start from 1!, position the 2nd to the last
        long long weight = 1;

        long long numSuccessor = 0;
        // start from the most right
        for (long long i = A.size() - 2; i >=0; --i) {
            numSuccessor = 0;
            for (long long j = i + 1; j < A.size(); ++j) {
                if (A[j] < A[i])
                    ++numSuccessor;
            }
            result += weight * numSuccessor;
            // update weight
            weight *= (A.size() - i);

        }


        return result;
    }
};

int main(int argc, char** argv)
{
  // initialization, data preparation
  vector<int> A = {1, 2, 4};
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.permutationIndex(A);

  return EXIT_SUCCESS;

}