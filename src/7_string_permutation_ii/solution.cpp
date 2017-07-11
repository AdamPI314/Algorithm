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
     * @param str a string
     * @return all permutations
     */
    vector<string> stringPermutation2(string& str) {
        // Write your code here
        vector<string> result;
        int n = str.size();
        if (n <= 0 ) {
            result.push_back(string(""));
          return result;
        }

        map<char, int> hash;
        for (char c : str)
          hash[c] += 1;

        string tmp(n, ' ');
        helper(hash, tmp, result, n-1);

        return result;
    }

    void helper(map<char, int> hash, string tmp, vector<string> &result, int index) {
      if (index == -1) {
        result.push_back(tmp);
        return;
      }

      // arrow guard
      for (auto &x : hash) {
          if (x.second <= 0)
            continue;
          else {
              tmp[index] = x.first;
              x.second -= 1;
              helper(hash, tmp, result, index - 1);
              // same level
              x.second += 1;

          }

      }
      
      return;
    }

};

int main(int argc, char** argv)
{
  // initialization, data preparation
  string str = "abb";

  // my solution
  Solution sln;

  auto result = sln.stringPermutation2(str);
  // correct answer
  

  return EXIT_SUCCESS;

}