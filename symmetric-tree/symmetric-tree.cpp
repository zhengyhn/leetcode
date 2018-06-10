#include <iostream>
#include <queue>

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
    bool isSymmetric(TreeNode* root) {
      if (root == NULL) {
        return true;
      }
      queue<TreeNode *> leftQueue;
      queue<TreeNode *> rightQueue;
      leftQueue.push(root->left);
      rightQueue.push(root->right);
      while (!leftQueue.empty() && !rightQueue.empty()) {
        TreeNode *left = leftQueue.front();
        leftQueue.pop();
        TreeNode *right = rightQueue.front();
        rightQueue.pop();
        if (left == NULL && right == NULL) {
          continue;
        } else if (left != NULL && right != NULL && left->val == right->val) {
          leftQueue.push(left->right);
          leftQueue.push(left->left);
          rightQueue.push(right->left);
          rightQueue.push(right->right);
        } else {
          return false;
        }
      }
      // if (!leftQueue.empty() || !rightQueue.empty()) {
      //   return false;
      // }
      return true;
    }
};

int main(void) {
  Solution sln;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);
  std::cout << sln.isSymmetric(root) << std::endl;

  return 0;
}
