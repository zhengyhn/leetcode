#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int slidingPuzzle(vector<vector<int>>& board) {
      string begin = board2str(board);
      string end = "123450";
      list<string> open = {begin};
      map<string, int> close;
      close[begin] = 0;
      map<string, string> parent;
      while (!open.empty()) {
        int min = 0xffff;
        list<string>::iterator p;
        for (list<string>::iterator it = open.begin(); it != open.end(); ++it) {
          int val = close[*it] + getDistance(*it, end);
          if (val < min) {
            min = val;
            p = it;
          }
        }
        string cur = *p;
        if (cur == end) {
          return getCount(parent, cur);
        }
        open.erase(p);
        int i = cur.find('0');
        string newStr(cur);
        if (i % 3 > 0) {
          swap(newStr[i], newStr[i - 1]);
          updateTable(cur, newStr, close[*p] + 1, open, close, parent);
          swap(newStr[i], newStr[i - 1]);
        }
        if (i % 3 < 2) {
          swap(newStr[i], newStr[i + 1]);
          updateTable(cur, newStr, close[*p] + 1, open, close, parent);
          swap(newStr[i], newStr[i + 1]);
        }
        if (i < 3) {
          swap(newStr[i], newStr[i + 3]);
          updateTable(cur, newStr, close[*p] + 1, open, close, parent);
          swap(newStr[i], newStr[i + 3]);
        }
        if (i >= 3) {
          swap(newStr[i], newStr[i - 3]);
          updateTable(cur, newStr, close[*p] + 1, open, close, parent);
          swap(newStr[i], newStr[i - 3]);
        }
      }
      return -1;
    }

    int getCount(map<string, string>& parent, const string& str) {
      int count = 0;
      string key = str;
      while (parent.find(key) != parent.end()) {
        key = parent[key];
        ++count;
      }
      return count;
    }

    void updateTable(const string& cur, const string& str, int dist, list<string>& open, map<string, int>& close, map<string, string>& parent) {
      if (close.find(str) == close.end() || close[str] > dist) {
        close[str] = dist;
        open.push_back(str);
        parent[str] = cur;
      }
    }

    int getDistance(const string& left, const string& right) {
      int ret = 0;
      for (int i = 0; i < left.size(); ++i) {
        ret += abs(left[i] - right[i]);
      }
      return ret;
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
