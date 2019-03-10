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
    bool isSameTree(TreeNode* p, TreeNode* q) {
      if ((p == NULL && q != NULL) || (p != NULL && q == NULL)) {
        return false;
      }
      if (p == NULL && q == NULL) {
        return true;
      }
      queue<TreeNode *> queue1, queue2;
      queue1.push(p);
      queue2.push(q);
      while (!queue1.empty() && !queue2.empty()) {
        TreeNode *p1 = queue1.front();
        queue1.pop();
        TreeNode *p2 = queue2.front();
        queue2.pop();
        if (p1->val != p2->val) {
          return false;
        }
        if (p1->left != NULL && p2->left != NULL) {
          queue1.push(p1->left);
          queue2.push(p2->left);
        } else if (p1->left != NULL || p2->left != NULL) {
          return false;
        }
        if (p1->right != NULL && p2->right != NULL) {
          queue1.push(p1->right);
          queue2.push(p2->right);
        } else if (p1->right != NULL || p2->right != NULL) {
          return false;
        }
      }
      if (!queue1.empty() || !queue2.empty()) {
        return false;
      }
      return true;
    }
};

int main(void) {
  Solution sln;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);
  std::cout << sln.isSameTree(root, root) << std::endl;

  return 0;
}
