#include <iostream>
#include <utility>
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

bool cmp(const pair<int, int> &x, const pair<int, int> &y)
{
    return x.first != y.first ? x.first < y.first : x.second > y.second;
}

class Solution
{
  public:
    /**
     * @param envelopes a number of envelopes with widths and heights
     * @return the maximum number of envelopes
     */
    int maxEnvelopes(vector<pair<int, int>> &envelopes)
    {
        // Write your code here
        int n = envelopes.size();
        if (n == 0)
        {
            return 0;
        }

        sort(envelopes.begin(), envelopes.end(), cmp);
        // dp save (max - 1) up to current point, including current point
        vector<int> dp(n), height(n + 1, INT_MAX);
        for (int i = 0; i < n; i++)
        {
            // replace the first value that is greater than envelopes[i].second, height is ordered
            // if envelopes[i].second is greater than all previous value, append it to the end

            // As a result, height store all the y-axis value of points to which x-axis < current-x-axis,
            // y-axis < current-y-axis
            
            // we got to think about the future, how current node will affect the upcoming node,
            // for example, we have {{1,10},{1,9},{1,8},{2,100}}, obviously, the last envelop can tolerate envelops before
            // But, the first three cannot tolerate each other, which means, up to {1,8}, just need to keep {1,8},
            // discard {1,10}, {1,9} will not affect the number of envelops {2,100} can be fit in, that number is 1 whatever
            // Keep the lowest number, replace the first one that's greater than it, is a low limit guarantee strategy.
            int k = lower_bound(height.begin(), height.end(), envelopes[i].second) - height.begin();
            height[k] = envelopes[i].second;

            dp[i] = k;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, dp[i]);
        }
        return ans + 1;
    }
};

int main(int argc, char **argv)
{
    // initialization, data preparation
    vector<pair<int, int>> envelopes = {{15, 8}, {2, 20}, {2, 14}, {4, 17}, {8, 19}, {8, 9}, {5, 7}, {11, 19}, {8, 11}, {13, 11}, {2, 13}, {11, 19}, {8, 11}, {13, 11}, {2, 13}, {11, 19}, {16, 1}, {18, 13}, {14, 17}, {18, 19}};
    // my solution
    Solution sln;
    auto result = sln.maxEnvelopes(envelopes);

    // correct answer

    return EXIT_SUCCESS;
}
