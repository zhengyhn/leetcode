#include <iostream>

using namespace std;

class Solution {
  public:
    bool isPowerOfTwo(int n) {
      if (n <= 0) {
        return false;
      }
      int count = 0;
      while (n > 0) {
        count += n & 0x1;
        n >>= 1;
        if (n != 0 && count > 0) {
          return false;
        }
      }
      return true;
    }
    bool isPowerOfTwo2(int n) {
      if (n <= 0) {
        return false;
      }
      return (n & (n - 1)) == 0;
    }
};

int main() {
  Solution sln;
  for (int i = -1; i < 100; ++i) {
    cout << i << ":" << sln.isPowerOfTwo2(i) << endl;
  }

  return 0;
}
