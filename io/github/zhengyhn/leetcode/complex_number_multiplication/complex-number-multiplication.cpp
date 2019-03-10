#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

struct Complex {
  int real;
  int virt;
  Complex(int real, int virt)
    :real(real), virt(virt)
  {}

  Complex(string str)
    :real(0), virt(0)
  {
    char stack[str.size()];
    int top = -1;
    for (int i = 0; i < str.size(); ++i) {
      if (str[i] == '+') {
        this->real = this->atoi(stack, top);
      } else if (str[i] == 'i') {
        this->virt = this->atoi(stack, top);
      } else {
        stack[++top] = str[i];
      }
    }
  }

  Complex& multi(const Complex& com) {
    int real = this->real * com.real + this->virt * com.virt * -1;
    int virt = this->real * com.virt + this->virt * com.real;

    this->real = real;
    this->virt = virt;

    return *this;
  }

  string toString() {
    stringstream ss;
    ss << this->real << '+' << this->virt << 'i';

    return ss.str();
  }

  int atoi(char *stack, int& top) {
    int ret = 0;
    int count = 0;
    while (top >= 0) {
      if (stack[top] == '-') {
        ret = -ret;
      } else {
        ret += (stack[top] - '0') * pow(10, count);
        ++count;
      }
      --top;
    }
    return ret;
  }
};

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
      Complex left(a);
      Complex right(b);

      left.multi(right);

      return left.toString();
    }
};

int main() {
  Solution sln;
  std::cout << sln.complexNumberMultiply("1+-1i", "1+-1i") << std::endl;

  return 0;
}
