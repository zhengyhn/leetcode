#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr2(string S) {
        int dp[S.size() + 1];
        dp[S.size()] = 0;
        for (int i = S.size() - 1; i >= 0; --i) {
            if (S[i] == '0') {
                dp[i] = dp[i + 1];
            } else {
                int countOne = 0;
                for (int j = i; j < S.size(); ++j) {
                    if (S[j] == '0') {
                        ++countOne;
                    }
                }
                int countZero = dp[i + 1] + 1;
                dp[i] = countOne < countZero ? countOne : countZero;
            }
        }
        return dp[0];
    }
    int minFlipsMonoIncr(string S) {
        return dfs(S, 0);
    }

    int dfs(string S, int i) {
        if (i >= S.size()) {
            return 0;
        }
        if (S[i] == '1') {
            int countOne = 0;
            for (int j = i; j < S.size(); ++j) {
                if (S[j] == '0') {
                    ++countOne;
                }
            }
            int countZero = 0;
            countZero = 1 + dfs(S, i + 1);
            return countOne < countZero ? countOne : countZero;
        } else {
            return dfs(S, i + 1);
        }
    }
};

int main() {
    Solution sln;
    cout << sln.minFlipsMonoIncr("00110") << endl;
    cout << sln.minFlipsMonoIncr("010110") << endl;
    cout << sln.minFlipsMonoIncr("00011000") << endl;

    cout << sln.minFlipsMonoIncr2("00110") << endl;
    cout << sln.minFlipsMonoIncr2("010110") << endl;
    cout << sln.minFlipsMonoIncr2("00011000") << endl;
    return 0;
}