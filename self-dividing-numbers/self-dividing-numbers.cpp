#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
      vector<int> result;
      for (int i = left; i <= right; ++i) {
        if (this->isSelfDividingNumbers(i)) {
          result.push_back(i);
        }
      }
      return result;
    }
    
    bool isSelfDividingNumbers(int digit) {
      int n = digit;
      while (n != 0) {
        int lower = n % 10;
        if (lower == 0) {
          return false;
        }
        if (digit % lower != 0) {
          return false;
        }
        n /= 10;
      }
      return true;
    }
};

int main() {
  Solution sln;

  vector<int> result = sln.selfDividingNumbers(1, 22);
  for (int i = 0; i < result.size(); ++i) {
    std::cout << result[i] << std::endl;
  }

  return 0;
}
