#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    vector<vector<int>> ret;
    if (intervals.size() <= 0) {
      ret.push_back(newInterval);
      return ret;
    }
    int i = 0;
    for (; i < intervals.size(); ++i) {
      if (newInterval[0] > intervals[i][1]) {
        ret.push_back(intervals[i]);
        continue;
      }
      if (newInterval[1] < intervals[i][0]) {
        break;
      }
      if (newInterval[0] > intervals[i][0]) {
        newInterval[0] = intervals[i][0];
      }
      if (newInterval[1] < intervals[i][1]) {
        newInterval[1] = intervals[i][1];
      }
    }
    ret.push_back(newInterval);
    while (i < intervals.size()) {
      ret.push_back(intervals[i++]);
    }
    return ret;
  }
};

int main() {
  Solution sln;
  vector<vector<int>> intervals;
  vector<int> newInterval;
  vector<vector<int>> ret;

  intervals = {{1, 5}, {6, 8}};
  newInterval = {0, 9};
  ret = sln.insert(intervals, newInterval);
  for (vector<int> list : ret) {
    for (int item : list) {
      cout << item << " ";
    }
    cout << endl;
  }

  intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
  newInterval = {4, 8};
  ret = sln.insert(intervals, newInterval);
  for (vector<int> list : ret) {
    for (int item : list) {
      cout << item << " ";
    }
    cout << endl;
  }
}