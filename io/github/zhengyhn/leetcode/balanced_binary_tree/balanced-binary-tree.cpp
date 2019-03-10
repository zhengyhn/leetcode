#include <iostream>
#include <cmath>

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
  bool isBalanced(TreeNode* root) {
    if (root == NULL) {
      return true;
    }
    int left = getDepth(root->left);
    int right = getDepth(root->right);

    if (left == -1 || right == -1 || abs(left - right) > 1) {
      return false;
    }
    return true;
  }

  int getDepth(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }
    int left = getDepth(root->left);
    int right = getDepth(root->right);

    if (left == -1 || right == -1 || abs(left - right) > 1) {
      return -1;
    }
    return (left > right ? left : right) + 1;
  }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  std::cout << sln.isBalanced(root) << std::endl;

  return 0;
}
