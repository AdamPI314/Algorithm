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
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n)
    {
        // write your code here
        // in place merge
        int i = m-1, j = n-1;
        int index = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (A[i] >= B[j])
                A[index--] = A[i--];
            else
                A[index--] = B[j--];
        }

        while( i>= 0) {
            A[index--] = A[i--];
        }
        while( j >= 0)
            A[index--] = B[j--];
        
    }
};

int main(int argc, char **argv)
{
    // initialization, data preparation
    int A[100] = {1, 2, 3, 6, 7};
    int B[5] = {3, 4, 5};

    // my solution
    Solution sln;

    sln.mergeSortedArray(A, 5, B, 3);

    // correct answer

    return EXIT_SUCCESS;
}