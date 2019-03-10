#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> generateParenthesis(int n) {
      vector<string> ret;
      if (n <= 0) {
        return ret;
      }
      ret = subResult(n - 1, n, '(');

      return ret;
    }

    vector<string> subResult(int leftCount, int rightCount, char root) {
      vector<string> ret;
      if ((leftCount == 0 && rightCount == 0)) {
        string temp(1, root);
        ret.push_back(temp);
        return ret;
      }
      vector<string> lefts;
      vector<string> rights;
      if (leftCount > 0) {
        lefts = subResult(leftCount - 1, rightCount, '(');
      }
      if (rightCount > 0 && leftCount < rightCount) {
        rights = subResult(leftCount, rightCount - 1, ')');
      }
      ret.insert(ret.end(), lefts.begin(), lefts.end());
      ret.insert(ret.end(), rights.begin(), rights.end());
      for (int i = 0; i < ret.size(); ++i) {
        ret[i].insert(ret[i].begin(), root);
      }
      return ret;
    }

    vector<string> generateParenthesisDp(int n) {
      vector<string> ret;
      if (n <= 0) {
        return ret;
      }
      vector<string> dp[2][n + 1][n + 1];
      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
          for (int k = 0; k <= n; ++k) {
            vector<string> temp;
            dp[i][j][k] = temp;
          }
        }
      }
      for (int k = 0; k <= n; ++k) {
        for (int j = 0; j < n; ++j) {
          for (int i = 0; i < 2; ++i) {
            if (j == 0 && k == 0) {
              string str = ""; 
              vector<string> temp(1, str);
              dp[i][j][k] = temp;
              continue;
            }
            vector<string> lefts;
            if (j > 0) {
              lefts = dp[i][j - 1][k];
              for (int x = 0; x < lefts.size(); ++x) {
                lefts[x].insert(lefts[x].begin(), '(');
              }
            }
            dp[i][j][k].insert(dp[i][j][k].end(), lefts.begin(), lefts.end());

            vector<string> rights;
            if (k > 0 && j < k) {
              rights = dp[i][j][k - 1];
              for (int x = 0; x < rights.size(); ++x) {
                rights[x].insert(rights[x].begin(), ')');
              }
            }
            dp[i][j][k].insert(dp[i][j][k].end(), rights.begin(), rights.end());
          }
        }
      }
      ret = dp[0][n - 1][n];
      for (int x = 0; x < ret.size(); ++x) {
        ret[x].insert(ret[x].begin(), '(');
      }
      return ret;
    }
};

int main() {
  Solution sln;
  for (int i = 0; i <= 3; ++i) {
    vector<string> ret = sln.generateParenthesis(i);
    // for (int j = 0; j < ret.size(); ++j) {
    //   std::cout << ret[j] << std::endl;
    // }
    std::cout << "=============" << std::endl;
    vector<string> retDp = sln.generateParenthesisDp(i);
    for (int j = 0; j < ret.size(); ++j) {
      std::cout << retDp[j] << std::endl;
    }
    std::cout << "------------" << std::endl;
  }

  return 0;
}
