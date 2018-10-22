#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

class Solution {
  public:
    int nextGreaterElement(int n) {
      if (n / 10 == 0) {
        return -1;
      }
      vector<int> arr = int2arr(n);
      int i = arr.size() - 1;
      for (; i > 0; --i) {
        if (arr[i] > arr[i - 1]) {
          break;
        }
      }
      if (i > 0) {
        int j = arr.size() - 1;
        for (; j >= i; --j) {
          if (arr[j] > arr[i - 1]) {
            swap(arr[j], arr[i - 1]);
            break;
          }
        }
      }
      reverse(arr.begin() + i, arr.end());
      long long ret = arr2int(arr);

      return ret > n && ret <= INT_MAX ? ret : -1;
    }

    vector<int> int2arr(int n) {
      vector<int> ret;
      int base = 10;

      while (n > 0) {
        ret.push_back(n % base);
        n /= base;
      }
      reverse(ret.begin(), ret.end());

      return ret;
    }

    long long arr2int(vector<int>& arr) {
      long long n = 0;
      int base = 1;
      for (int i = arr.size() - 1; i >= 0; --i) {
        n += arr[i] * base;
        base *= 10;
      }
      return n;
    }
};

int main() {
  Solution sln;
  for (int i = 1; i < 100; ++i) {
    cout << sln.nextGreaterElement(i) << endl;
  }
  cout << sln.nextGreaterElement(INT_MAX - 1) << endl;
  cout << sln.nextGreaterElement(INT_MAX) << endl;

  return 0;
}
