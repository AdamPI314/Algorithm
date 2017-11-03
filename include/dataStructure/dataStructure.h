#ifndef _DATASTRUCTURE_H__
#define _DATASTRUCTURE_H__

namespace dataStructure
{
/*
 * Definition for a point.
 */
struct Point
{
	int x = 0;
	int y = 0;
	Point() {}
	Point(int a, int b) : x(a), y(b) {}
};

class ListNode
{
  public:
	int val;
	ListNode *next;
	ListNode(int val)
	{
		this->val = val;
		this->next = nullptr;
	}
};
};

#endif