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
     * @param word: A string
     * @return: A boolean
     */
  bool exist(vector<vector<char>> &board, string &word)
  {
    // write your code here
    if (word.size() == 0)
      return true;
    int m = board.size();
    if (m == 0)
      return false;
    int n = board[0].size();
    if (n == 0)
      return false;

    // hash map to tell whether a position has been used/visited properly or not
    unordered_set<int> myS;

    // find a initial position
    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        // starting point
        if (backtrack(board, word, i, j, 0, myS))
          return true;
      }
    }
    return false;
  }

  bool backtrack(const vector<vector<char>> &board, const string &word, int row, int col, int w_idx, unordered_set<int> myS)
  {
    // move up
    if (!is_valid(board.size(), board[0].size(), row, col))
      return false;
    if (w_idx >= word.size())
      return false;
    if (board[row][col] != word[w_idx])
      return false;

    int idx_tmp = row * board[0].size() + col;
    if (myS.count(idx_tmp) > 0)
      return false;

    // cout << row << "\t" << col << "\t" << board[row][col] << "\t" << w_idx << "\n";
    // seems current position works, save it in myS first
    if (w_idx == word.size() - 1)
      return true;
    myS.insert(idx_tmp);
    // move up
    if (backtrack(board, word, row, col + 1, w_idx + 1, myS))
      return true;
    // move down
    if (backtrack(board, word, row, col - 1, w_idx + 1, myS))
      return true;
    // move left
    if (backtrack(board, word, row - 1, col, w_idx + 1, myS))
      return true;
    // move right
    if (backtrack(board, word, row + 1, col, w_idx + 1, myS))
      return true;
    myS.erase(idx_tmp);

    return false;
  }

  bool is_valid(int m, int n, int m_in, int n_in)
  {
    if (m_in < 0 || n_in < 0 || m_in >= m || n_in >= n)
      return false;
    return true;
  }
};

int main(int argc, char **argv)
{
  // initialization, data preparation
  vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'E', 'S'}, {'A', 'D', 'E', 'E'}};
  // string word = "ABCCED";
  string word = "ABCESEEEFS";
  // my solution
  Solution sln;

  // correct answer
  auto x = sln.exist(board, word);

  return EXIT_SUCCESS;
}