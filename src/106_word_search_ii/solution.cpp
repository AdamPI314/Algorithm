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
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
  vector<string> wordSearchII(vector<vector<char>> &board, vector<string> &words)
  {
    // write your code here
    vector<string> ans;

    // ensure that board[0] > 0
    if (board.size() == 0)
      return ans;

    size_t max_l = 0;
    vector<vector<int>> move = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    unordered_set<string> dict;
    unordered_set<string> prior_dict;
    unordered_set<string> result;

    for (auto x : words)
    {
      if (x.size() > max_l)
        max_l = x.size();
      dict.emplace(x);
    }
    for (auto x : dict)
    {
      for (int i = 0; i < x.size(); ++i)
      {
        auto str = x.substr(0, i + 1);
        if (prior_dict.find(str) == prior_dict.end())
          prior_dict.emplace(str);
      }
    }

    string tmp;
    unordered_set<int> path;
    for (int i = 0; i < board.size(); ++i)
    {
      for (int j = 0; j < board[0].size(); ++j)
      {
        backtrack(board, prior_dict, dict, move, max_l, i * board[0].size() + j, 0, tmp, path, result);
      }
    }

    for (auto s : result)
      ans.push_back(s);

    return ans;
  }

  void backtrack(const vector<vector<char>> &board, const unordered_set<string> &prior_dict, const unordered_set<string> &dict,
                 const vector<vector<int>> &move, int bound, int pos, int depth, string tmp,
                 unordered_set<int> path, unordered_set<string> &result)
  {
    // branch terminating, later
    if (depth > bound)
      return;
    // O(1), don't return yet, there may exist longer words
    if (dict.count(tmp) > 0)
    {
      if (result.find(tmp) == result.end())
        result.emplace(tmp);
    }

    // move one step deeper
    int row = pos / board[0].size();
    int col = pos % board[0].size();
    for (auto d : move)
    {
      int x = row + d[0], y = col + d[1];
      if (is_valid(board.size(), board[0].size(), x, y))
      {
        string next_tmp = tmp + board[x][y];
        int next_pos = x * board[0].size() + y;
        if (prior_dict.count(next_tmp) > 0 && path.find(next_pos) == path.end())
        {
          path.emplace(next_pos);
          backtrack(board, prior_dict, dict, move, bound, next_pos, depth + 1, next_tmp, path, result);
          path.erase(next_pos);
        }
      }
    }

    return;
  }

  bool is_valid(int m, int n, int row, int col)
  {
    if (row < 0 || col < 0 || row >= m || col >= n)
      return false;
    return true;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  vector<vector<char>> board = {{'d', 'o', 'a', 'f'}, {'a', 'g', 'a', 'i'}, {'d', 'c', 'a', 'n'}};
  vector<string> words = {"dog", "dad", "dgdg", "can", "again"};
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.wordSearchII(board, words);
  return EXIT_SUCCESS;
}