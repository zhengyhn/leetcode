#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int i = 0;
        int j = 2;
        long long first = A[0];
        while (i < A.size()) {
            // first = getBinary(A, 0, i);
            // cout << first << endl;
//            if (count(A, i) > A.size() / 3) {
//                cout << first << endl;
//                return {-1, -1};
//            }
            long long second = getBinary(A, i + 1, j - 1);
            cout << i << " " << j << " " << A.size() << endl;
            if (i == 33) {
                cout << first << " " << second << endl;
            }
            if (second > first) {
                ++i;
                first = (first << 1) + A[i];
                j = i + 2;
            } else if (second < first) {
                ++j;
            } else {
                long long third = getBinary(A, j, A.size() - 1);
                // cout << i << " " << j << " " << first << " " << second << " " << third << endl;
                if (third == second) {
                    return {i, j};
                } else {
                    ++i;
                    first = (first << 1) + A[i];
                    j = i + 2;
                }
            }
            if (j >= A.size()) {
                ++i;
                first = (first << 1) + A[i];
                j = i + 2;
            }
        }
        return {-1, -1};
    }

    int count(vector<int>& A, int i) {
        int ret = 0;
        for (int k = i; k >= 0; --k) {
            if (A[k] == 1) {
                ++ret;
            }
        }
        return ret;
    }

    long long getBinary(vector<int>& A, int i, int j) {
        int base = 1;
        long long ret = 0;
        for (int k = j; k >= i; --k) {
            ret += base * A[k];
            base *= 2;
        }
        return ret;
    }
};

int main() {
    Solution sln;
    vector<int> arr;
    vector<int> ret;
    arr = {1,0,1,0,1};
    ret = sln.threeEqualParts(arr);
    for (int i: ret) {
        cout << i << " ";
    }
    cout << endl;
    arr = {1,1,0,1,1};
    ret = sln.threeEqualParts(arr);
    for (int i: ret) {
        cout << i << " ";
    }
    cout << endl;

    arr = {1,0,1,1,0};
    ret = sln.threeEqualParts(arr);
    for (int i: ret) {
        cout << i << " ";
    }
    cout << endl;

    arr = {0,1,0,0,1,1,0,1,0,1,1,1,1,0,1,0,1,1,0,0,1,0,0,1,1,0,1,1,0,1,1,0,1,0,1,0,0,1,1,0,1,0,1,1,1,1,0,1,0,1,1,0,0,1,0,0,1,1,0,1,1,0,1,1,0,1,0,1,0,0,1,1,0,1,0,1,1,1,1,0,1,0,1,1,0,0,1,0,0,1,1,0,1,1,0,1,1,0,1,0};
    ret = sln.threeEqualParts(arr);
    for (int i: ret) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}