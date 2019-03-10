#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    vector<int> getRow(int rowIndex) {
      vector<int> ret = {1};
      if (rowIndex == 0) {
        return ret;
      }
      ret.push_back(1);
      for (int i = 1; i < rowIndex; ++i) {
        int prev = ret[0];
        for (int j = 1; j <= i; ++j) {
          int next = ret[j];
          ret[j] = prev + ret[j];
          prev = next;
        }
        ret.push_back(1);
      }
      return ret;
    }

    vector<int> getRow2(int rowIndex) {
      vector<int> ret(rowIndex + 1, 1);
      for (int i = 1; i <= rowIndex / 2; ++i) {
        ret[i] = ret[rowIndex - i] = (long long)ret[i - 1] * (rowIndex - i + 1) / i;
      }
      return ret;
    }
}; 

int main() {
  Solution sln;
  for (int i = 0; i <= 33; ++i) {
    vector<int> ret = sln.getRow2(i);
    for (int item: ret) {
      std::cout << item << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
