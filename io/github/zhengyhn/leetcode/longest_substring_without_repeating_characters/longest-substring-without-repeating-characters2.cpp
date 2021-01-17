#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> indexes;
    int ret = 0;
    int left = 0;
    int right = 0;
    while (right < s.size()) {
      if (indexes.find(s[right]) == indexes.end()) {
        indexes[s[right]] = right;
        ret = max(ret, right - left + 1);
      } else {
        while (left <= indexes[s[right]]) {
          indexes.erase(s[left]);
          ++left;
        }
        indexes[s[right]] = right;
      }
      ++right;
    }
    return ret;
  }
};

int main(int argc, char **argv) {
  Solution sln;
  std::string str = "abcabcbb";
  std::cout << sln.lengthOfLongestSubstring(str) << std::endl;
}
