#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
  public:
    void solveSudoku(vector<vector<char>>& board) {
      stack<vector<vector<char>>> states;
      states.push(board);
      int emptyCount = 0;
      vector<vector<int>> emptyPos;
      for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
          if (board[i][j] == '.') {
            ++emptyCount;
            vector<int> temp = {i, j};
            emptyPos.push_back(temp);
          }
        }
      }
      char path[board.size() * board.size()];
      int top = -1;
      path[++top] = '0';

      while (top >= 0) {
        ++path[top];
        if (path[top] > '9') {
          --top;
          states.pop();
          continue;
        }
        vector<vector<char>> state = states.top();
        int i = emptyPos[top][0];
        int j = emptyPos[top][1];
        state[i][j] = path[top];
        // int i, j;
        // for (i = 0; i < state.size(); ++i) {
        //   for (j = 0; j < state[i].size(); ++j) {
        //     if (state[i][j] == '.') {
        //       state[i][j] = path[top];
        //       break;
        //     }
        //   }
        //   if (j != state[i].size()) {
        //     break;
        //   }
        // }
        bool isValid = this->isValid(state, i, j);
        if (isValid) {
          if (top == emptyCount - 1) {
            board = state;
            return;
          }
          path[++top] = '0';
          states.push(state);
        }
      }
    }
  private:
    bool isValid(vector<vector<char>>& board, int row, int col) {
      for (int i = 0; i < board.size(); ++i) {
        if (i != row && board[i][col] == board[row][col]) {
          return false;
        }
        if (i != col && board[row][i] == board[row][col]) {
          return false;
        }
      }
      int rowStart = (row / 3) * 3;
      int colStart = (col / 3) * 3;
      for (int i = rowStart; i < rowStart + 3; ++i) {
        for (int j = colStart; j < colStart + 3; ++j) {
          if (i == row && j == col) {
            continue;
          }
          if (board[i][j] == board[row][col]) {
            return false;
          }
        }
      }
      return true;
    }

    void print(vector<vector<char>>& board) {
      for (auto row: board) {
        for (auto col: row) {
          std::cout << col;
        }
        std::cout << std::endl;
      }
      std::cout << "----------" << std::endl;
    }
};

int main() {
  Solution sln;
  vector<vector<char>> board = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
  };
  sln.solveSudoku(board);
  for (auto row: board) {
    for (auto col: row) {
      std::cout << col;
    }
    std::cout << std::endl;
  }

  return 0;
}
