#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void solveSudoku(vector<vector<char>>& board) {
    int size = 9;
    vector<vector<int>> rows(size, vector<int>(size, 0));
    vector<vector<int>> cols(size, vector<int>(size, 0));
    vector<vector<int>> subs(size, vector<int>(size, 0));
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
        if (board[i][j] != '.') {
          int value = board[i][j] - '1';
          rows[i][value] = 1;
          cols[j][value] = 1;
          subs[(i / 3) * 3 + j / 3][value] = 1;
        }
      }
    }
    solve(board, rows, cols, subs, 0, 0);
  }

  bool solve(vector<vector<char>>& board, vector<vector<int>>& rows,
             vector<vector<int>>& cols, vector<vector<int>>& subs, int startI,
             int startJ) {
    for (int i = startI; i < board.size(); ++i) {
      int j = (i == startI) ? startJ : 0;
      for (; j < board.size(); ++j) {
        if (board[i][j] != '.') {
          continue;
        }
        int subIndex = (i / 3) * 3 + j / 3;
        for (int k = 0; k < board.size(); ++k) {
          if (rows[i][k] != 0 || cols[j][k] != 0 || subs[subIndex][k] != 0) {
            continue;
          }
          board[i][j] = k + '1';
          rows[i][k] = 1;
          cols[j][k] = 1;
          subs[subIndex][k] = 1;
          bool can = solve(board, rows, cols, subs, i, j + 1);
          if (can) {
            return true;
          } else {
            board[i][j] = '.';
            rows[i][k] = 0;
            cols[j][k] = 0;
            subs[subIndex][k] = 0;
          }
        }
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution sln;
  vector<vector<char>> board;
  board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
           {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
           {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
           {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
           {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
           {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
           {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
           {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
           {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  sln.solveSudoku(board);
  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[i].size(); ++j) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}