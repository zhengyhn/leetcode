#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int countPrimes(int n) {
      if (n <= 2) {
        return 0;
      }
      int count = 0;
      vector<int> set(n + 2, 1);
      for (int i = 2; i < n; ++i) {
        if (set[i] == 0) {
          continue;
        }
        for (int j = 2; i * j < n; ++j) {
          // std::cout << i << " " << j << std::endl;
          set[i * j] = 0;
        }
        ++count;
      }
      return count;
    }
};

int main() {
  Solution sln;
  for (int i = 999983; i <= 999983; ++i) {
    std::cout << sln.countPrimes(i) << std::endl;
  }

  return 0;
}
