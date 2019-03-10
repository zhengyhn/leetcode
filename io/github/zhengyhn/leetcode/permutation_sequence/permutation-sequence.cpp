#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
  public:
    string getPermutation(int n, int k) {
      vector<int> ret(n);
      for (int i = 0; i < n; ++i) {
        ret[i] = i + 1;
      }
      if (k == 1) {
        return toString(ret);
      }
      while (k > 1) {
        int i = ret.size() - 1;
        for (; i > 0; --i) {
          if (ret[i] > ret[i - 1]) {
            break;
          }
        }
        int j = ret.size() - 1;
        for (; j >= i; --j) {
          if (ret[j] > ret[i - 1]) {
            break;
          }
        }
        swap(ret[j], ret[i - 1]);
        reverse(ret, i, ret.size() - 1);
        --k;
      }
      return toString(ret);
    }

    void reverse(vector<int>& v, int begin, int end) {
      while (begin < end) {
        swap(v[begin++], v[end--]);
      }
    }

    string toString(vector<int>& v) {
      string str;
      for (int i = 0; i < v.size(); ++i) {
        stringstream ss;
        ss << v[i];
        str.append(ss.str());
      }
      return str;
    }
};

int main() {
  Solution sln;
  string ret;
  ret = sln.getPermutation(10, 20);
  cout << ret << endl;

  return 0;
}
