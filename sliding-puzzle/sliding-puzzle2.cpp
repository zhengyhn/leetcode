#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int slidingPuzzle(vector<vector<int>>& board) {
      string begin = board2str(board);
      string end = "123450";
      map<string, int> visited = {{begin, 1}};
      queue<string> q;
      q.push(begin);
      int count = 0;
      map<int, vector<int>> moves = {
              {0, {1, 3}},
              {1, {0, 2, 4}},
              {2, {1, 5}},
              {3, {0, 4}},
              {4, {3, 5, 1}},
              {5, {4, 2}}
      };
      while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
          string cur = q.front();
          q.pop();
          if (cur == end) {
            return count;
          }
          int j = cur.find('0');
          for (int k = 0; k < moves[j].size(); ++k) {
            addElement(cur, j, moves[j][k], q, visited);
          }
        }
        ++count;
      }
      return -1;
    }

    void addElement(const string& cur, int idx, int newIdx, queue<string>& q, map<string, int>& visited) {
      string newStr(cur);
      swap(newStr[idx], newStr[newIdx]);
      if (!visited[newStr]) {
        q.push(newStr);
        visited[newStr] = 1;
      }
    }

    string board2str(const vector<vector<int>>& board) {
      string ret;
      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
          ret.push_back(board[i][j] + '0');
        }
      }
      return ret;
    }
};

int main() {
  Solution sln;
  vector<vector<int>> board;
  board = {
    {1, 2, 3},
    {4, 0, 5}
  };
  cout << sln.slidingPuzzle(board) << endl;

  board = {
    {1, 2, 3},
    {5, 4, 0}
  };
  cout << sln.slidingPuzzle(board) << endl;

  board = {
    {4, 1, 2},
    {5, 0, 3}
  };
  cout << sln.slidingPuzzle(board) << endl;

  board = {
    {3, 2, 4},
    {1, 5, 0}
  };
  cout << sln.slidingPuzzle(board) << endl;


  return 0;
}
