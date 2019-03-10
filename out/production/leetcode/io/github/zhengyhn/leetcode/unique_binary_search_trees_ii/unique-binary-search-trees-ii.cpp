#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  vector<TreeNode *> generateTreesDp(int n) {
    if (n <= 0) {
      return {};
    }
    vector<TreeNode *> dp[n + 1][n + 1];
    for (int i = n; i > 0; --i) {
      for (int j = i; j <= n; ++j) {
        vector<TreeNode *> ret;
        if (i > j) {
          dp[i][j] = {NULL};
          continue;
        }
        for (int k = i; k <= j; ++k) {
          vector<TreeNode *> lefts = dp[i][k - 1];
          vector<TreeNode *> rights = dp[k + 1][j];
          for (TreeNode *left : lefts) {
            for (TreeNode *right : rights) {
              TreeNode *temp = new TreeNode(k);
              temp->left = left;
              temp->right = right;
              ret.push_back(temp);
            }
          }
        }
        dp[i][j] = ret;
      }
    }
    return dp[1][n];
  }

  vector<TreeNode *> generateTrees(int n) {
    if (n <= 0) {
      return {};
    }
    return helper(1, n);
  }

  vector<TreeNode *> helper(int start, int end) {
    vector<TreeNode *> ret;
    if (start > end) {
      ret.push_back(NULL);
      return ret;
    }
    for (int i = start; i <= end; ++i) {
      vector<TreeNode *> lefts = helper(start, i - 1);
      vector<TreeNode *> rights = helper(i + 1, end);
      for (TreeNode *left : lefts) {
        for (TreeNode *right : rights) {
          TreeNode *temp = new TreeNode(i);
          temp->left = left;
          temp->right = right;
          ret.push_back(temp);
        }
      }
    }
    return ret;
  }
};

int main() {
  Solution sln;

  return 0;
}