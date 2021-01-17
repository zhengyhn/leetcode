#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    vector<int> grayCode(int n) {
      vector<int> queue = {0};
      unordered_set<int> set = {0};
      for (int i = 0; i < queue.size(); ++i) {
        int elem = queue[i];
        int p = 0;
        for (int j = 0; j < n; ++j) {
          p = j == 0 ? 1 : 2 * p;
          int val = elem;
          if ((p & elem) == 0) {
            val += p;
          } else {
            val -= p;
          }
          if (set.find(val) == set.end()) {
            set.insert(val);
            queue.push_back(val);
            break;
          }
        }
      }
      return queue;
    }

    /**
     * 可以用数学归纳法证明
     */
    vector<int> grayCode2(int n) {
      vector<int> ret(1 << n);
      for (int i = 0; i < ret.size(); ++i) {
        ret[i] = i ^ (i >> 1);
      }
      return ret;
    }
};

int main() {
  Solution sln;
  for (int i = 0; i < 5; ++i) {
    vector<int> ret = sln.grayCode2(i);
    for (int item: ret) {
      cout << item << " ";
    }
    cout << endl;
  }
  return 0;
}
