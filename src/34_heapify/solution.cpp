#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
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

class MinHeap
{
  public:
    vector<int> data;

  public:
    MinHeap(const vector<int> &A)
    {
        data.assign(A.begin(), A.end());
    }
    int parent(i)
    {
        return (i - 1) / 2;
    }
    int left(i)
    {
        return 2 * i + 1;
    }
    int rifht(i)
    {
        return 2 * i + 2;
    }
    // return minimum value
    int getMin()
    {
        return data[0];
    }
    void pop()
    {
    }
    void deleteKey(int key)
    {
    }
    void insertKey(int key)
    {
    }
    // Decreases value of key at index 'i' to new_val.  It is assumed that
    // new_val is smaller than harr[i].
    void decreaseKey(i, int new_val)
    {
        data[i] = new_val;
    }
};

class Solution
{
  public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A)
    {
        // write your code here
    }
};

int main(int argc, char **argv)
{
    // initialization, data preparation
    vector<int> A = {3, 2, 1, 4, 5};
    // my solution
    Solution sln;
    sln.heapify(A);

    // correct answer

    return EXIT_SUCCESS;
}