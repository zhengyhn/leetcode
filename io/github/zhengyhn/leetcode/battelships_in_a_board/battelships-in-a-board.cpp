#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int adjacentCount(vector<vector<char>>& board, int i, int j) {
      int count = 0;
      if ((i - 1) >= 0 && board[i - 1][j] == 'X') {
        ++count;
      }
      if ((j - 1) >= 0 && board[i][j - 1] == 'X') {
        ++count;
      }
      return count;
    }

    int countBattleships(vector<vector<char>>& board) {
      int count = 0;
      for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
          if (board[i][j] == 'X') {
            ++count;
            if (this->adjacentCount(board, i, j) > 0) {
              --count;
            }
          }
        }
      }
      return count;
    }
};

int main() {
  Solution sln;
  vector<vector<char>> board = {{'X', '.', 'X'}};
  // vector<vector<char>> board = {{'X', '.', '.', 'X'}, {'.', '.', '.', 'X'}, {'.', '.', '.', 'X'}};
  // vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'.', '.', '.', '.'}, {'X', '.', 'X', '.', 'X'}, {'X', '.', 'X', '.', 'X'}};

  std::cout << sln.countBattleships(board) << std::endl;

  return 0;
}
