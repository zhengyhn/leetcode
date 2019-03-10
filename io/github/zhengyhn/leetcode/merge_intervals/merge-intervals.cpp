#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
  public:
    vector<Interval> merge(vector<Interval>& intervals) {
      vector<Interval> ret;
      bool merged = false;
      for (int i = 0; i < intervals.size(); ++i) {
        int j = 0;
        merged = false;
        int bottom = intervals[i].start;
        int up = intervals[i].end;
        for (; j < ret.size(); ++j) {
          int tempBottom = min(bottom, ret[j].start);
          int tempUp = max(up, ret[j].end);
          // cout << "temp: " << tempBottom <<  " " << tempUp << endl;
          if ((tempUp - tempBottom) <= (up - bottom + ret[j].end - ret[j].start)) {
            ret[j] = ret[ret.size() - 1];
            ret.pop_back();
            merged = true;
            --j;
            bottom = tempBottom;
            up = tempUp;
          }
        }
        // cout << "merged: " << merged <<  " " << bottom << " " << up << endl;
        if (merged) {
          Interval interval(bottom, up);
          ret.push_back(interval);
        } else {
          ret.push_back(intervals[i]);
        }
        // printIntervals(ret);
      }
      return ret;
    }

    void printIntervals(vector<Interval>& intervals) {
      for (Interval item: intervals) {
        cout << item.start << "," << item.end << " ";
      }
      cout << endl;
    }
};

vector<Interval> getIntervals(vector<vector<int>>& arr) {
  vector<Interval> intervals;
  for (vector<int> row: arr) {
    Interval interval(row[0], row[1]);
    intervals.push_back(interval);
  }
  return intervals;
}

void printIntervals(vector<Interval>& intervals) {
  for (Interval item: intervals) {
    cout << item.start << "," << item.end << " ";
  }
  cout << endl;
}

int main() {
  Solution sln;
  vector<vector<int>> arr;
  vector<Interval> intervals;
  vector<Interval> ret;
  // arr = {{1,3},{2,6},{8,10},{15,18}};
  // intervals = getIntervals(arr);
  // ret = sln.merge(intervals);
  // printIntervals(ret);

  // arr = {{1,4}, {4, 5}};
  // intervals = getIntervals(arr);
  // ret = sln.merge(intervals);
  // printIntervals(ret);

  // arr = {{2,3},{4,5},{6,7},{8,9},{1,10}};
  // intervals = getIntervals(arr);
  // ret = sln.merge(intervals);
  // printIntervals(ret);

  // arr = {{2,3},{5,5},{2,2},{3,4},{3,4}};
  // intervals = getIntervals(arr);
  // ret = sln.merge(intervals);
  // printIntervals(ret);

  arr = {{2,3},{4,6},{5,7},{3,4}};
  intervals = getIntervals(arr);
  ret = sln.merge(intervals);
  printIntervals(ret);

  return 0;
}
