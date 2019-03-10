#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    bool exist(vector<vector<char>>& board, string word) {
      if (word.size() <= 0 || board.size() <= 0) {
        return false;
      }
      bool ret = false;
      for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
          if (board[i][j] == word[0]) {
            char temp = board[i][j];
            board[i][j] = '.';
            string copyWord(word.begin() + 1, word.end());
            ret = subExist(board, copyWord, i, j);
            if (ret) {
              return ret;
            }
            board[i][j] = temp;
          }
        }
      }
      return ret;
    }

    bool subExist(vector<vector<char>>& board, string& word, int iStart, int jStart) {
      if (word.size() <= 0) {
        return true;
      }
      bool ret = false;
      int i = -1, j = -1;
      if (iStart - 1 >= 0 && board[iStart - 1][jStart] == word[0]) {
        i = iStart - 1;
        j = jStart;
        ret = next(board, word, i, j);
        if (ret) {
          return ret;
        }
      }
      if (iStart + 1 < board.size() && board[iStart + 1][jStart] == word[0]) {
        i = iStart + 1;
        j = jStart;
        ret = next(board, word, i, j);
        if (ret) {
          return ret;
        }
      }
      if (jStart - 1 >= 0 && board[iStart][jStart - 1] == word[0]) {
        i = iStart;
        j = jStart - 1;
        ret = next(board, word, i, j);
        if (ret) {
          return ret;
        }
      }
      if (jStart + 1 < board[0].size() && board[iStart][jStart + 1] == word[0]) {
        i = iStart;
        j = jStart + 1;
        ret = next(board, word, i, j);
        if (ret) {
          return ret;
        }
      }
      return false;
    }

    bool next(vector<vector<char>>& board, string& word, int i, int j) {
      char temp = board[i][j];
      board[i][j] = '.';
      string copyWord(word.begin() + 1, word.end());
      bool ret = subExist(board, copyWord, i, j);
      board[i][j] = temp;

      return ret;
    }
};

int main() {
  Solution sln;
  vector<vector<char>> board;
  board = {
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','D','E','E'}
  };
  cout << sln.exist(board, "ABCCED") << endl;
  cout << sln.exist(board, "SEE") << endl;
  cout << sln.exist(board, "ABCB") << endl;

  return 0;
}
