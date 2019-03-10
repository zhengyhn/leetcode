#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> fizzBuzz(int n) {
      vector<string> ret;
      for (int i = 1; i <= n; ++i) {
        if (i % 3 == 0 && i % 5 == 0) {
          ret.push_back("FizzBuzz");
        } else if (i % 3 == 0) {
          ret.push_back("Fizz");
        } else if (i % 5 == 0) {
          ret.push_back("Buzz");
        } else {
          stringstream ss;
          ss << i;
          ret.push_back(ss.str());
        }
      }
      return ret;
    }
};

int main() {
  Solution sln;
  vector<string> ret = sln.fizzBuzz(15);
  for (string item: ret) {
    std::cout << item << std::endl;
  }

  return 0;
}
