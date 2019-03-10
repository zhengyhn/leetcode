#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int climbStairs(int n) {
      int last = 1;
      int lastButNotLeast = 1;
      for (int i = 2; i <= n; ++i) {
        int temp = last;
        last = last + lastButNotLeast;
        lastButNotLeast = temp;
      }
      return last;
    }
};

int main() {
  Solution sln;
  std::cout << sln.climbStairs(1) << std::endl;
  std::cout << sln.climbStairs(2) << std::endl;
  std::cout << sln.climbStairs(3) << std::endl;
  std::cout << sln.climbStairs(4) << std::endl;
  std::cout << sln.climbStairs(5) << std::endl;

  return 0;
}
