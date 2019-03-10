#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
      int result = 0;
      int count = 0;

      while (num > 0) {
        result += ((num & 1) ^ 1) * pow(2, count++);
        num >>= 1; 
      }
      return result;  
    }
};

int main() {
  Solution sln;
  std::cout << sln.findComplement(5) << std::endl;
  std::cout << sln.findComplement(1) << std::endl;

  return 0;
}
