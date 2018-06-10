#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    string countAndSay(int n) {
      string ret = "1";
      for (int i = 2; i <= n; ++i) {
        string last = ret;
        int count = 0;
        string now;
        for (int j = 0; j < last.size(); ++j) {
          if (last[j] == last[j + 1]) {
            ++count;
          } else {
            now.push_back(count + 1 + '0');
            now.push_back(last[j]);
            count = 0;
          }
        }
        ret = now;
      }
      return ret;
    }
};

int main(void) {
  Solution sln;
  for (int i = 1; i < 100; ++i) {
    std::cout << sln.countAndSay(i) << std::endl;
  }

  return 0;
}
