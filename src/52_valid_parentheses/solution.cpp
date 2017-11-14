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
  /*
     * @param s: A string
     * @return: whether the string is a valid parentheses
     */
  bool isValidParentheses(const string &s)
  {
    stack<char> myS;
    for (int i = 0; i < s.size(); ++i)
    {
      if (isLeft(s[i]))
        myS.push(s[i]);
      else if (isRight(s[i]))
      {
        if (myS.empty())
          return false;
        auto l = myS.top();
        myS.pop();
        if (!isValidChar(l, s[i]))
          return false;
      }
    }
    if (myS.empty())
      return true;
    else
      return false;
  }

  bool isLeft(const char &c)
  {
    if (c == '{' || c == '(' || c == '[')
      return true;
    else
      return false;
  }

  bool isRight(const char &c)
  {
    if (c == '}' || c == ')' || c == ']')
      return true;
    else
      return false;
  }

  bool isValidChar(const char &c1, const char &c2)
  {
    if (c1 == '(' && c2 == ')')
      return true;
    if (c1 == '{' && c2 == '}')
      return true;
    if (c1 == '[' && c2 == ']')
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
  string s = "[][)";
  auto x = sln.isValidParentheses(s);

  return EXIT_SUCCESS;
}