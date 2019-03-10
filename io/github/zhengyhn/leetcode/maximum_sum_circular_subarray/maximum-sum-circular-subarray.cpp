#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxSubarraySumCircular(vector<int>& A) {
      long long max = -0xffffff;
      int size = A.size();
      bool isAllPositive = true;
      for (int start = 0; start < size; ++start) {
        int i = start;
        long long sum = 0;
        while (start < size && i - size < (start % size)) {
          if (A[i % size] < 0) {
            isAllPositive = false;
          }
          sum += A[i % size];
          // cout << sum << " " << max << endl;
          if (sum > max) {
            max = sum;
          }
          ++i;
          if (sum < 0) {
            start = i;
            sum = 0;
          }
        }
        if (isAllPositive) {
          break;
        }
      }
      return max;
    }
};

int main() {
  Solution sln;
  vector<int> arr;
  arr = {1,-2,3,-2};
  cout << sln.maxSubarraySumCircular(arr) << endl;
  arr = {5,-3,5};
  cout << sln.maxSubarraySumCircular(arr) << endl;
  arr = {3,-1,2,-1};
  cout << sln.maxSubarraySumCircular(arr) << endl;
  arr = {3,-2,2,-3};
  cout << sln.maxSubarraySumCircular(arr) << endl;
  arr = {-2,-3,-1};
  cout << sln.maxSubarraySumCircular(arr) << endl;

  return 0;
}
