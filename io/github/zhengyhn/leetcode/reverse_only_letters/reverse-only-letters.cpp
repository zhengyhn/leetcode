#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    string reverseOnlyLetters(string S) {
      if (S.size() <= 1) {
        return S;
      }
      int i = 0;
      int j = S.size() - 1;
      while (i < j) {
        while (!isLetter(S[i])) {
          ++i;
        }
        while (!isLetter(S[j])) {
          --j;
        }
        if (i < j) {
          char temp = S[i];
          S[i] = S[j];
          S[j] = temp;
          ++i;
          --j;
        }
      }
      return S;
    }

    bool isLetter(char c) {
      return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
};

int main() {
  Solution sln;
  cout << sln.reverseOnlyLetters("ab-cd") << endl;
  cout << sln.reverseOnlyLetters("a-bC-dEf-ghIj") << endl;
  cout << sln.reverseOnlyLetters("Test1ng-Leet=code-Q!") << endl;

  return 0;
}
