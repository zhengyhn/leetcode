#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  void qsort(vector<vector<int>>& intervals, int begin, int end) {
    if (begin >= end) {
      return;
    }
    int low = begin;
    int high = end;
    vector<int> pivot = intervals[low];
    while (low < high) {
      while (low < high && intervals[high][0] >= pivot[0]) {
        --high;
      }
      intervals[low] = intervals[high];
      while (low < high && intervals[low][0] <= pivot[0]) {
        ++low;
      }
      intervals[high] = intervals[low];
    }
    intervals[low] = pivot;
    qsort(intervals, begin, low - 1);
    qsort(intervals, low + 1, end);
  }

 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() <= 1) {
      return intervals;
    }
    qsort(intervals, 0, intervals.size() - 1);
    vector<vector<int>> ret = {intervals[0]};
    for (int i = 1; i < intervals.size(); ++i) {
      vector<int> temp = ret[ret.size() - 1];
      if (temp[1] >= intervals[i][0]) {
        temp[1] = max(temp[1], intervals[i][1]);
        ret[ret.size() - 1] = temp;
      } else {
        ret.push_back(intervals[i]);
      }
    }
    return ret;
  }
};

int main() {
  Solution sln;
  vector<vector<int>> arr;
  arr = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  vector<vector<int>> ret = sln.merge(arr);
  for (auto item : ret) {
    cout << item[0] << "," << item[1] << endl;
  }

  return 0;
}
