#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int totalNQueens(int n) {
      int ret = 0;
      if (n <= 0) {
        return ret;
      }
      int stack[n];
      int top = -1;
      stack[++top] = -1;

      while (top >= 0) {
        ++stack[top];
        if (stack[top] >= n) {
          --top;
          continue;
        }
        bool isValid = this->isValidBoard(stack, top + 1, n);
        if (isValid) {
          if (top == n - 1) {
            ++ret;
          } else {
            stack[++top] = -1;
          }
        }
      }
      return ret;
    }
  private:
    bool isValidBoard(int *stack, int stackLen, int boardLen) {
      if (stackLen == 1) {
        return true;
      }
      int it = stack[stackLen - 1];
      if (it >= boardLen) {
        return false;
      }
      for (int i = 0; i < stackLen - 1; ++i) {
        if (it == stack[i]) {
          return false;
        }
        int left = it - stackLen + 1 + i;
        if (left >= 0 && left == stack[i]) {
          return false;
        }
        int right = stackLen - i - 1 + it;
        if (right < boardLen && right == stack[i]) {
          return false;
        }
      }
      return true;
    }

    vector<string> toString(int *stack, int stackLen, int n) {
      vector<string> ret(n);

      for (int i = 0; i < n; ++i) {
        string item(n, '.');
        if (i < stackLen) {
          item[stack[i]] = 'Q';
        }
        ret[i] = item;
      }
      return ret;
    }

    void print(int *stack, int stackLen, int n) {
      vector<string> ret = this->toString(stack, stackLen, n);
      for (auto row: ret) {
        for (auto item: row) {
          std::cout << item;
        }
        std::cout << std::endl;
      }
      std::cout << "--------" << std::endl;
    }
};

int main() {
  Solution sln;
  for (int i = 0; i < 15; ++i) {
    int ret = sln.totalNQueens(i);
    std::cout << ret << std::endl;
  }

  return 0;
}
