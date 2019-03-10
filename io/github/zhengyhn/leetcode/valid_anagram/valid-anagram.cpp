#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool isAnagram1(string s, string t) {
      if (s.size() != t.size()) {
        return false;
      }
      int first[26] = {0};
      int second[26] = {0};
      for (int i = 0; i < s.size(); ++i) {
        first[s[i] - 'a'] += 1;
      }
      for (int i = 0; i < t.size(); ++i) {
        second[t[i] - 'a'] += 1;
      }
      for (int i = 0; i < 26; ++i) {
        if (first[i] != second[i]) {
          return false;
        }
      }
      return true;
    }

    bool isAnagram(string s, string t) {
      if (s.size() != t.size()) {
        return false;
      }
      std::map<char, int> first, second;
      for (int i = 0; i < s.size(); ++i) {
        first[s[i]] += 1;
      }
      for (int i = 0; i < t.size(); ++i) {
        second[t[i]] += 1;
      }
      for (std::map<char, int>::iterator it = first.begin();
           it != first.end(); ++it) {
        if (it->second != second[it->first]) {
          return false;
        }
      }

      return true;
    }
};

int main() {
  Solution sln;

  if (sln.isAnagram1("anagram", "naagram")) {
    std::cout << "t" << std::endl;
  } else {
    std::cout << "f" << std::endl;
  }

  if (sln.isAnagram1("rat", "car")) {
    std::cout << "t" << std::endl;
  } else {
    std::cout << "f" << std::endl;
  }
}
