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

//  Definition of Interval:
class Interval
{
public:
  int start, end;
  Interval(int start, int end)
  {
    this->start = start;
    this->end = end;
  }
};

class Solution
{
public:
  /*
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */

  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
  {
    if (intervals.size() == 0)
    {
      intervals.push_back(newInterval);
      return intervals;
    }
    vector<Interval> ans;
    vector<int> idx;

    for (int i = 0; i < intervals.size(); ++i)
    {
      if (hasOverlap(intervals[i], newInterval))
        idx.push_back(i);
    }

    if (idx.size() == 0)
    {
      // in the front
      if (newInterval.end < intervals.front().start)
      {
        intervals.insert(intervals.begin(), newInterval);
        return intervals;
      }
      // in the back
      else if (newInterval.start > intervals.back().end)
      {
        intervals.push_back(newInterval);
        return intervals;
      }
      // in the middle
      else
      {
        for (int i = 0; i < intervals.size(); ++i)
        {
          if (intervals[i].start > newInterval.start)
          {
            intervals.insert(intervals.begin() + i, newInterval);
            return intervals;
          }
        }
      }
    }

    // has overlap
    for (int i = 0; i < idx.front(); ++i)
    {
      ans.push_back(intervals[i]);
    }
    // handle overlap
    int start = min(intervals[idx.front()].start, newInterval.start);
    int end = max(intervals[idx.back()].end, newInterval.end);
    ans.push_back(Interval(start, end));
    //finish up
    for (int i = idx.back() + 1; i < intervals.size(); ++i)
    {
      ans.push_back(intervals[i]);
    }

    return ans;
  }
  bool hasOverlap(const Interval &i1, const Interval &i2) const
  {
    if (i1.start <= i2.start && i1.end >= i2.start)
      return true;
    else if (i2.start <= i1.start && i2.end >= i1.start)
      return true;
    else
      return false;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  vector<Interval> intervals;
  intervals.push_back(Interval(1, 2));
  intervals.push_back(Interval(5, 9));

  Interval newInterval(9, 11);
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.insert(intervals, newInterval);

  return EXIT_SUCCESS;
}