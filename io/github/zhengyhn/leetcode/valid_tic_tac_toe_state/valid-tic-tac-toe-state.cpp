#include <iostream>
#include <queue>

using namespace std;

class Solution {
  public:
    bool validTicTacToe(vector<string>& board) {
      int oCount = 0;
      int xCount = 0;
      char first;
      for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
          if (board[i][j] == 'O') {
            ++oCount;
            first = 'O';
          }
          if (board[i][j] == 'X') {
            ++xCount;
            first = 'X';
          }
        }
      }
      if (xCount + oCount == 1 && first != 'X') {
        return false;
      }
      if (xCount - oCount > 1 || oCount - xCount > 0) {
        return false;
      }
      int xRepeat = 0;
      int oRepeat = 0;
      if (board[0][0] != ' ' && board[0][0] == board[0][1] && board[0][1] == board[0][2]) {
        xRepeat += board[0][0] == 'X' ? 1 : 0;
        oRepeat += board[0][0] == 'O' ? 1 : 0;
      }
      if (board[2][0] != ' ' && board[2][0] == board[2][1] && board[2][1] == board[2][2]) {
        xRepeat += board[2][0] == 'X' ? 1 : 0;
        oRepeat += board[2][0] == 'O' ? 1 : 0;
      }
      if (board[0][0] != ' ' && board[0][0] == board[1][0] && board[1][0] == board[2][0]) {
        xRepeat += board[0][0] == 'X' ? 1 : 0;
        oRepeat += board[0][0] == 'O' ? 1 : 0;
      }
      if (board[0][2] != ' ' && board[0][2] == board[1][2] && board[1][2] == board[2][2]) {
        xRepeat += board[0][2] == 'X' ? 1 : 0;
        oRepeat += board[0][2] == 'O' ? 1 : 0;
      }
      if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        xRepeat += board[0][0] == 'X' ? 1 : 0;
        oRepeat += board[0][0] == 'O' ? 1 : 0;
      }
      if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        xRepeat += board[0][2] == 'X' ? 1 : 0;
        oRepeat += board[0][2] == 'O' ? 1 : 0;
      }
      if (xRepeat > 0 && oRepeat > 0) {
        return false;
      }
      if (oRepeat > 0 && xCount >= oCount) {
        return false;
      }
      if (xRepeat > 0 && xCount == oCount) {
        return false;
      }
      return true;
    }
};

int main(void) {
  Solution sln;
  vector<string> board;
  board = {"O  ", "   ", "   "};
  std::cout << sln.validTicTacToe(board) << std::endl;
  board = {"XOX", " X ", "   "};
  std::cout << sln.validTicTacToe(board) << std::endl;
  board = {"XXX", "   ", "OOO"};
  std::cout << sln.validTicTacToe(board) << std::endl;
  board = {"XOX", "O O", "XOX"};
  std::cout << sln.validTicTacToe(board) << std::endl;
  board = {"XXX","XOO","OO "};
  std::cout << sln.validTicTacToe(board) << std::endl;
  board = {"OXX","XOX","OXO"};
  std::cout << sln.validTicTacToe(board) << std::endl;
  board = {"XOX","X O","X O"};
  std::cout << sln.validTicTacToe(board) << std::endl;

  return 0;
}
