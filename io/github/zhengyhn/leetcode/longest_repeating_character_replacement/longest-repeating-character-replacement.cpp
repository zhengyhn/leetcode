#include <iostream>

using namespace std;

class Solution {
 public:
  int characterReplacement(string s, int k) {
    int ret = 0;
    if (s.size() <= 0) {
      return ret;
    }
    int count[26] = {0};
    int maxCount = 0;
    int left = 0;
    int right = 0;
    while (right < s.size()) {
      int i = s[right] - 'A';
      count[i]++;
      maxCount = max(maxCount, count[i]);
      if ((right - left + 1) > (maxCount + k)) {
        count[s[left] - 'A'] -= 1;
        ++left;
      }
      ret = max(ret, right - left + 1);
      ++right;
    }
    return ret;
  }
};

int main() {
  Solution sln;
  cout << sln.characterReplacement("IMNJJ", 2) << endl;

  return 0;
}