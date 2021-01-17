#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    if (intervals.size() <= 0) {
      intervals.push_back(newInterval);
      return intervals;
    }
    vector<vector<int>> ret;
    int i = 0;
    bool inserted = false;
    for (; i < intervals.size(); ++i) {
      if (newInterval[0] > intervals[i][1]) {
        ret.push_back(intervals[i]);
        continue;
      }
      if (newInterval[1] < intervals[i][0]) {
        ret.push_back(newInterval);
        inserted = true;
        break;
      }
      vector<int> temp;
      if (newInterval[0] < intervals[i][0]) {
        temp.push_back(newInterval[0]);
      } else {
        temp.push_back(intervals[i][0]);
      }
      int j = i;
      for (; j < intervals.size(); ++j) {
        if (newInterval[1] < intervals[j][0]) {
          temp.push_back(newInterval[1]);
          i = j;
          break;
        } else if (newInterval[1] <= intervals[j][1]) {
          temp.push_back(intervals[j][1]);
          i = j + 1;
          break;
        }
      }
      if (temp.size() <= 1) {
        temp.push_back(newInterval[1]);
        i = j;
      }
      ret.push_back(temp);
      inserted = true;
      break;
    }
    if (!inserted) {
      ret.push_back(newInterval);
    } else {
      while (i < intervals.size()) {
        ret.push_back(intervals[i++]);
      }
    }

    return ret;
  }
};

int main() {
  Solution sln;
  vector<vector<int>> intervals;
  vector<int> newInterval;

  intervals = {{1, 5}, {6, 8}};
  newInterval = {0, 9};

  vector<vector<int>> ret = sln.insert(intervals, newInterval);
  for (vector<int> list : ret) {
    for (int item : list) {
      cout << item << " ";
    }
    cout << endl;
  }
}