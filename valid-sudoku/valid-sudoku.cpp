#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    bool isValidSudoku(vector<vector<char>>& board) {
      unordered_set<char> emptySet;
      vector<unordered_set<char>> rowSets(9, emptySet);
      vector<unordered_set<char>> colSets(9, emptySet);
      vector<unordered_set<char>> subSets(9, emptySet);
      for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
          if (board[i][j] == '.') {
            continue;
          }
          if (rowSets[i].find(board[i][j]) != rowSets[i].end()) {
            return false;
          } else {
            rowSets[i].insert(board[i][j]);
          }
          if (colSets[j].find(board[i][j]) != colSets[j].end()) {
            return false;
          } else {
            colSets[j].insert(board[i][j]);
          }
          int subIdx = (i / 3) * 3 + j / 3;
          if (subSets[subIdx].find(board[i][j]) != subSets[subIdx].end()) {
            return false;
          } else {
            subSets[subIdx].insert(board[i][j]);
          }
        }
      }
      return true;
    }
};

int main() {
  Solution sln;
  vector<vector<char>> board;
  board = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
  };
  std::cout << sln.isValidSudoku(board) << std::endl;

  board = {
    {'8','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
  };
  std::cout << sln.isValidSudoku(board) << std::endl;

  return 0;
}
