#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
      std::stack<char> upDownStack;
      std::stack<char> leftRightStack;
      std::stack<char> *pStack;
      char reverse;

      for (int i = 0; i < moves.size(); ++i) {
        switch (moves[i]) {
          case 'U':
            pStack = &upDownStack;
            reverse = 'D';
            break;
          case 'D':
            pStack = &upDownStack;
            reverse = 'U';
            break;
          case 'L':
            pStack = &leftRightStack;
            reverse = 'R';
            break;
          case 'R':
            pStack = &leftRightStack;
            reverse = 'L';
            break;
        }
        if (!pStack->empty() && pStack->top() == reverse) {
          pStack->pop();
        } else {
          pStack->push(moves[i]);
        }
      }
      return upDownStack.empty() && leftRightStack.empty();
    }
};

int main() {
  Solution sln;
  std::string seq = "UD";
  std::cout << sln.judgeCircle(seq) << std::endl;
  seq = "UDD";
  std::cout << sln.judgeCircle(seq) << std::endl;
  seq = "DD";
  std::cout << sln.judgeCircle(seq) << std::endl;
  seq = "RL";
  std::cout << sln.judgeCircle(seq) << std::endl;
  seq = "DURDLDRRLL";
  std::cout << sln.judgeCircle(seq) << std::endl;

  return 0;
}
