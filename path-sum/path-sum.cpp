#include<iostream>

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
    bool hasPathSum(TreeNode* root, int sum) {
      if (root == NULL) {
        return false;
      }
      if (root->left && hasPathSum(root->left, sum - root->val)) {
        return true;
      }
      if (root->right && hasPathSum(root->right, sum - root->val)) {
        return true;
      }
      if (root->left == NULL && root->right == NULL && root->val == sum) {
        return true;
      }
      return false;
    }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->left->left = new TreeNode(11);
  root->left->left->left = new TreeNode(7);
  root->left->left->right = new TreeNode(2);
  std::cout << sln.hasPathSum(root, 27) << std::endl;

  return 0;
}
