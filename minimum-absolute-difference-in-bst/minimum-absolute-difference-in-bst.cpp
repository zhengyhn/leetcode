#include <iostream>
#include <stack>

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
    int getMinimumDifference(TreeNode* root) {
      stack<TreeNode *> stack;
      int last = -0xffff;
      int cur = 0;
      int min = 0xffff;

      TreeNode *theRoot = root;
      stack.push(theRoot);
      while (!stack.empty()) {
        TreeNode *p = stack.top();
        stack.pop();
        if (p != NULL) {
          stack.push(p);
          stack.push(p->left);
        } else if (!stack.empty()) {
          theRoot = stack.top();
          cur = theRoot->val;
          // std::cout << cur << " " << last << std::endl;
          if (cur - last < min) {
            min = cur - last;
          }
          last = cur;
          stack.pop();
          stack.push(theRoot->right);
        }
      }
      return min;
    }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->left->right = new TreeNode(2);
  root->right = new TreeNode(4);
  std::cout << sln.getMinimumDifference(root) << std::endl;

  return 0;
}
