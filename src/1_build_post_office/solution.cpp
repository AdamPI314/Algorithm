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

class Solution {
public:
    /**
     * @param grid a 2D grid
     * @return an integer
     */
    int shortestDistance(vector<vector<int>>& grid) {
        // Write your code here
        // dijkstra algorithm
        int m = grid.size();
        if ( m == 0 )
            return -1;
        int n = grid[0].size();
        if (n == 0 || !haveZero(grid))
            return -1;
            
        vector<int> sumRow(m, 0);
        vector<int> sumCol(n, 0);

        // sum over cols and rows
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++sumRow[i];
                    ++sumCol[j];
                }
                
            }
        }
        vector<int> costRow(m, 0);
        vector<int> costCol(n, 0);
        //calculate distance till point i from all points before
        calculateSumDistance(sumRow, costRow);
        calculateSumDistance(sumCol, costCol);
        
        // iterate over all grid points, find the smallest cost
        int cost = INT_MAX;
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j){
                if (grid[i][j] == 0 && costRow[i] + costCol[j] < cost)
                    cost = costRow[i] + costCol[j];
            }
        }
        
        return cost;
        
    }
    void calculateSumDistance(const vector<int> &a, vector<int> & cost) {
        // calculate the cost to current point i
        int n = a.size();
        cost[n-1] = 0;
        // points before i, integral, the first value is gonna be zero
        // distance till i
        // a[i] = (i-0)*a[0] + (i-1)*a[1]  + (i-2)*a[2] + ...
        vector<int> tmp(n, 0);
        vector<int> integral(n, 0);
        
        tmp[0] = a[0];
        for(size_t i = 1; i<n; ++i) {
            tmp[i] = tmp[i-1] + a[i];
        }
        for(size_t i = 1; i<n; ++i) {
            integral[i] = integral[i-1] + tmp[i-1];
        }
        for(size_t i = 0; i<n; ++i) {
            cost[i] = integral[i];
        }
        // points after i
        tmp[n-1] = a[n-1];
        for(int i = n-2; i>=0; --i) {
            tmp[i] = tmp[i+1] + a[i];
        }
        integral[n-1] = 0;
        for(int i = n-2; i>=0; --i) {
            integral[i] = integral[i+1] + tmp[i+1];
        }
        
        for(size_t i = 0; i<n; ++i) {
            cost[i] += integral[i];
        }
    }
    
    bool haveZero(const vector<vector<int> >& grid) {
        for(size_t i = 0; i < grid.size(); ++i) {
            for(size_t j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0)
                    return true;
            }
        }
        return false;
    }
};

int main(int argc, char** argv)
{
  // initialization, data preparation

  // my solution
  Solution sln;

  // correct answer
  

  return EXIT_SUCCESS;

}