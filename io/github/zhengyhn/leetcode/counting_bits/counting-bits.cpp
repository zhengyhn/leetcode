#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
      vector<int> ret = {0};
      for (int i = 1; i <= num; ++i) {
        int base = floor(log2(i));
        ret.push_back(ret[i % (int)pow(2, base)] + 1);
      }
      return ret;
    }
};

int main() {
  Solution sln;
  vector<int> ret = sln.countBits(15);
  for (int item: ret) {
    std::cout << item << std::endl;
  }

  return 0;
}
