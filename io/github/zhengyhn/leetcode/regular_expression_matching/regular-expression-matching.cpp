#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.size() == 0 && p.size() == 0) {
            return true;
        }
        if (s.size() == 0) {
            if (p.size() % 2 == 1) {
                return false;
            }
            for (int i = 1; i < p.size(); i += 2) {
                if (p[i] != '*') {
                    return false;
                }
            }
            return true;
        }
        if (p.size() == 0) {
            return false;
        }
        char sc = s[s.size() - 1];
        char pc = p[p.size() - 1];
        if (sc == pc || pc == '.') {
            return isMatch(s.substr(0, s.size() - 1), p.substr(0, p.size() - 1));
        }
        if (pc != '*' && pc != sc) {
            return false;
        }
        int result = isMatch(s, p.substr(0, p.size() - 2));
        if (result) {
            return true;
        }
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == p[p.size() - 2] || p[p.size() - 2] == '.') {
                result = isMatch(s.substr(0, i), p.substr(0, p.size() - 2));
                if (result) {
                    return true;
                }
            } else {
                return false;
            }
        }
        return false;
    }
};

int main() {
  Solution sln;
  std::cout << sln.isMatch("a", ".*..a*") << std::endl;

  return 0;
}
