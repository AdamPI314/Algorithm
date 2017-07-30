#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>
// #include <stack>
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


// I don't think the guy who made this problem don't understand how stack and queue work
// Why someone even want to implement stack with two queue!
class Stack {
public:
	queue<int> q1;
	queue<int> q2;

public:
    // Push a new item into the stack
    void push(int x) {
		if (q1.empty()) {
			q1.push(x);
			// move all element in q2 to the back of q1's new element
			while (!q2.empty()) {
				auto tmp = q2.front();
				q2.pop();
				q1.push(tmp);
			}
		}
		// q2 must be empty
		else {
			q2.push(x);
			while(!q1.empty()) {
				auto tmp = q1.front();
				q1.pop();
				q2.push(tmp);
			}
		}
    }

    // Pop the top of the stack
    void pop() {
        // Write your code here
		if (!q1.empty())
			q1.pop();
		else
			q2.pop();
    }

    // Return the top of the stack
    int top() {
        // Write your code here
		if (!q1.empty())
			return q1.front();
		else
			return q2.front();
    }

    // Check the stack is empty or not.
    bool isEmpty() {
        // Write your code here
		return (q1.empty() && q2.empty());
    }
};


int main(int argc, char **argv)
{
	// initialization, data preparation

	// my solution
	Stack sln;

	// correct answer

	return EXIT_SUCCESS;
}