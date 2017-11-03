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
     * @param A a string
     * @param B a string
     * @return a boolean
     */
    bool stringPermutation(string &A, string &B)
    {
        // Write your code here
        int m = A.size();
        int n = B.size();

        if (m==n && m ==0)
            return true;
        if (m != n || m <= 0)
            return false;

        multiset<char> ASet;
        multiset<char> BSet;

        for (char x : A)
            ASet.insert(x);
        for (char x : B)
            BSet.insert(x);

        auto itA = ASet.begin();
        auto itB = BSet.begin();
        for (; itA != ASet.end() && itB != BSet.end(); ++itA, ++itB) {
            if (*itA != *itB)
                return false;
        } 
        return true;
    }
};

int main(int argc, char **argv)
{
    // initialization, data preparation
    string A = "abcd";
    string B = "bcad";

    // my solution
    Solution sln;
    auto x = sln.stringPermutation(A, B);

    // correct answer

    return EXIT_SUCCESS;
}
