#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    if (s2.size() < s1.size()) {
      return false;
    }
    unordered_map<char, int> counts;
    for (int i = 0; i < s1.size(); ++i) {
      if (counts.find(s1[i]) == counts.end()) {
        counts[s1[i]] = 0;
      }
      counts[s1[i]] += 1;
    }
    int left = 0;
    for (; left < s2.size(); ++left) {
      if (counts.find(s2[left]) == counts.end()) {
        continue;
      }
      int right = left;
      while (right < s2.size() && (right - left + 1) <= s1.size()) {
        counts[s2[right]] -= 1;
        if (counts.find(s2[right]) == counts.end()) {
          while (left < right) {
            counts[s2[left]] += 1;
            ++left;
          }
          left = right;
          break;
        } else if (counts[s2[right]] < 0) {
          while (left < right && s2[left] != s2[right]) {
            counts[s2[left]] += 1;
            ++left;
          }
          counts[s2[left]] += 1;
          ++left;
        }
        ++right;
      }
      if ((right - left + 1) > s1.size()) {
        // cout << j << " " << i << " " << endl;
        return true;
      }
    }
    return false;
  }
};

int main(int argc, char **argv) {
  Solution sln;
  std::cout << sln.checkInclusion("hello", "ooolleoooleh") << std::endl;
  std::cout << sln.checkInclusion("acd", "dcda") << std::endl;
  std::cout << sln.checkInclusion("ab", "eidbaooo") << std::endl;
  std::cout << sln.checkInclusion("ab", "eidboaoo") << std::endl;

  return 0;
}