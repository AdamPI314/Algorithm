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

class Solution
{
  public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    /*
    题意： 正则表达式匹配，'.'可以匹配任意字符，'*'可以匹配任意个(可以为0)'*'之前的字符
    不考虑'*'的话，题目变成简单的匹配。考虑'*'，可能产生的情况有匹配0、1、2…个字符
    因此可以使用递归或dp或其他方法解决
    */
    bool isMatch(string s, string p)
    {
        if (s.size() == 0) {
            // p.size() is zero or p is X*X*
            if (p.size() & 1)
                return false;
            for (std::size_t i = 1; i < p.size(); i += 2) {
                if (p[i] != '*')
                    return false;
            }
            return true;
        }
        if (p.size() == 0)
            return false;
        // if p has '*', gonna check match 0 time, 1 time, 2 times or more times
        if (p.size() > 1 && p[1] == '*') {
            if (compare(s[0], p[0])) {
                return isMatch(s, p.substr(2)) || isMatch(s.substr(1), p);
            }
            else
                return isMatch(s, p.substr(2));
        }
        else {
            if (compare(s[0], p[0]))
                return isMatch(s.substr(1), p.substr(1));
            else
                return false;
        }

    }

    bool compare(char c, char p) {
        if (p == '.' || c == p)
            return true;
        return false;
    }
    
};

int main(int argc, char **argv)
{
    // initialization, data preparation

    // my solution
    Solution sln;

    // correct answer
    std::string s = "aa";
    std::string p = "a";
    auto x = sln.isMatch(s, p);

    return EXIT_SUCCESS;
}