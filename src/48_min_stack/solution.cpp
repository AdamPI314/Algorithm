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

class MinStack
{
public:
  stack<int> stk, minstk;

  MinStack() {}
  /*
    * @param a: An integer
    */
  MinStack(int a)
  {
    // do intialization if necessary
  }
  /*
     * @param number: An integer
     * @return: nothing
     */
  void push(int number)
  {
    // write your code here
    stk.push(number);
    if (minstk.empty() || number <= minstk.top())
      minstk.push(number);
  }

  /*
     * @return: An integer
     */
  int pop()
  {
    // write your code here
    int top = stk.top();
    stk.pop();
    if (top == minstk.top())
      minstk.pop();
    return top;
  }

  /*
     * @return: An integer
     */
  int min()
  {
    // write your code here
    return minstk.top();
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation

  // my solution
  MinStack sln(10);

  // correct answer

  return EXIT_SUCCESS;
}