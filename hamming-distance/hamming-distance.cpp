#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
      int result = x ^ y;
      int count = 0;
      while (result) {
        count += result & 1;
        result >>= 1; 
      }
      return count;
    }
};

int main() {
  Solution sln;
  std::cout << sln.hammingDistance(1, 12) << std::endl;

  return 0;
}
