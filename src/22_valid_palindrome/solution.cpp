#include <iostream>
#include <vector>
#include <list>
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
#include <numeric>
#include <functional>

#include "../../include/fileIO/fileIO.h"
#include "../../include/dataStructure/dataStructure.h"
#include "../../include/misc/misc.h"

using namespace std;

class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        // Write your code here
		if (s.size() <= 1)
			return true;
		int begin = 0, end = s.size() - 1;

		int lower_captital_distance = abs('A' - 'a');
		for (; begin < end;) 
		{
			if (!isAlphaNumeric(s[begin]))
			{
				++begin;
				continue;
			}
			if (!isAlphaNumeric(s[end]))
			{
				--end;
				continue;
			}
			// both are valid
			if (s[begin] == s[end] || abs(s[begin] - s[end]) == lower_captital_distance)
			{
				++begin;
				--end;
			}
			else
				return false;
		}
		return true;
    }

	bool isAlphaNumeric(char c) 
	{
		if ((c >= '0' && c <= '9') || ( c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			return true;
		return false;
	}
};

int main(int argc, char **argv)
{
	// initialization, data preparation
	string s = "A man, a plan, a canal: Panama";
	// my solution
	Solution sln;
	auto result = sln.isPalindrome(s);

	// correct answer

	return EXIT_SUCCESS;
}