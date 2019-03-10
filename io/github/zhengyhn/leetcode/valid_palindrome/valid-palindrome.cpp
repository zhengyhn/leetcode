#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    bool isPalindrome(string s) {
      int head = 0; 
      int tail = s.size() - 1; 
      while (head <= tail) {
        if (!isAlphaNumeric(s[head])) {
          ++head;
          continue;
        }
        if (!isAlphaNumeric(s[tail])) {
          --tail;
          continue;
        }
        if (toLower(s[head]) != toLower(s[tail])) {
          return false;
        }
        ++head;
        --tail;
      }
      return true;
    }

    bool isAlphaNumeric(char c) {
      return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }

    char toLower(char c) {
      if (c >= 'A' && c <= 'Z') {
        return c - ('A' - 'a');
      }
      return c;
    }
};

int main() {
  Solution sln;

  std::string s;
  s = "A man, a plan, a canal: Panama";
  std::cout << sln.isPalindrome(s) << std::endl;

  s = "race a car";
  std::cout << sln.isPalindrome(s) << std::endl;

  s = "";
  std::cout << sln.isPalindrome(s) << std::endl;

  s = "a";
  std::cout << sln.isPalindrome(s) << std::endl;

  s = " , ";
  std::cout << sln.isPalindrome(s) << std::endl;

  s = " ,b ";
  std::cout << sln.isPalindrome(s) << std::endl;

  s = "0P";
  std::cout << sln.isPalindrome(s) << std::endl;

  return 0;
}
