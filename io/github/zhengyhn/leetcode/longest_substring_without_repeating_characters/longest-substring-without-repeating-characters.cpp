#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int maxLength = 0;
      for (int i = 0; i < s.size(); ++i) {
        std::set<char> theSet;
        theSet.insert(s[i]);
        int length = 1;
        for (int j = i + 1; j < s.size(); ++j) {
          if (theSet.find(s[j]) == theSet.end()) {
            theSet.insert(s[j]);
            length++;
          } else {
            for (int k = i; k <= j; ++k) {
              if (s[k] != s[j]) {
                ++i;
              } else {
                break;
              }
            }
            break;
          }
        }
        maxLength = length > maxLength ? length : maxLength;
      }
      return maxLength;
    }

    int lengthOfLongestSubstring2(string s) {
      int maxLength = 0;
      int i = 0, j = 0;
      std::set<char> theSet;
      while (i < s.size() && j < s.size()) {
        if (theSet.find(s[j]) == theSet.end()) {
          theSet.insert(s[j]);
          ++j;
          maxLength = (j - i) > maxLength ? (j - i) : maxLength;
        } else {
          theSet.erase(s[i]);
          ++i;
        }
      }
      return maxLength;
    }

    int lengthOfLongestSubstring3(string s) {
      int maxLength = 0;
      int i = 0, j = 0;
      int arr[128] = {};
      while (i < s.size() && j < s.size()) {
        if (arr[s[j] - 'a'] <= 0) {
          arr[s[j] - 'a'] = 1;
          ++j;
          maxLength = (j - i) > maxLength ? (j - i) : maxLength;
        } else {
          arr[s[i] - 'a'] = 0;
          ++i;
        }
      }
      return maxLength;
    }
};

int main(int argc, char **argv) {
  Solution sln;
  std::string str(argv[1]);
  std::cout << sln.lengthOfLongestSubstring(str) << std::endl;
  std::cout << sln.lengthOfLongestSubstring2(str) << std::endl;
  std::cout << sln.lengthOfLongestSubstring3(str) << std::endl;
}
