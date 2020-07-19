#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result;
    helper(root, result);
    return result;
  }

  void helper(TreeNode *root, vector<int> &result) {
    if (root == NULL) {
      return;
    }
    helper(root->left, result);
    helper(root->right, result);
    result.push_back(root->val);
  }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);
  vector<int> ret;
  ret = sln.postorderTraversal(root);
  for (int item : ret) {
    cout << item << endl;
  }

  return 0;
}
