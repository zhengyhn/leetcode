#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    bool isIdealPermutationOld(vector<int>& A) {
      int global = 0;
      int local = 0;
      for (int i = 0; i < A.size(); ++i) {
        int j = i + 1;
        if (j < A.size() && A[i] > A[j]) {
          ++global;
          ++local;
        }
        for (++j; j < A.size(); ++j) {
          if (A[i] > A[j]) {
            ++global;
          }
        }
      }
      return global == local;
    }
    bool isIdealPermutation(vector<int>& A) {
      for (int i = 0; i < A.size(); ++i) {
        if (A[i] - i > 1 || A[i] - i < -1) {
          return false;
        }
      }
      return true;
    }
};

int main() {
  Solution sln;
  vector<int> arr;
  arr = {1, 0, 2};
  std::cout << sln.isIdealPermutation(arr) << std::endl;
  arr = {1, 2, 0};
  std::cout << sln.isIdealPermutation(arr) << std::endl;

  return 0;
}
