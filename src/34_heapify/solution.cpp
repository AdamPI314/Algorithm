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

// class MinHeap
// {
//   public:
//     // remember heap got to be a complete tree, so A[i]'s children index, if exist, must be 2*i+1 or 2*i+2
//     vector<int> data;
//     int capacity = 0;
//     int heap_size = 0;

//   public:
//     MinHeap(int _capacity)
//     {
//         data.resize(_capacity);
//         capacity = _capacity;
//         heap_size = 0;
//     }
//     int parent(int i)
//     {
//         return (i - 1) / 2;
//     }
//     int left(int i)
//     {
//         return 2 * i + 1;
//     }
//     int right(int i)
//     {
//         return 2 * i + 2;
//     }
//     // return minimum value
//     int getMin()
//     {
//         return data[0];
//     }
//     int extractMin()
//     {
//         if (heap_size == 1 )
//         {
//             --heap_size;
//             return data[0];
//         }
//         // store the minimum, then remove if from heap
//         int top = data[0];
//         data[0] = data[--heap_size];
//         MinHeapify(0);
//         return top;
//     }
//     // This function deletes key at index i. It first reduced value to minus
//     // infinite, then calls extractMin()
//     void deleteKey(int key)
//     {
//         decreaseKey(0, INT_MIN);
//         extractMin();
//     }
//     void insertKey(int key)
//     {
//         if (heap_size >= capacity)
//         {
//             std::cerr << "heap size is bigger than capacity, overflow!!!" << endl;
//             return;
//         }
//         ++heap_size;
//         // first insert the key at the end
//         int i = heap_size - 1;
//         data[i] = key;
//         while ( i != 0 && data[i] < data[parent(i)])
//         {
//             std::swap(data[parent(i)], data[i]);
//             i = parent(i);
//         }
//     }
//     // Decreases value of key at index 'i' to new_val.  It is assumed that
//     // new_val is smaller than harr[i].
//     void decreaseKey(int i, int new_val)
//     {
//         data[i] = new_val;
//         while (i != 0 && data[i] < data[parent(i)])
//         {
//             swap(data[i], data[parent(i)]);
//             i = parent(i);
//         }
//     }
//     // A recursive method to heapify a subtree with root at given index
//     // This method assumes that the subtrees are already heapified
//     void MinHeapify(int i)
//     {
//         int l = left(i);
//         int r = right(i);
//         int smallest = i;
//         // find the smallest index
//         if (l < heap_size && data[l] < data[smallest])
//             smallest = l;
//         if (r < heap_size && data[r] < data[smallest])
//             smallest = r;
//         //
//         if (smallest != i)
//         {
//             std::swap(data[i], data[smallest]);
//             MinHeapify(smallest);
//         }
//     }
// };

// class Solution
// {
//   public:
//     /**
//      * @param A: Given an integer array
//      * @return: void
//      */
//     void heapify(vector<int> &A)
//     {
//         // write your code here
//         MinHeap mh(A.size());
//         for (auto x : A)
//             mh.insertKey(x);
//         A.assign(mh.data.begin(), mh.data.end());
//     }
// };

class Solution
{
  public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    // A recursive method to heapify a subtree with root at given index
    // This method assumes that the subtrees are already heapified
    void min_heapify(vector<int> &A, int i, int len)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest = i;
        if (l < len)
            if (A[l] < A[i])
                largest = l;

        if (r < len)
            if (A[r] < A[largest])
                largest = r;

        if (largest != i)
        {
            swap(A[i], A[largest]);
            min_heapify(A, largest, len);
        }
    }
    void heapify(vector<int> &A)
    {
        // write your code here
        int len = A.size();
        // for all none leaf nodes, len/2 gives the index of first leaf
        // since min_heapify assume subtrees are heapified
        for (int i = len / 2; i >= 0; i--)
            min_heapify(A, i, len);
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
